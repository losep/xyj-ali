// flag.c

inherit ITEM;

void create()
{
    set_name("����", ({"flag","qi"}));
    set("unit", "��");
    set_weight(500);
    set("long", @LONG
        ***********************************************
        **      �ô����߿�Ϊ���鸣��ˮ����֮����     **
        ***********************************************
LONG);
}

void init()
{
    object who = environment();
    
    if (userp(who)) {
        if (query("owned")) {
            if (query("owned") != who->query("id"))
                call_out("destruct_me", 1, who, this_object());
        } else {
            set("owned", who->query("id"));
        }
    }
    add_action("do_wave", "wave");
}

void destruct_me(object who, object me)
{
    message_vision("һ����紵����$n����һ�Żҽ���\n", who, me);
    destruct(me);
}

int do_wave(string arg)
{
    object me = this_player();
    object hb;

    if (me->query("id") != query("owned") || me != environment()) return 0;
    if (!arg || !id(arg)) return notify_fail("�������ʲô��\n");

    if (!(hb = me->query_temp("dntg_helper"))) {
        destruct_me(me, this_object());
        return 1;
    }
    if (!hb->check_huaguo_waveroom())
        return notify_fail("�����ӣ�Ҫ������"+name()+"����Ӧ����Ƭ�����ء�\n");
    if (me->query("dntg/huaguo") == "done")
        return notify_fail("��������е�"+name()+"�������˵����ڴ˳����Ŀ���ʱ�⡣\n");
    message_vision("$N�����������ӣ����һ���������컯�����컯������ûˮ��ԭ����һ�������š����Ǳ���һ���������ļҵ����ֵ��ǿ�ȥѽ����\n", me);
    call_out("monkeys_jump", 2, environment(me));
    me->set("dntg/huaguo", "allow");
    load_object("/obj/empty");
    move("/obj/empty");
    return 1;
}

void monkeys_jump(object where)
{
    object who1 = present("hou zi 1", where);
    object who2 = present("hou zi 2", where);
    object who3 = present("hou zi 3", where);
    object who4 = present("hou zi 4", where);
    if (who1) destruct(who1);
    if (who2) destruct(who2);
    if (who3) destruct(who3);
    if (who4) destruct(who4);
    message("vision", "�������������ȿֺ�������ٲ���\n", where);
    destruct(this_object());
}
