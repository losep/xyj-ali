// three.c
#include <ansi.h>

inherit F_SSERVER;

int restore_env(object me, object target, int i, int j);

int perform(object me, object target)
{
    int i, j;

    if (!target) target = offensive_target(me);
    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭ʩչ��һ�С����ˡ�����\n");
    if (!me->is_fighting())
        return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");
    if ((int)me->query("force") < 1000)
        return notify_fail("�������������\n");
    if ((int)me->query("kee") < 300)
        return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
    if ((int)me->query_skill("killer-sword", 1) < 50)
        return notify_fail("���׷�꽣���𻹲�����ʹ����һ�л������ѣ�\n");
    if ((int)me->query_skill("keening-stick", 1) < 50)
        return notify_fail("��Ŀ�ɥ�����𻹲�����ʹ����һ�л������ѣ�\n");
    if ((int)me->query_skill("hellfire-whip", 1) < 50)
        return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

    i = me->query("env/brief_message");
    j = target->query("env/brief_message");
    me->delete("env/brief_message");
    target->delete("env/brief_message");

    message_vision("\n$N˫�ֻ�һ��Բ����Ȼ������٣������������������������ˡ����ˡ������С�\n", me);

    if (!present(target, environment(me))) return restore_env(me, target, i, j);
    me->set("HellZhen", 7);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    if (!present(target, environment(me))) return restore_env(me, target, i, j);
    me->set("HellZhen", 6);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

    if (!present(target, environment(me))) return restore_env(me, target, i, j);
    me->set("HellZhen", 1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    restore_env(me, target, i, j);

    me->receive_damage("kee", 100);
    me->add("force", -100);

    if (!target->is_fighting(me)) {
        if (living(target)) {
            if (userp(target)) target->fight_ob(me);
            else target->kill_ob(me);
        }
    }

    me->start_busy(3);
    return 1;
}

int restore_env(object me, object target, int i, int j)
{
    if (i) me->set("env/brief_message", 1);
    if (j) target->set("env/brief_message", 1);
    me->delete("HellZhen");
    return 1;
}
