
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    object weapon;
    int me_brief, target_brief;
    string msg;

    if (!target) target = offensive_target(me);
    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭ʩչ��һ�С�������졹��\n");
    weapon = me->query_temp("weapon");
    if (!me->is_fighting(target))
        return notify_fail("��������졹ֻ����ս����ʹ��!\n");
    if (me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
        return notify_fail("��������졹ֻ���޵׶����˲ſ����ã�\n");
    if ((int)me->query("max_force") < 1500)
        return notify_fail("�������������\n");
    if ((int)me->query("force") < 500)
        return notify_fail("����������㣡\n");
    if (!weapon || weapon->query("skill_type") != "sword")
        return notify_fail("�������ʹ�ñ���ʱ����ʹ�ã�\n");
    if ((int)me->query_skill("qixiu-sword", 1) < 120)
        return notify_fail("������޽��ȼ�������!!\n");


    msg = MAG"\n$N����һЦ�����е�"+weapon->name()+MAG"����һ�ӣ���ʱ��ɳ��ʯ������ֱ����ʣ���\n"NOR;
    message_vision(msg, me, target);
    me_brief = me->delete("env/brief_message");
    target_brief = target->delete("env/brief_message");
    me->set_temp("QXJ_perform", 6);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    me->delete_temp("QXJ_perform");
    if (me_brief) me->set("env/brief_message", me_brief);
    if (target_brief) target->set("env/brief_message", target_brief);

    me->add("force", -150);

    if (!target->is_fighting(me)) {
        if (living(target)) {
            if (userp(target)) target->fight_ob(me);
            //else target->kill_ob(me);
        }
    }

    me->start_busy(1+random(1));
    return 1;
}

