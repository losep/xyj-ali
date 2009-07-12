// ALI by NewX

#include <ansi.h>

int valid_kill(object killer, object victim)
{
    int pk_k, pk_v;

    if (userp(victim) && killer->query_condition("no_pk_time")>240
            && userp(killer))
        return notify_fail("�����ɱ��̫�࣬��ʱ��Ȼ�����������أ��²�ȥ�֡�\n");

     return 1;
}

int valid_move(object me)
{
    mixed no_move;

    if (me->over_encumbranced())
        return notify_fail("��ĸ��ɹ��أ��������á�\n");

    if (me->is_busy())
        return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

    no_move = me->query_temp("no_move");
    if (no_move) {
        if (stringp(no_move))
            return notify_fail(no_move);
        else
            return notify_fail("�����ڲ����ƶ���\n");
    }

    return 1;
}

int block_tell(object me)
{
    int time, count, last_tell;

    // temporary block tell flooding.
    time = time();
    if ( me->query("channel/tell_block") &&
         (time-me->query("channel/tell_block")) < 0 ) {
        return notify_fail("��Ľ�̸ָ���ʱ�ر��ˡ�\n");
    }

    count = me->query("channel/tell_count");
    count++;
    last_tell=me->query("channel/last_tell");
    if (count > 3) {
        count = 0;
        me->set("channel/last_tell", time);
        if (time == last_tell) {
            me->set("channel/tell_block", time + 180);
            return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸ָ���ʱ�ر��ˡ�\n");
        }
    }
    me->set("channel/tell_count", count);
    return 1;
}
