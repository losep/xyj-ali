//ŤתǬ��

#include <ansi.h>

inherit F_SSERVER;

int cast(object me, object target)
{
    string msg;
    int ap, dp, dg, damage;

    if (!target) target = offensive_target(me);
    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭��ŤתǬ����\n");
    if (!me->query("cast_juanbi"))
        return notify_fail("��ŤתǬ�����ǰ���С���ľ��û�������״�˭Ҳ�ò��ˣ�\n");
    if (!target->is_fighting(me))
        return notify_fail("ֻ����ս���в���ʹ��ŤתǬ����\n");
    if ((int)me->query("kee") < 100)
        return notify_fail("���������㣬�ò���ŤתǬ����\n");
    if ((int)me->query("force") < 100)
        return notify_fail("����������������ʹ��ŤתǬ����\n");
    if ((int)me->query_skill("dengxian-dafa", 1) < 40)
        return notify_fail("��ĵ��ɴ󷨻��������졣\n");
    if ((int)me->query("mana") < 300)
        return notify_fail("��ķ��������Ա��������˵У�\n");

    if (me->query("cast_juanbi") > 0)
        msg = HIW"\n$N��$n������ŭ��һ����ת˲�仯��һֻ��������"
                +"���������ı�����$n��ȥ��\n" NOR;
    else // cast_juanbi == -1, it's baixiang-xiaow himself
        msg = HIW"\n$N��$n������ŭ��һ�����ֳ���ɫ�����ԭ�Σ�"
                +"���������ı�����$n��ȥ��\n" NOR;

    ap = (int)me->query_skill("spells");

    dp = target->query_skill("spells");
    dg = target->query_skill("dodge");
    if (dp!=0) dp=100*ap/dp/3+random(100*ap/dp)/2; else dp=100;
    if (dg!=0) dg=100*ap/dg/3+random(100*ap/dg)/2; else dg=100;

    damage = me->query("max_mana")/20+1;
    damage = (me->query("mana_factor")+me->query("str")+random(damage))*2;
    if (dp < 30) {
        msg += HIW"����$n����׼����Ťת��������Գ��һ��ץס��$N�ı��ӣ�\n"
                +"$N�۵�һ���ƺߣ����ɼ��ı�$n���˹�ȥ��\n"NOR;
        message_vision(msg, me, target);
        me->add("kee", me->query("str") * 2);
        me->start_busy(30-dp+random(10));
    } else if (dp<60 && dp>30) {
        msg += HIW"$n��æŤת������ת�񹦽�$N�ĳ��ǵ�����\n"NOR;
        message_vision(msg, me, target);
        me->start_busy(1+random(2));
    } else if (dg<50) {
        msg += HIW"$n�������һԾ����������һ����\n"NOR;
        message_vision(msg, me, target);
        me->start_busy(1+random(2));
        target->start_busy(random(3));
    } else {
        msg += HIW"$n�ٲ���������$N�ĳ��Ǹ߸߾���$N����һ˦��"
                +"$n������ߵķ��ݰ���˳�ȥ��\n"NOR;
        message_vision(msg, me, target);
        target->receive_damage("kee",damage,me);
        me->start_busy(random(2));
        target->start_busy(1+random(3));
        COMBAT_D->report_status(target); 
    }

    me->add("force", -30);
    me->add("mana", -30);

    target->kill_ob(me);
    return 1;
}

