// feedback.c
// ������Ԫ

inherit F_SSERVER;

int conjure(object me, object target)
{
    int diff, zyneed;

    if (target && target != me)
        return notify_fail("��ֻ�ܲ����Լ�������Ԫ��\n");

    if ((int)me->query("atman") < 20)
        return notify_fail("�����Ԫ������\n");
    if ((int)me->query_skill("magic") < 10)
        return notify_fail("�㻹û���������ֱ�����ͨ��\n"); 
    diff = me->query("eff_gin") - me->query("gin");
    zyneed = diff * 50 / (int)me->query_skill("magic");
    if (zyneed < 1)
        return notify_fail("�����ھ�Ԫ���㣬û��Ҫ������Ԫ��\n");
    
    if (zyneed > me->query("atman")) zyneed = me->query("atman");
    diff = zyneed * (int)me->query_skill("magic") / 50;
    
    me->receive_heal("gin", diff);
    me->add("atman", -zyneed);

    message_vision("$N��������Լ���������Ĳ�������ɫ��ʱ��ú���������\n", me);

    if (me->is_fighting()) me->start_busy(1);

    return 1;
}
