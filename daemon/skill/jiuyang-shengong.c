// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// jiuyang-shengong.c ������
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");

	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 20)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("������������������񹦡�\n");

	me->receive_damage("kee", 10);
	me->receive_damage("force", 10);
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
