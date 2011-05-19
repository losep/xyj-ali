// Jiz
#include <ansi.h>

inherit F_SSERVER;

int cast(object me, object target)
{
    int success_adj, damage_adj;

    success_adj = 180;
    damage_adj = 170;

    if (!target) target = offensive_target(me);

    if (me->query("family/family_name")!="���ƶ�")
        return notify_fail("����ζ���ֻ�л��ƶ����˲ſ����ã�\n");
    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭����ζ���\n");

    if ((int)me->query_skill("pingtian-dafa", 1) < 30)
        return notify_fail("���ƽ��󷨻�򲻹���������ó����\n");

    if ((int)me->query("mana") < 25+(int)me->query("mana_factor"))
        return notify_fail("��ķ��������������������û��ʲô�ã�\n");

    if ((int)me->query("force") < 100)
        return notify_fail("��������������޷�����������\n");

    if ((int)me->query("sen") < 10)
        return notify_fail("���������ǲ��壬����Լ������ˣ�\n");

    me->add("mana", -25-2*(int)me->query("mana_factor"));
    me->receive_damage("sen", 50);

    if (random(me->query("max_mana")) < 50) {
        message_vision(HIM"$N���������дʡ�������ʲôҲû�з�����\n"NOR,me);
        return 1;
    }
    
    me->receive_wound("kee", 10);

    msg = HIC "$N�����ڱ���������������ʱ��Ѫֱð��ͻȻ��Ȼ��������������һ����$n��ȥ��\n" NOR;

    message_vision(msg, me, target);

    ap = (int)me->query_skill("spells");
    ap = ap * ap / 1000 * ap;
    ap = ap * (1 + (int)me->query("combat_exp")/5000000);
    ap = ap + (int)me->query("combat_exp");
    ap = ap/100*180;

    dp = (int)target->query("combat_exp");

    if (random(ap+dp) < dp) {
        msg = HIC"\n�����$n�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);
    }
    else {
        a_damage = me->query("mana")/40;
        d_damage = target->query("mana")/40;
        a_damage += random(me->query("eff_sen")/20);
        d_damage += random(target->query("eff_sen")/20);
        a_damage += me->query("mana_factor")*170/100;
        d_damage += random(target->query("mana_factor")*170/100);
        
        if (a_damage > d_damage) {
            damage = a_damage - d_damage;
            damage += me->query("mana_factor")*170/100;
            damage = damage*170/100;
            damage_bonus = (int)me->query_skill("spells")/200;
            if (damage_bonus > 3) damage_bonus = 3;
            damage += damage*damage_bonus;
            if (damage > 3000) damage = 3000;
            
            msg = HIC "���$n���յý�ͷ�ö\n" NOR;
            message_vision(msg, me, target);
            target->receive_damage("kee", damage*3/5, me);
            target->receive_wound("kee", damage/2, me);
            COMBAT_D->report_status(target);
        } else if (a_damage < d_damage) {
            msg = HIC "������汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR;
            message_vision(msg, me, target);
            
            damage = d_damage;
            if (damage > 400) damage = 400;
            damage -= target->query("mana_factor");
            damage = damage*170/100;
            damage_bonus = (int)me->query_skill("spells")/200;
            if (damage_bonus < 1) damage_bonus = 1;
            if (damage_bonus > 10) damage_bonus = 10;
            damage += damage/damage_bonus;
            
            msg = HIR "\n���$n��ܲ��������յý�ͷ�ö\n" NOR;
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

