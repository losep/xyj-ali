// lovefire-whip.c
// �����

inherit SKILL;

string name() { return "�����"; }

mapping *action = ({
    ([
        "action" : "ֻ��$N�������룬�������ȼ����һ�Ż𣬣�һʽ�����������$w��$nϮ��",
        "dodge"  : -5,
        "damage" : 20,
        "parry"  : -10,
        "lvl"         : 0,
        "skill_name"  : "�������",
        "damage_type" : "����",
        "post_action" : (: call_other, WEAPON_D, "wave_weapon" :),
    ]),
    ([
        "action" : "$N��ɫͨ�죬�Ŀڷ·�ð����һ�Ż�ʹ���ˡ�������ġ���ǿ���������$n�������",
        "dodge"  : -10,
        "damage" : 30,
        "parry"  : 5,
        "lvl"         : 10,
        "skill_name"  : "�������",
        "damage_type" : "����",
    ]),
    ([
        "action" : "$Nһʽ������ٷ�����С��֮����Լ͸����һ�Ż�$w��$n�͵ش���",
        "dodge"  : -5,
        "damage" : 20,
        "parry"  : 5,
        "lvl"         : 20,
        "skill_name"  : "����ٷ�",
        "damage_type" : "����",
    ]),
    ([
        "action" : "$N����������������ƺ�������һ�������ŮӤ��Ӱ��һ�С������̥����$n��ȥ",
        "dodge"  : -10,
        "damage" : 30,
        "parry"  : -10,
        "lvl"         : 30,
        "skill_name"  : "�����̥",
        "damage_type" : "����",
    ]),
});

int valid_enable(string usage)
{
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
    if ((int)me->query_skill("foxforce",1) < 40)
        return notify_fail("�������ķ���Ϊ��ǳ��û��ѧ����ޣ�\n");
    return 1;
}

mapping query_action(object me, object weapon) 
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    ||  (string)(weapon->query("skill_type")) != "whip")
        return notify_fail("�������������û���ӣ���ô������ް��� :)\n");
    if ((int)(me->query("kee")) < 50)
        return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("kee", 30);
    return 1;
}

string perform_action_file(string action)
{
    return CLASS_D("fox") + "/lovefire-whip/" + action;
}

