//Last modified by waiwai@2001/05/21

#include <ansi.h>

inherit SSERVER;

void free(object target);

int perform(object me, object target)
{
	object weapon;
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong,req;

	if( !target ) target = offensive_target(me);
	if (!weapon = me->query_temp("weapon"))
		return notify_fail("��û�ý�����ʲô��������\n");
	 
      req=(int)me->query_skill("sword", 1)+(int)me->query_skill("snowsword", 1)+(int)me->query_skill("moonforce", 1); 
	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("snowsword",1) < 100)
		return notify_fail("��Ĺ���ȼ���������ʹ����������\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"��ֻ����ս����ʹ�á�\n"NOR);

	if(target->query_temp("in_qingwang"))
	return notify_fail(target->query("name")+"�Ѿ���������������ˣ�\n");  

	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	msg = HIB"$N�Է����߶�������������"+weapon->query("name")+HIB"���һ�ţ���$n"+HIB"��ͷ���¡�\n"NOR;

	success = 1;
	ap = (me->query_skill("spells")+me->query_skill("snowsword")) /2 ;
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp =target->query_skill("spells");
	dp =dp * dp * dp /12;
	dp += (int)target->query("daoxing");
	if( ap < dp ) success = 0;
		if(success == 1 ){
		msg +=  HIB "$n"HIB"������һƬ���ң���ʹ����ͻȻ���������������˶�������������ͷ��ס��\n" NOR;
		target->set_temp("in_qingwang", 1);
        howlong = random((me->query_skill("spells") -100))+1;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
		msg +=  HIG "$n"HIG"�������ѣ���Ϊ����������������һԾ�������������Ϯ����\n" NOR;	
		
        	if( living(target) ) target->kill_ob(me);
			me->start_busy(2);
		} 

	message_vision(msg, me, target);

	return 1;
}

void free(object target)
{
	if (target)
	target->delete_temp("in_qingwang");      
	return;
}

