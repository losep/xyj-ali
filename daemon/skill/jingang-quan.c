// ALi by NewX
 
// jingang-quan.c, ��ħŮ���ȭ��

// ��а֮ȭ Թ��֮ȭ ����֮ȭ ����֮ȭ

inherit SKILL;

string name() { return "ħŮ���ȭ"; }

mapping *action = ({
    ([
     "name":     "����а֮ȭ��",
     "action":
"$nֻ����$N������ɢ����һ��ǿ��������Ϣ������΢΢��㱡�\n"
"˭֪���ڴ�ʱ��$N�����ʯ���쾪��һȭ��\n"
"ԭ����$N��Ȼ���������ڵ������������ƶ��������ӳ������𺳵�һȭ",
     "force":     50,
     "dodge":     -10,
     "parry":     -10,
     "damage_type":   "����",
     ]),
    ([
     "name":     "��Թ��֮ȭ��",
     "action":
"$n��Ȼ�е������¶���Ȼ�½�����ˮ���Թ�������Ȼӿ����$p����ʶ��\n"
"����$n������֮�ʣ�$N��ȭͷ��һ������ĽǶȺ�����$n��$l",
     "force":     100,
     "dodge":     10,
     "parry":     -10,
     "damage_type":   "����",
     ]),
    ([
     "name":     "������֮ȭ��",
     "action":
"�޴�ľ����к�ȻϮ����$n����ͷ����Ҫ��������ͷͻȻ��$p���������֡�\n"
"������ʱ��$N��ȭͷ���ˣ����Ǳ������������������һȭ",
     "force":     70,
     "dodge":     10,
     "parry":     10,
     "damage_type":   "����",
     ]),
    ([
     "name":     "������֮ȭ��",
     "action":
"һ���ƺ���ֹͣ��������һƬ��ɪ��ɱ֮�������������ռ䡣\n"
"�����޾��Ļ���\n"
"$N��ȭͷ��Я�����޾��Ļ�����Ϣ��������Ϯ����$n��$l",
     "force":     70,
     "dodge":     -10,
     "parry":     10,
     "damage_type":   "����",
     ]),
});

int valid_learn(object me)
{
    if (me->query("gender") != "Ů��")
        return notify_fail("ħŮ���ȭ��Ů��ר�á�\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ħŮ���ȭ������֡�\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("sen") < 40)
        return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
    if ((int)me->query("kee") < 40)
        return notify_fail("����������������Ϣһ�������ɡ�\n");
    if ((int)me->query("force") < 10)
        return notify_fail("������������ˡ�\n");

    me->receive_damage("kee", 30);
    me->add("force", -10);

    return 1;
}
