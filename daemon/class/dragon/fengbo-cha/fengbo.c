#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    string msg;
    object weapon, weapon2;
    int skill, ap, dp, damage;

    if (!target) target = offensive_target(me);

    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
    return notify_fail("��Ҫ��˭ʩչ��һ�С��޾��粨��?\n");

    if (!(me->is_fighting()))
        return notify_fail(HIW"���޾��粨��"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    ||  (string)weapon->query("skill_type") != "fork")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    skill = me->query_skill("fengbo-cha",1);
    if (skill < 100)
        return notify_fail("��ķ粨ʮ����ȼ�����, ����ʹ�á��޾��粨����\n");

    if (me->query("force") < 1000)
        return notify_fail("��������������޷����á��޾��粨����\n");

    msg = HIC "$N�����Ϣ,������"+weapon->name()+HIC"���˼�Ȧ,�͵���$n�ı��о�ȥ��\n";
    message_vision(msg, me, target);

    damage = 10 + random(skill / 2);

    ap = me->query_skill("fork") +4*skill ;
    dp = target->query_skill("force") + 4;

    if (dp < 1)
        dp = 1;                        

    if (random(ap) > random(dp)) {
        // if(userp(me))
        me->add("force",-50);
        if (objectp(weapon2 = target->query_temp("weapon"))) {
            msg = "$n��ʱ�����ֱ�һ�飬����"+weapon2->name()+"���ֶ�����\n" NOR;
            message_vision(msg, me, target);
            weapon2->move(environment(me));
            return 1;
        }
        target->receive_damage("kee", damage);
        target->start_busy(4+random(skill)/20);
        msg = "˭֪$n���и�����û��������$N��ʱ�����ٳ���\n";
        message_vision(msg, me, target);
        me->start_busy(1);
        return 1;
    }
    else {
        me->add("force",-30);
        if (objectp(weapon2 = target->query_temp("weapon"))){
            msg = "����$n������$N����ͼ�����̽�����" + weapon2->name()
                + "��÷��겻͸��ʹ$N�ġ��޾��粨��û�������á�\n"NOR;
            message_vision(msg, me, target);
            me->start_busy(2);
            return 1;
        }
        msg = "˭֪$n���и�����û��������$N��ʱ�����ٳ���\n";
        message_vision(msg, me, target);
        me->start_busy(2);
        return 1;
    }

    return 1;
} 

