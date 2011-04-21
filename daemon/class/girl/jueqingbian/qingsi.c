//��˿
//requirement: jueqingbian > 100, kee > 20%, sen > 50%

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    string msg;
    int ap, dp, bonus, my_exp, your_exp;
    int qi, max_qi, qi_pcg, shen, max_shen, shen_pcg;
    object whip, weapon;

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character()
            || target->is_corpse()
            || target == me)
        return notify_fail("��Ҫ��˭��\n");

    if (!whip = me->query_temp("weapon"))
        return notify_fail("��û�ñ��ӣ���ô��ȡ���˵ı�����\n");
    if (!weapon = target->query_temp("weapon"))
        return notify_fail("�Է�û�ñ���������ô��ȡ��\n");

    if ((int)me->query_skill("jueqingbian", 1) < 100)
        return notify_fail("��ľ���޻�򻹲�����\n");
    if (me->query_skill_mapped("force") != "moonforce")
        return notify_fail("����ޱ��������Ů�ľ�����ʹ�á�\n");
    if (me->query_skill("moonforce", 1) < 100)
        return notify_fail("�����Ů�ľ��������졣\n");
    if (!target->is_fighting(me))
        return notify_fail("����û���ڴ�ܣ�\n");

    qi = me->query("kee");
    max_qi = me->query("max_kee");
    qi_pcg = qi*100/max_qi;
    if (qi < 20 || qi_pcg < 50)
        return notify_fail("���������ã�������������㡣\n");

    shen = me->query("sen");
    max_shen = me->query("max_sen");
    shen_pcg = shen*100/max_shen;
    if (shen < 20 || shen_pcg < 50)
        return notify_fail("����־���壬������������㡣\n");

    if (me->query("force") < 200)
        return notify_fail("���������̣�������������㡣\n");

    me->add("force", -200);
    me->receive_damage("kee", 20);
    me->receive_damage("sen", 20);

    msg = HIC "$N��˫�ۺ�Ȼ��ÿն������е�" + whip->query("name")
        + HIC "������ʵ��ת�ۼ侹�Ѳ�����$n���е�" + weapon->query("name")
        + HIC "��\n" NOR;

    ap = me->query_skill("jueqingbian", 1) + me->query_str() * 10;
    dp = target->query_str() * 10;
    my_exp = me->query("combat_exp");
    your_exp = target->query("combat_exp");
    if (my_exp > your_exp)
    {
        bonus = 100 * my_exp / your_exp - 100;
    }
    else
    {
        bonus = 100 - 100 * my_exp / your_exp;
    }

    if (random(ap + dp + bonus) > dp)
    {
        weapon->unequip();
        msg += HIC "$n�󾪣���æ�����ضᣬ˭֪" + whip->query("name")
            + HIC "�Ͼ���������Ǳ����˿˿���ƻ�����$n��������\n" NOR;
        if ((int)me->query_encumbrance() + weapon->weight()
                < (int)me->query_max_encumbrance())
        {
            weapon->move(me);
            msg += HIC "$NͻȻ������" + whip->query("name")
                + HIC "һ����$n��Ҳ����ס���е�" + weapon->query("name")
                + HIC "����$NӲ���˹�ȥ��\n" NOR;
        }
        else
        {
            weapon->move(environment(me));
            msg += HIC "$NͻȻ������" + whip->query("name")
                + HIC "һ����$n��Ҳ����ס���е�" + weapon->query("name")
                + HIC "��ԶԶ�ķ��˳�ȥ��\n" NOR;
        }
    }
    else
    {
        msg += HIC "$n�������ţ�����" + weapon->query("name")
            + HIC "�����������ܿ�ͽ�����" + whip->query("name")
            + HIC "�Ĳ��������ˡ�\n" NOR;
    }

    me->start_busy(2+random(3));

    message_vision(msg, me, target);
    return 1;
}

