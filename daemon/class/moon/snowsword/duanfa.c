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
                return notify_fail("你要对谁施展这一招「短发」？\n");

        if(!me->is_fighting())
                return notify_fail("「短发」只能在战斗中使用！\n");

        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("snowsword", 1) < 200)
                return notify_fail("你的风回雪舞剑法不够熟练，使用这一招会有困难！\n");

	if( (int)me->query_skill("moonforce",1) < 200 )
		return notify_fail("你的圆月心法不够！\n");

        if(skill2 <skill)
                return notify_fail("你的基本剑法级别还不够！\n");

 	if(me->is_busy())
             return notify_fail("看你香汗淋漓的样子，等会儿再用吧！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

	message_vision(HIW"\n\t\t$N手中剑势一缓，和着飘逸的冷月凝香舞唱起歌来…………\n"NOR,me,target);
	message_vision(HIM"\n\t\t我已剪短了我的发，剪断了牵挂……\n"NOR,me,target);
	message_vision(HIM"\n\t\t从此忘记，你的情话，你的慌话……\n"NOR,me,target);

              damage=(int)me->query_skill("snowsword")*3+me->query("force_factor")+
		(int)me->query_skill("dodge")+random((int)me->query_skill("sword")*3);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
              message_vision(HIW"\n$n听着听着不由心底一酸，心神荡漾，三魂六魄都丢光了……\n\n"NOR,me,target);

		// Added by waiwai@2002/05/27
		if( !me->query("vip") && target->query("vip") ) {
             target->receive_damage("sen",damage/2,me);
             target->receive_wound("sen",damage/2,me);
		} else {
             target->receive_damage("sen",damage,me);
             target->receive_wound("sen",damage,me);
		}

             COMBAT_D->report_status(target);
	message_vision(HIY"\n\t\t$N歌舞间一式"HIG"[短发]"HIY"不经意的使出，竟不似在战斗中……\n"NOR,me,target);
        me->receive_damage("sen", 50);
        me->add("force", -250);
	me->start_busy(2);

	} else {
        me->receive_damage("sen", 100);
        me->add("force", -500);
	me->start_busy(2+random(3));
             message_vision(HIG"\n$n"HIG"冷哼一声，五音不全，跑调了都不知道？\n"NOR,me,target);
             }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->kill_ob(me);
                        else target->kill_ob(me);
				}
			}
	return 1;
}
