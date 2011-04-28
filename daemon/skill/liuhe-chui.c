
//�����ϴ�����

/*
���ϴ���  dodge  7    parry  -7    damage  27
*/

inherit SKILL;

string name() { return "���ϴ���"; }

mapping *action = ({
    ([  "action":           "$N�Ĺ����߶�ʮһ�����ֳ���$w����$n��ͷ����һ�һ�",
        "dodge":        15,
        "parry":        -10,
        "damage":       35,
        "damage_type":  "����",
    ]),
    ([  "action":           "ֻ��$N��ð�׹⣬���͹�����־���$w�ͳ�$n��$l����ɨ�˹�ȥ",
        "dodge":        10,
        "parry":        -15,
        "damage":       25,
        "damage_type":  "����",
    ]),
    ([  "action":           "ֻ���䣡��һ��$N��$w�ڵ����ҵó������������$N�ַ��˸���ͷ�����������˱����$n",
        "dodge":        5,
        "parry":        -10,
        "damage":       35,
        "damage_type":  "����",
    ]),
    ([  "action":           "ֻ��$N��һ���������е�$wֱ��ֱȥ��ֱ��$nƽ�ƹ�ȥ",
        "dodge":        5,
        "parry":        0,
        "damage":       20,
        "damage_type":  "����",
    ]),
    ([  "action":           "$N���һ�������е�$w�������ᣬ�����転����$n$l������ȥ�������������̩ɽѹ����",
        "dodge":        5,
        "parry":        0,
        "damage":       20,
        "damage_type":  "����",
    ]),
    ([  "action":           "����$N�߸߾�����$w���͵���������$nֻ��һ���������������\n$n���ڰ��н���֮ʱ��$N��$wȴ����һת���ִ������϶��˻���",
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
        return notify_fail("�������������û�а취�����ϴ�����\n");

    if (!(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "hammer")
        return notify_fail("���������һ���󴸲��������ϴ�����\n");

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
        return notify_fail("�����������������û�а취��ϰ���ϴ�����\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ�����ϴ�����\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

