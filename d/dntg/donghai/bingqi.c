// bingqi.c

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("����",({"bing qi"}));
    set_weight(20000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long","һ��������������ǹ������ꪡ������ᡢ������\n"
"ʲô���У����涼���м������֣����������ƣ���\n");
        set("unit","��");
    }
}

void init()
{
    object where, owner;

    if (userp(where = environment())) {
        if (!(owner = query("owner")))
            set("owner", where);
        if (query("owner") != where)
            call_out("destruct_me", 5);
    }
    
    add_action("do_dist", "distribute");
    add_action("do_dist", "distrib");
    add_action("do_dist", "fenfa");
}

void destruct_me()
{
    tell_object(environment(), "����������������һ�ء�\n");
    destruct(this_object());
}

int do_dist(string arg)
{
    object me, helper, where, who;

    me = this_player();
    if (me != query("owner"))
        return 0;

    helper = me->query_temp("dntg_helper");
    if (!helper)
        return 0;

    where = environment(me);
    if (!where)
        return 0;

    who = present("beng jiangjun", where);
    if (!who) {
        if (where != helper->get_playg_room())
            return 0;
        where->reset();
        who = present("beng jiangjun", where);
    }
    if (!who || !living(who))
        return 0;

    if (!arg || !id(arg))
        return notify_fail("��Ҫ�ַ�ʲô��\n");

    message_vision("$N�ó�һ���������е����������ǣ�����ȡ������������\n\n", me);
    if (me->query("dntg/huaguo") != "done") {
        message_vision("$N�ɻ�Ŀ���$n���������Ǻ�����Ҳ��Ϊ���ڴ�������\n", who, me);
        return 1;
    } else if (me->query("dntg/donghai")) {
        message_vision("$N�ܹ���˵�������Ѿ������ˣ����ʹ��������ˡ�\n", who);
        return 1;
    } else if (random(10) != 1) {
        message_vision("Ⱥ���˸߲��ҵ�Χ£�����������Ҽ񣬴ӱ��������������һ��������\n", who);
        message_vision("��һ�ᣬһ����������ʰһ�ա���Щ�������ģ�û�������ֱ���������ץ���������ϴ�������\n", who);
        destruct(this_object());
        return 1;
    } else {
        message_vision("Ⱥ���˸߲��ҵ�Χ£�����������Ҽ񣬴ӱ���������Գ���һ��������\n", who);
        message_vision("$N��һ�Խе���̫���ˣ����������ǵı����ǹ����ˣ����Լ�Ҳ��һ�����ֵļһ�ɣ�\n", who);
        me->set("dntg/donghai", "begin");
        helper->report_progress(10);
        destruct(this_object());
        return 1;
    }
}
