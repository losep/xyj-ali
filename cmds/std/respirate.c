// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int finish(object me, int gin_cost);

int main(object me, string arg)
{
    int gin_cost, busy_time;

    seteuid(getuid());

    if (environment(me)->query("no_fight")
    ||  environment(me)->query("no_magic"))
        return notify_fail("��ȫ���ڽ�ֹ������\n");
    if (me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("����һ��������û����ɣ��������С�\n");
    if (me->is_fighting())
        return notify_fail("ս��Ҳ��һ�����У������ܺ���Ԫ�Ļ���ͬʱ���С�\n");
    if (!arg || !sscanf(arg, "%d", gin_cost))
        return notify_fail("��Ҫת�����پ�Ԫ��\n");
    if (gin_cost < 10) return notify_fail("������Ҫ�� 10 �㡸�����������ɡ�\n");
    if ((int)me->query("gin") < gin_cost)
        return notify_fail("��ľ�Ԫ���㣬���ǿ��ת����Ԫ����һ���غ��ģ�\n");
    if ((int)me->query("kee") * 100 / (int)me->query("max_kee") < 70)
        return notify_fail("����������״��̫���ˣ��޷����о���\n");
    if ((int)me->query("sen") * 100 / (int)me->query("max_sen") < 70)
        return notify_fail("�����ھ���״��̫���ˣ��޷������Լ������飡\n");

    write("������۾���ƽ�ľ�������ͼ�����ڵľ�Ԫת��Ϊ��Ԫ��\n");
    me->receive_damage("gin", gin_cost);

    busy_time = random(1 + gin_cost / 20) + 3;
    me->start_busy(busy_time);

    call_out("finish", busy_time+1, me, gin_cost);
    return 1;
}

int finish(object me, int gin_cost)
{
    int atman_gain;

    // This function ranged from 1 to 15 when gin_cost = 30
    atman_gain = gin_cost * ((int)me->query_skill("magic") / 10
        + (int)me->query_spi()/2 + (int)me->query_con()/2) / 30;
    atman_gain = atman_gain + random(atman_gain);

    if (atman_gain < 1) {
        tell_object(me, "������һ��С�ľ�Ȼ˯���ˡ�\n");
        me->start_busy(1);
        return 1;
    }

    me->add("atman", atman_gain);
    tell_object(me, "��������ϣ������ۣ�����վ��������\n");

    if ((int)me->query("atman") > (int)me->query("max_atman") * 2) {
        if ((int)me->query("max_atman") >= (int)me->query_skill("magic") * 10) {
            tell_object(me, "���Ȼ����һ�����ƶ��ģ��·�Ҫ�³���һ�����ƺ���Ԫ�Ļ����Ѿ�������ƿ����\n");
        } else {
            tell_object(me, "�����Ԫ����ˣ�\n");
            me->add("max_atman", 1);
        }
        me->set("atman", me->query("max_atman"));
    }

    me->start_busy(1);
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : respirate|tuna [<�ķѡ�����������Ԥ��ֵ 30>]

�������У����á������������������������项�ķ�������ľ�Ԫ
ת�����Ԫ��

��ο� help stats
HELP
    );
    return 1;
}
