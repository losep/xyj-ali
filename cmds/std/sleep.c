// sleep.c

#include <ansi.h>

int main(object me, string arg)
{
    object obj, old_target;
    int i;
    object *inv;   
    object where = environment(me);

    //mon 12/18/97, allow forced sleep by "keshui chong".
    if (!where->query("sleep_room") && !me->query_temp("force_sleep"))
        return notify_fail("���ﲻ��˯���ĵط���\n");
    if (me->is_busy())
        return notify_fail("����æ���أ�\n");
    if (me->is_fighting())
        return notify_fail("ս���в���˯����\n");   
    if ((time() - me->query("last_sleep")) < 90)
        return notify_fail("���˯��һ��, �Ȼ��ɡ�\n");

    if (where->query("if_bed")) {
        write("��������һ�꣬��ʼ˯����\n");
        write("��һ�������ͽ��������硣\n");
        me->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        message_vision(HIY "$N������һ�꣬��һ����������������������硣\n" NOR,me);
    }
    else { 
        write("��͵�һ�ɣ���ʼ˯����\n");
        write("��һ�������ͽ��������硣\n");
        me->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        message_vision(HIY "$N�͵�һ�ɣ���һ����������������������硣\n" NOR,me);
    }

    if (me->query_temp("ridee"))
        me->query_temp("ridee")->set_temp("rider", 0);
    me->set_temp("ridee",0);
    me->add_temp("apply/dodge", -me->query_temp("ride/dodge"));
    me->set_temp("ride/dodge", 0);
    me->disable_player("<˯����>");

    call_out("wakeup", random(45 - me->query("con")) + 10, me, where);
    return 1;
}

void wakeup(object me,object where)
{
    if (!me) return;

    me->set("sen", (int)me->query("max_sen"));
    if ((int)me->query("mana") < (int)me->query("max_mana"))
        me->set("mana", (int)me->query("max_mana"));

    me->enable_player();

    while (environment(me)->is_character())
        me->move(environment(environment(me)));

    if (random(5) == 1 && interactive(me)){
        me->set("dream_place", (string)environment(me));
        me->set_temp("block_msg/all", 0);
        me->move("/d/ourhome/honglou/kat");
    }
    else{
        message_vision(HIY "$Nһ����������������ػ��һ�½�ǡ�\n" NOR,me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");
    }
}

int help(object me)
{
    write(@HELP
ָ���ʽ : sleep
 
����˼�壬���ָ��������˯���ġ�
HELP
    );
    return 1;
}
