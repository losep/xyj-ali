// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me)
{
	int exp, pot, tpot;
	tpot = (int) me->query("potential");
	pot = (int) me->query("potential")- (int) me->query("learned_points");
	exp = (int) me->query("combat_exp");
	exp = exp+pot * 2;
	me->set("combat_exp",exp );
	me->set("potential", tpot - pot);	
	write("�ϣ�\n");
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : transfer
 
���ָ��������㽫Ǳ��תΪ���飨��������.
 
HELP
    );
    return 1;
}
