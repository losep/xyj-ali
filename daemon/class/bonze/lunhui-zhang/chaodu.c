#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����ɻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->query_temp("lastchaodu")+15>time())
	  return notify_fail("��ո�ʹ�����ɾ��У�����Ъ����ɡ�\n");
//      if (!(me->query("id")=="bell" || "xiaoxiao"))
//       return notify_fail("ֻ�з���ſ���ʹ���Ⱦ���.\n");
	if (me->query("force")<100)
	 return notify_fail("�������������\n");
/*          extra = me->query_skill("lunhui-staff",1) * 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
*/
	me->add("force",-100);
  msg = HIR "$N����˵��:��Ի,��ɱֹɱ!�ҽ���ʹ�ɱ��.��������ͷ�������Щ���֮ͽ!\n" NOR;
	message_vision(msg, me, target);
  msg =  HIY "����ѭ������Ӧ��ˬ��\n"NOR;
         message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",0);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
  msg =  HIC "�����ֻ֣������©��\n"NOR;
          message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",3);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
  msg =  HIG "�������������سɷ�\n"NOR;
         message_vision(msg, me, target);
	me->set_temp("LUNHUI_perform",5);
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
 msg =  HIW "$n�����Ѿ����˼������磮������\n"NOR;
	message_vision(msg, me, target);
/*	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
*/
	me->set_temp("lastchaodu",time());
	me->start_busy(2);
	return 1;
}
