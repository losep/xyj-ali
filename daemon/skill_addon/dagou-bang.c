// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// dagou-bang.c

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
	"dodge": -10,
	"damage": 30,
	"damage_type": "����"
]),
([	"action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
	"dodge": -20,
	"damage": 40,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
	"dodge": -30,
	"damage": 50,
	"damage_type": "����"
]),
([	"action": "$Nʩ�����������졹��$w����������$n��ȥ",
	"dodge": -20,
	"damage": 40,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        if (!me) me = this_object();
	if (random(me->query_skill("staff")) > 60 &&
	    me->query_skill("force") > 60 &&
	    me->query("force") > 100 &&
	    (string)weapon->query("id") == "yuzhu zhang" ) {
		me->add("force", -100);
		return ([
		"action": "$N�������һ����â������������ʹ���������޹���������ǵذ㹥��$n",
		"damage": 500,
		"damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("��������������򹷰�����\n");
	me->receive_damage("kee", 40);
	return 1;
}

