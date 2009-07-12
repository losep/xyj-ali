// Created by waiwai@2000/12/20
// Last modified by waiwai@2002/12/05

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int extra,damage;
        if( !target ) target = offensive_target(me);
 
       if( !target
          || !target->is_character()
          || !me->is_fighting(target) )
                return notify_fail("�������ѩ��ֻ����ս����ʹ�á�\n");

       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("ʹ�á������ѩ�������ðѽ���\n"); 

        if( (int)me->query("force") < 400 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("snowsword",1) < 60 )
                return notify_fail("��ķ��ѩ�轣���ȼ�����.\n");

        if( (int)me->query_skill("moonforce",1) < 60 )
                return notify_fail("���Բ���ķ��ȼ�����.\n");

 	if(me->is_busy())
             return notify_fail("����æ�š���\n");

         msg = HIY "$Nʹ���¹�����֮�ܡ������ѩ�������ж�ʱ������أ�������ѩ�衭��\n" NOR;

        message_vision(msg, me);

        extra=me->query_skill("snowsword",1);
       damage=extra*2+random((int)me->query_skill("dodge")*4);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {

        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);

	// Added by waiwai@2002/05/27
	if( !me->query("vip") && target->query("vip") ) {
       target->receive_damage("kee",damage/2,me);
       target->receive_wound("kee",damage/4,me);
	} else {
       target->receive_damage("kee",damage,me);
       target->receive_wound("kee",damage/2,me);
	}

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        me->add_temp("apply/attack",-extra);  
        me->add_temp("apply/damage",-extra);

        me->add("force", -200);
        me->start_busy(2+random(1));
	} else {
             message_vision(HIC"\n$n"HIC"һ����Խ��Խ�����⣬��Ц����������ˡ��� \n"NOR,me,target);
        me->add("force", -300);
        me->start_busy(3);
             }


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->kill_ob(me);
                        else target->kill_ob(me);
				}
			}

        return 1;
}


