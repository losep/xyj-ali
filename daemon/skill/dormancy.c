// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }
#include <ansi.h>
void skill_improved(object me)
{
	int s;

	s = me->query_skill("dormancy", 1);
	if((int)me->query("tol") < s/5) {
		tell_object(me, HIW "��������ѧ�������������������ˡ�\n" NOR);
		me->add("tol", 1);
	}
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

