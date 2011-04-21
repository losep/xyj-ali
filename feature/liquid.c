// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// liquid.c

#include <dbase.h>
#include <name.h>

void init()
{
    add_action("do_drink", "drink");
    add_action("do_fill", "fill");
}

string extra_long()
{
    int amount, max;
    string str;

    if (amount = query("liquid/remaining")) {
        max = query("max_liquid");
        if (amount == max)
            str = "����װ����" + query("liquid/name") + "��\n";
        else if (amount > max/2)
            str = "����װ���ߡ��˷�����" + query("liquid/name") + "��\n";
        else if (amount >= max/3)
            str = "����װ���塢��������" + query("liquid/name") + "��\n";
        else if (amount > max/2)
            str = "����װ�������" + query("liquid/name") + "��\n";
        return str;
    }
    else return 0;
}

int do_drink(string arg)
{
    string msg = query("drink_msg");
    if (!living(this_player()))
        return 1;
    if (!this_object()->id(arg)) return 0;
    if (this_player()->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
    if (!query("liquid/remaining"))
        return notify_fail(name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n" : "�ǿյġ�\n"));
    if ((int)this_player()->query("water") >= (int)this_player()->max_water_capacity())
        return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

    add("liquid/remaining", -1);
    if (msg)
        message_vision(msg, this_player(), this_object());
    else
        message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
            + "��\n", this_player());
    this_player()->add("water", 30);
    if (this_player()->is_fighting()) this_player()->start_busy(2);
    if (!query("liquid/remaining"))
        write("���Ѿ���" + name() + "���" + query("liquid/name")
            + "�ȵ�һ��Ҳ��ʣ�ˡ�\n");

    // This allows customization of drinking effect.
    if (query("liquid/drink_func")) return 1;

    switch (query("liquid/type")) {
        case "alcohol":
            this_player()->apply_condition("drunk",
                (int)this_player()->query_condition("drunk") 
                + (int)query("liquid/drunk_apply"));
            break;
        // added by snowcat jul 17 1997
        case "spring": {
            object me = this_player();
            int recover;
            if (me->query("max_gin")>me->query("eff_gin")) {
                recover = (me->query("max_gin")-me->query("eff_gin"))/10;
                if (recover == 0) recover = 1;
                me->add("eff_gin",recover);
                message_vision("������$N�ľ����ָ��˲��١�\n",me);
            }
            if (me->query("max_kee")>me->query("eff_kee")) {
                recover = (me->query("max_kee")-me->query("eff_kee"))/10;
                if (recover == 0) recover = 1;
                me->add("eff_kee",recover);
                message_vision("������$N�������ָ��˲��١�\n",me);
            }
            if (me->query("max_sen")>me->query("eff_sen")) {
                recover = (me->query("max_sen")-me->query("eff_sen"))/10;
                if (recover == 0) recover = 1;
                me->add("eff_sen",recover);
                message_vision("������$N�������ָ��˲��١�\n",me);
            }
            break;
        }
    }

    return 1;
}

int do_fill(string arg)
{
    string liquid_name;
    string liquid_type;
    mapping poison;
    function f;
    
    if (!living(this_player()))
        return 1;
    if (!this_object()->id(arg)) return 0;
    if (this_player()->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
    // the following spring is added by snowcat jul 17 1997
    if (!environment(this_player())->query("resource/water") &&
        !environment(this_player())->query("resource/spring") &&
        !mapp(environment(this_player())->query("resource/poison")))
        return notify_fail("����û�еط�����װˮ��\n");
    
    if (mapp(poison = environment(this_player())->query("resource/poison"))) {
        f = (: call_other, __FILE__, "drink_poison" :);
        liquid_name = poison["name"];
        liquid_type = "poison";
        set("liquid/poison_condition", poison["condition"]);
        set("liquid/poison_effect", poison["effect"]);
    }
    else if (environment(this_player())->query("resource/spring")) {
        liquid_name = "Ȫˮ";
        liquid_type = "spring";
    }
    else {
        liquid_name = "��ˮ";
        liquid_type = "water";
    }
    if (query("liquid/remaining"))
        message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������", this_player());
    message_vision("$N��" + name() + "װ��"+liquid_name+"��\n", this_player());

    if (this_player()->is_fighting()) this_player()->start_busy(2);

    set("liquid/type", liquid_type);
    set("liquid/name", liquid_name);
    set("liquid/remaining", query("max_liquid"));
    if (!functionp(f))
        set("liquid/drink_func", 0);
    else
        set("liquid/drink_func", bind(f, this_object()));

    return 1;
}

int drink_poison(object ob)
{
    this_player()->apply_condition(ob->query("liquid/poison_condition"),
        (int)this_player()->query_condition(ob->query("liquid/poison_condition"))
        + (int)ob->query("liquid/poison_effect"));
    return 0;
}
