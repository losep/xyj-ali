// tuntian.c
#include <ansi.h>

inherit F_SSERVER;

int cast(object me, object target)
{
    string msg;
    int ap, dp, a_damage, d_damage, damage, damage_bonus;

    if (!target) target = offensive_target(me);
    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭ʩչħ�����죿\n");
    if (!me->query("cast_tuntian"))
        return notify_fail("��ħ�����졹����ʨ��ħ�ľ��û�������״�˭Ҳ�ò��ˣ�\n");
    if ((int)me->query("mana") < 100+2*(int)me->query("mana_factor"))
        return notify_fail("��ķ���������\n");
    if ((int)me->query("sen") < 100)
        return notify_fail("���޷����о�����\n");

    me->add("mana", -25 - 2*(int)me->query("mana_factor"));
    me->receive_damage("sen", 50);

    if (random(me->query("max_mana")) < 50) {
        write("���ˣ�����ʨ�Ӳ�֪����ȥ�ˣ�\n");
        return 1;
    }

    if (me->query("cast_tuntian") > 0)
        msg = HIC "\n$N�������˾����ģ��������һֻ���������ʨ�ӣ�"
                +"�ſ�Ѫ������$nҧȥ��\n" NOR;
    else // cast_tuntian == -1, it's qingshi-laomo himself
        msg = HIC "\n$N�������˾����ģ��ֳ���ɫʨ��ԭ�ͣ�"
                +"�ſ�Ѫ������$nҧȥ��\n" NOR;

    message_vision(msg, me, target);

    ap = (int)me->query_skill("spells");
    ap = ap * ap / 1000 * ap;
    ap = ap * (1 + (int)me->query("combat_exp")/5000000);
    ap = ap + (int)me->query("combat_exp");
    ap = ap/100*120;

    dp = (int)target->query("combat_exp");

    if (random(ap+dp) < dp) {
        msg = HIC "\n$n��æһ��������һ�ԡ�\n" NOR;
        message_vision(msg, me, target);
    }
    else {
        a_damage = me->query("mana")/40;
        d_damage = target->query("mana")/40;
        a_damage += random(me->query("eff_sen")/20);
        d_damage += random(target->query("eff_sen")/20);
        a_damage += me->query("mana_factor")*120/100;
        d_damage += random(target->query("mana_factor")*120/100);
        
        if (a_damage > d_damage) {
            damage = a_damage - d_damage;
            damage += me->query("mana_factor")*120/100;
            damage = damage*120/100;
            damage_bonus = (int)me->query_skill("spells")/200;
            if (damage_bonus > 3) damage_bonus = 3;
            damage += damage*damage_bonus;
            if (damage > 3000) damage = 3000;
            
            msg = HIR "\n���$n��ҧ�˸����ţ�\n" NOR;
            message_vision(msg, me, target);
            target->receive_damage("kee", damage*3/5, me);
            target->receive_wound("kee", damage/2, me);
            COMBAT_D->report_status(target);
        } else if (a_damage < d_damage) {
            msg = HIC "ֻ��$nһ��ŭ����ëʨ�ӱ���ñ治�巽�򣬷���ҧ����$N��\n" NOR;
            message_vision(msg, me, target);
            
            damage = d_damage;
            if (damage > 400) damage = 400;
            damage -= target->query("mana_factor");
            damage = damage*120/100;
            damage_bonus = (int)me->query_skill("spells")/200;
            if (damage_bonus < 1) damage_bonus = 1;
            if (damage_bonus > 10) damage_bonus = 10;
            damage += damage/damage_bonus;
            
            msg = HIR "\n���$N��ҧ�˸����ţ�\n" NOR;
            message_vision(msg, me, target);
            me->receive_damage("kee", damage*3/5, target);
            me->receive_wound("kee", damage/2, target);
            COMBAT_D->report_status(me);
        } else
            message_vision(HIB "������ñ�$N�Է�����ס��˭Ҳû�гԿ���\n" NOR, target);
    }

    me->start_busy(1+random(2));
    target->kill_ob(me);

    return 3+random(5);
}

