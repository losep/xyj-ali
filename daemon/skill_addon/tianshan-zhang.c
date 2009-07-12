// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// tianshan-zhang.c, based on dagou-bang.c

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
	"dodge": -3,
	"damage": 40,
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
	"dodge": -5,
	"damage": 45,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ɽѩ��������$n��$l",
	"dodge": -10,
	"damage": 60,
	"damage_type": "����"
]),
([	"action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
	"dodge": -5,
	"damage": 50,
	"damage_type": "����"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 80)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("���������������ɽ�ȷ���\n");
	me->receive_damage("kee", 25);
	return 1;
}

