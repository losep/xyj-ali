// Created by waiwai@2000/10/20
// Last modified by waiwai@2001/06/20
// ����no_break��������.

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int exert(object me, object target)
{
    string msg;
    object obj;

    obj=target->query_temp("weapon");

    if( !target )
          return notify_fail(WHT"��ʽ��exert suiren [Ŀ��ID]\n"NOR);

    if(!target)target = offensive_target(me);

    if( !target
        || !target->is_character()
        || !me->is_fighting(target) || !living(target))
          return notify_fail(WHT"��ʽ��exert suiren [Ŀ��ID]\n"NOR);

    if( (int)me->query("force") < 200 )      
                return notify_fail("�������������\n");

    if( target->is_busy() )
           return notify_fail(target->name() + "Ŀǰ���ڷ��������ǽ����ĺ�ʱ��!\n");

    if( (int)me->query_skill("moonforce", 1) < 100 )
    return notify_fail("���Բ���ķ���򲻹���������ʹ�á����С���\n");

    msg = HIW"\n$N���绬��������һ������֮���������������$n"HIW"���еı��У�\n"NOR;

    if( random(me->query("combat_exp")) >  (int)target->query("combat_exp")/3 ) {
         //��ʵ����û��Ҫ�ж�ʲô������.
         if (target->query_temp("weapon") ||  target->query_temp("secondary_weapon")) {
	  if( obj->query("no_break") == 1 ) 
            return notify_fail(""WHT+target->name()+NOR WHT"���е�"+obj->name()+NOR WHT"���ܱ����顣\n"NOR);
         msg += HIY"���$p"HIY"���е�"HIG+obj->query("name")+HIY"���������֮��һ���������˸����飡\n" NOR;
         obj->unequip();
         obj->move(environment(target));
         obj->set("name", "�����" + obj->query("name"));
         obj->set("long", HIC"һ�������"+obj->query("name")+HIC"��Ƭ��\n"NOR);
         obj->set("value", 0);
         obj->set("weapon_prop", 0);
         obj->set("liquid", 0);//��������ǰ�����Ե�.
         call_out("remove_broken_obj",random(60)+60,obj);//ʱ��Ӧ�þ�����Щ.
         target->reset_action();
         me->add("force", -150);
         me->start_busy(2+random(1));
         }
         } else {
         msg += HIC"����$p"HIC"�������У����˿�ȥ��$P�ļ�ıû�еóѡ�\n" NOR;
         me->add("force", -200);
         me->start_busy(2+random(2));
         }
         message_vision(msg, me, target);
         return notify_fail(""WHT+target->name()+NOR WHT"Ŀǰ�ǿ��֣�ûʲô��������ġ�\n"NOR); 

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
    tell_object(environment(obj),"һ��΢�紵����"+obj->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(obj);
  }
}
