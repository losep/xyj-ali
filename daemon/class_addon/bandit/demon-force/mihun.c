// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;

	if( !me->is_fighting() )
		return notify_fail("���Ի�󷨣�ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("�������������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ���Ի�󷨣ݣ�\n");
	}

	skill = me->query_skill("force");

	me->add("force", -50);
	me->receive_damage("sen", 20);

	message_vision(
		HIB "\n$N����������죬˫�۱���쳣���ʣ�\n" NOR, me, target);
	
	if( random(target->query("combat_exp")) > (int)me->query("combat_exp") / 2 ) {
		message_vision("$N�ܿ��ת��ͷȥ���ܿ���$n��Ŀ�⡣\n", target, me);
		me->start_busy(3);
		return 1;
	}

	damage = (int)me->query("force_factor") * 2 - target->query("max_force") / 15;
	if( damage < 1 ) {
		message_vision("����$N��$n��ע�������޶�....��\n", target, me);
		me->start_busy(3);
		return 1;
	}

	target->receive_damage("gin", damage);
	if( random(skill) > (int)target->query("cps") * 2 )
		target->start_busy(3);
	message_vision("$N��$n�Ĺ����������󣬲��Խ�������������\n", target, me);
	
	me->start_busy(1);
	return 1;
}

