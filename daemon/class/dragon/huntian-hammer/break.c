// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    object weapon;
    int i;

    if (!target) target = offensive_target(me);

    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭ʩչ��һ�С�����һ�ơ�?\n");

    if (!me->is_fighting())
        return notify_fail("������һ�ơ�ֻ����ս���в���ʹ��!\n");

    if ((int)me->query("max_force") < 1200)
        return notify_fail("�������������\n");
    if ((int)me->query("force") < 500)
        return notify_fail("����������㣡\n");
    if ((int)me->query_skill("huntian-hammer",1) < 80)
        return notify_fail("��Ļ��촸�ȼ���������ʩչ����һ��!!\n");
    if ((int)me->query_skill("dragonforce",1) < 80)
        return notify_fail("��������ķ�����������!!\n");

    i = me->query_skill("huntian-hammer",1)/3;
        
    me->delete("env/brief_message");
    target->delete("env/brief_message");

    me->set_temp("HTH_perform", 6);
    me->add_temp("apply/attack",i);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    me->add_temp("apply/attack",-i);
        
    me->delete_temp("HTH_perform");

    me->add("force", -200);

    if (!target->is_fighting(me)) {
        if (living(target)) {
            if (userp(target)) target->fight_ob(me);
            else target->kill_ob(me);
        }
    }

    me->start_busy(2+random(1));
    return 1;
}

