// iron-cloth.c

inherit SKILL;
#include <ansi.h>
void skill_improved(object me)
{
        int s;

        s = me->query_skill("incarnation", 1);
        if( (int)me->query("spi") < s/5) {
                tell_object(me, HIW "����������������������������ˡ�\n" NOR);
                me->add("spi", 1);
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

