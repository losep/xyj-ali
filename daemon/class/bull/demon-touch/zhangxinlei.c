#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    object weapon;
    string msg,str;
    if (!target) target = offensive_target(me);

    if (!target
    ||  !target->is_character()
    ||  target->is_corpse()
    ||  target==me)
        return notify_fail("��Ҫ��˭ʩչ��һ�������ף�\n");

    if (!me->is_fighting())
        return notify_fail("������ֻ����ս����ʹ�ã�\n");

    if (me->query("family/family_name")!="���ƶ�")
       return notify_fail("�������ס�ֻ�л��ƶ����˲ſ����ã�\n");

    if (time()-(int)me->query_temp("xiao_end") < 5)
        return notify_fail("�����ö�Ͳ����ˣ�\n");

    if ((int)me->query("force") < 500)
        return notify_fail("�������������\n");

    if ((int)me->query("kee") < 300)
        return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

    if ((int)me->query_skill("demon-touch", 1) < 70)
        return notify_fail("���ħ���ּ��𻹲�����ʹ����һ�л������ѣ�\n");

    me->delete("env/brief_message");

    message_vision("\n$N���һ���������ס���\n", me);

    me->set_temp("moyunshou_per", 6);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    me->delete_temp("moyunshou_per");

    me->receive_damage("kee", 50);
    me->add("force", -100);
    me->set_temp("xiao_end",time());
    return 1;
}

