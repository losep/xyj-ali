// five-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����������ˮ������һ����һʽˮ�־��еġ��鵶��ˮ������������ıܿ���һ����\n",
        "$n������ת���Ų����У�һʽ���С�ľ�־�����ٿ�ش�ľ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ���������еġ����־�����$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ��ó������Ӱ���ӻ������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ�����С����־��������ݵ���$N�����\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query_skill("changelaw") < (int)(me->query_skill("five-steps") / 2) )
                return notify_fail("����׾����˽⻹��������޷�ѧϰ��������\n");
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 20;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 10;
}

