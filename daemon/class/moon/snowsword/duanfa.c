//Last modified by waiwai@2001/05/21

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void duanfa_ok(object);

int perform(object me, object target)
{
        int damage,skill,skill2;

        skill = me->query_skill("sword", 1);
        skill2 = me->query_skill("snowsword", 1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��̷�����\n");

        if(!me->is_fighting())
                return notify_fail("���̷���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("snowsword", 1) < 200)
                return notify_fail("��ķ��ѩ�轣������������ʹ����һ�л������ѣ�\n");

	if( (int)me->query_skill("moonforce",1) < 200 )
		return notify_fail("���Բ���ķ�������\n");

        if(skill2 <skill)
                return notify_fail("��Ļ����������𻹲�����\n");

 	if(me->is_busy())
             return notify_fail("�����㺹��������ӣ��Ȼ�����ðɣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

	message_vision(HIW"\n\t\t$N���н���һ��������Ʈ�ݵ����������質�������������\n"NOR,me,target);
	message_vision(HIM"\n\t\t���Ѽ������ҵķ���������ǣ�ҡ���\n"NOR,me,target);
	message_vision(HIM"\n\t\t�Ӵ����ǣ�����黰����ĻŻ�����\n"NOR,me,target);

              damage=(int)me->query_skill("snowsword")*3+me->query("force_factor")+
		(int)me->query_skill("dodge")+random((int)me->query_skill("sword")*3);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
              message_vision(HIW"\n$n�������Ų����ĵ�һ�ᣬ���������������Ƕ������ˡ���\n\n"NOR,me,target);

		// Added by waiwai@2002/05/27
		if( !me->query("vip") && target->query("vip") ) {
             target->receive_damage("sen",damage/2,me);
             target->receive_wound("sen",damage/2,me);
		} else {
             target->receive_damage("sen",damage,me);
             target->receive_wound("sen",damage,me);
		}

             COMBAT_D->report_status(target);
	message_vision(HIY"\n\t\t$N�����һʽ"HIG"[�̷�]"HIY"�������ʹ������������ս���С���\n"NOR,me,target);
        me->receive_damage("sen", 50);
        me->add("force", -250);
	me->start_busy(2);

	} else {
        me->receive_damage("sen", 100);
        me->add("force", -500);
	me->start_busy(2+random(3));
             message_vision(HIG"\n$n"HIG"���һ����������ȫ���ܵ��˶���֪����\n"NOR,me,target);
             }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->kill_ob(me);
                        else target->kill_ob(me);
				}
			}
	return 1;
}
