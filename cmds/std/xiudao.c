// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

#include <obstacle.h>

void finish(object me, int pot_gain);

int main(object me, string arg)
{
   int obstacle_size = sizeof(obstacles);
   int busy_time, pot_gain;
   int xiudao_lvl;
   mapping fam;
   object where;

   seteuid(getuid());
   where = environment(me);
   
   if(where->query("no_fight") || where->query("no_magic") )
        return notify_fail("��ȫ���ڽ�ֹ������\n");
   
//   if (!where->query("jingzuo_room"))
//     return notify_fail("�˴����˾���������\n");

   if ( (xiudao_lvl = me->query_skill("spells")) < 20 ) 
     return notify_fail("�㷨����Ϊ̫�ͣ������й�������\n");

   if (me->is_busy() || me->query_temp("pending/exercising"))
     return notify_fail("��������æ���ء�\n");

   if( me->is_fighting() )
     return notify_fail("ս�����޵�������������\n");

   if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
     return notify_fail("���������ǲ��壬��������Ҫ�߻���ħ��\n");

   if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
     return notify_fail("����������������������Ҫ�����ˣ�\n");

   pot_gain = xiudao_lvl/20 + random(3);
   busy_time = random(7200)/pot_gain/100;
   pot_gain = 1 + random(pot_gain*2);
   busy_time *= pot_gain;
   pot_gain += (int)me->query("obstacle/number")*pot_gain/2/obstacle_size;
   if (me->query("food") + me->query("water") < 20) busy_time *= 2;
   message_vision(HIY "$N�����۾�����ϥ���£�����ĬĬ���֪��˵Щʲô��\n" NOR, me);
   me->start_busy(busy_time);
   call_out("finish",busy_time, me, pot_gain);
   return 1;
}

void finish(object me, int pot_gain)
{
   message_vision(HIY "$N���������۾�������һ����վ��������\n" NOR, me);

   tell_object(me, HIC "��ĵ���������" + chinese_number(pot_gain*3) + "ʱ����\n" NOR);
 //       if ((me->query("potential") + pot_gain - me->query("learned_points")) < 101)
                me->add("combat_exp", pot_gain);
//   else
//     me->set("potential", me->query("learned_points")+100);

   if (me->query("food") >= pot_gain) me->add("food",-pot_gain);
   else me->set("food", 0);

   if (me->query("water") >= pot_gain) me->add("water",-pot_gain);
   else me->set("water", 0);

   me->receive_damage("sen", me->query("int"));
   me->receive_damage("kee", me->query("int"));
   me->improve_skill("spells", random(pot_gain));

   me->start_busy(1);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : xiudao

������������ߵ��С�
HELP
        );
        return 1;
}
