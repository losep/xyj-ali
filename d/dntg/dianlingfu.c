// ALi by NewX

inherit ITEM;

void create()
{
    set_name("�����", ({"dian ling fu","fu"}));
    set("unit", "��");
    set_weight(10);
    set("long", "һ�ŵ�ĸ���ĵ��������Ҫ����ʱ���������Կ���(ji)����\n");
    set("no_give", "�����������������ˣ�\n");
    set("no_sell", "�ƹ��ҡҡͷ˵���ⱦ��С�겻���ա�\n");
    setup();
}

void init()
{
    add_action("do_ji", "ji");
}

int do_ji(string arg)
{
    object me = this_player();
    object env;
    
    if (!arg || !id(arg)) return notify_fail("�����ʲô��\n");

    if (me->query("mana") + random(500) < 1000) {
        message_vision("$N�ó�����������һ���������磡��\n", me);
        message_vision("��ʲôҲû�з�������\n", me);
    } else {
        message_vision("$N�ó�����������һ���������磡��\n", me);
        message_vision("��ʱ��������ҫ�۶�꣡\n", me);
        message_vision("�ۣ����������磡\n", me);
        env = environment(me);
        env->weather_effect("light");
        foreach (object ob in all_inventory(env)) {
            if (ob) ob->weather_effect("light");
        }
    }
    destruct(this_object());
    return 1;
}
