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
    object ob = this_object();
    object where = environment();

    if (userp(where)) {
        if (!ob->query("owner"))
            ob->set("owner", where);
        else if (ob->query("owner") != where)
            call_out("destruct_me", 5, ob);
    }
    add_action("quest_give", "give");
}

void destruct_me(object ob)
{
    if (ob) {
        tell_object(environment(ob), "����������������һ�ء�\n");
        destruct(ob);
    }
}

int quest_give(string arg)
{
    string name;
    object me = this_player(), who, helper;

    if (me != query("owner"))
        return 0;

    if (!(helper = me->query_temp("dntg_helper")))
        return 0;

    if (sscanf(arg, "bing qi to %s", name) != 1
    &&  sscanf(arg, "%s bing qi", name) != 1)
        return 0;

    if (!(who = present(name, environment(me)))
    ||  !living(who)
    ||  !who->is_character()
    ||  who->is_corpse())
        return 0;

    if (who->query("id") != "beng jiangjun") return 0;

    if (me->query("dntg/huaguo") != "done") {
        message_vision(CYN "$N" CYN "˵��������˭����\n" NOR, who);
        return 1;
    } else if (me->query("dntg/donghai")) {
        message_vision(CYN "$N" CYN "˵���������Ѿ������ˣ����ʹ��������ˡ�\n" NOR, who);
        return 1;
    } else if (random(10) != 1) {
        message_vision(CYN "$N" CYN "�˷ܵĽе���̫���ˣ�Ҫ���ٶ�һ����͸����ˡ�\n" NOR, who);
        destruct(this_object());
        return 1;
    } else {
        message_vision(CYN "$N" CYN "���˵�����������\n" NOR, who);
        message_vision(CYN "$N" CYN "˵����̫���ˣ����������ǵı����ǹ����ˣ����Լ�Ҳ��һ�����ֵļһ�ɣ�\n" NOR, who);
        me->set("dntg/donghai", "begin");
        helper->report_progress(10);
        destruct(this_object());
        return 1;
    }
}

