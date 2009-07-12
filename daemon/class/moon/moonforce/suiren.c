// Created by waiwai@2000/10/20
// Last modified by waiwai@2001/06/20
// 引入no_break参数设置.

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int exert(object me, object target)
{
    string msg;
    object obj;

    obj=target->query_temp("weapon");

    if( !target )
          return notify_fail(WHT"格式：exert suiren [目标ID]\n"NOR);

    if(!target)target = offensive_target(me);

    if( !target
        || !target->is_character()
        || !me->is_fighting(target) || !living(target))
          return notify_fail(WHT"格式：exert suiren [目标ID]\n"NOR);

    if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");

    if( target->is_busy() )
           return notify_fail(target->name() + "目前正在发呆，正是进攻的好时机!\n");

    if( (int)me->query_skill("moonforce", 1) < 100 )
    return notify_fail("你的圆月心法火候不够，还不会使用「碎刃」。\n");

    msg = HIW"\n$N沉肩滑步，运起一股阴柔之气激射而出，击向$n"HIW"手中的兵刃！\n"NOR;

    if( random(me->query("combat_exp")) >  (int)target->query("combat_exp")/3 ) {
         //其实觉得没必要判断什么左右手.
         if (target->query_temp("weapon") ||  target->query_temp("secondary_weapon")) {
	  if( obj->query("no_break") == 1 ) 
            return notify_fail(""WHT+target->name()+NOR WHT"手中的"+obj->name()+NOR WHT"不能被震碎。\n"NOR);
         msg += HIY"结果$p"HIY"手中的"HIG+obj->query("name")+HIY"与这股阴柔之气一碰竟被震了个粉碎！\n" NOR;
         obj->unequip();
         obj->move(environment(target));
         obj->set("name", "震碎的" + obj->query("name"));
         obj->set("long", HIC"一堆破碎的"+obj->query("name")+HIC"碎片。\n"NOR);
         obj->set("value", 0);
         obj->set("weapon_prop", 0);
         obj->set("liquid", 0);//这里是以前所忽略的.
         call_out("remove_broken_obj",random(60)+60,obj);//时间应该尽量短些.
         target->reset_action();
         me->add("force", -150);
         me->start_busy(2+random(1));
         }
         } else {
         msg += HIC"可是$p"HIC"急急拆招，躲了开去，$P的计谋没有得逞。\n" NOR;
         me->add("force", -200);
         me->start_busy(2+random(2));
         }
         message_vision(msg, me, target);
         return notify_fail(""WHT+target->name()+NOR WHT"目前是空手，没什么可以震碎的。\n"NOR); 

          if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
         }
            return 1;
}

void remove_broken_obj(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),"一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
    destruct(obj);
  }
}
