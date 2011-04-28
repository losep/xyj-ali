
//�����촸��

/*
���촸  dodge  7    parry  -7    damage  27
*/

inherit SKILL;

string name() { return "���촸"; }

mapping *action = ({
    ([      "action":           "$N�Ĺ����߶�ʮһ������$w����$n��ͷ����һ�һ�",
        "dodge":        15,
        "parry":        -10,
        "damage":       35,
        "damage_type":  "����",
    ]),
    ([      "action":           "ֻ��$N��ð�׹⣬���͹�𣬳���$w�ͳ�$n��$l����ɨ�˹�ȥ",
        "dodge":        10,
        "parry":        -15,
        "damage":       25,
        "damage_type":  "����",
    ]),
    ([      "action":           "ֻ���䣡��һ��$N��$w�ڵ����ҵó������������$N���Ʒ��˸���ͷ������һ����$n���˹�ȥ",
        "dodge":        5,
        "parry":        -10,
        "damage":       35,
        "damage_type":  "����",
    ]),
    ([      "action":           "ֻ��$N��һ���������е�$w��������ɨ��Ȧ���Ƶ�$n���˲���",
        "dodge":        5,
        "parry":        0,
        "damage":       20,
        "damage_type":  "����",
    ]),
    ([      "action":           "$N���һ�������е�$w�������ᣬ�����転����$n$l������ȥ",
        "dodge":        5,
        "parry":        0,
        "damage":       20,
        "damage_type":  "����",
    ]),
    ([      "action":           "����$Nһ��ת������$w���¶���һ����$nֻ��һ���������������\n$n���ڰ��н���֮ʱ��$N��$w����һת�������˻���",
        "dodge":        5,
        "parry":        -10,
        "damage":       25,
        "damage_type":  "����",
    ]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_force") < 50)
        return notify_fail("�������������û�а취�����촸��\n");

    if (!(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "hammer")
        return notify_fail("���������һ���󴸲��������촸��\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("kee") < 50
    ||  (int)me->query("force") < 50)
        return notify_fail("�����������������û�а취��ϰ���촸��\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ����촸��\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

