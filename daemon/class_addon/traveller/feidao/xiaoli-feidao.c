// counterattack.c

#include <ansi.h>

inherit SSERVER;
void surekill(object me, object target);
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mС��ɵ�[37mֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int) me->query_skill("feidao",1) <= 200)
		return notify_fail("��ķɵ��������������������ܷ���С��ɵ���\n");

	message_vision(RED"$NĿ��ת���ض���$n��׼����������һ����\n"NOR,me,target);
msg = HIY "$Nʹ���ɵ������������鷢��" + HIR "С��ɵ�" +HIY "��$nֻ������ǰһ�����ʺ��ѱ��Դ�����������" ;
msg +=  "\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR;

	message_vision(msg, me, target);
		target->die();
	return 1;
}
