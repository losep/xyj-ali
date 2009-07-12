// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	int lvl;
	if( target ) return notify_fail("��ʶ��ֻͨ�ܶ��Լ�ʹ�á�\n");
	if( me->query("atman") < 1000 )
		return notify_fail("�������������\n");
	lvl = (int) me->query_skill("essencemagic",1);
        if( me->query("gin") <= 50 )
                return notify_fail("��ľ�������\n");
	me->add("atman", -50);
	me->receive_damage("gin", 50);
	message_vision(HIY "$N��ϥ��������ʼ���ü�ʶ��ͨ��˼�붨 ...\n" NOR, me);
	if( random(me->query_skill("magic")) > (int)me->query_int() * 10 ) {
		if( random(me->query("max_atman")) < (int)me->query("atman")/2 ) {
			me->set_skill("essencemagic", lvl -1 );
			write( HIR "���������һƬ���ң���İ�ʶ��ͨ�����ˣ�\n" NOR );
			return 1;
		}
			me->set_skill("essencemagic", lvl + 1);
			write( HIG "��İ�ʶ��ͨ����ˣ�\n" NOR );
			return 1;
	}
	write("������ֻ����һ������\n");
	return 1;
}
