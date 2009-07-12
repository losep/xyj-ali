// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void finish(object me,int exp_gain, int pot_gain);

int main(object me, string arg)
{
   object where;
   int level,time,exp_gain,pot_gain,constant;

   where=environment(me);

   if(where->query("no_fight") || where->query("no_magic") )
        return notify_fail("��ȫ���ڽ�ֹ������\n");
   
//   if (!where->query("jingzuo_room"))
//     return notify_fail("�˴����˾���������\n");

   if ( (int)me->query_skill("chanting") < 20 ) 
     return notify_fail("����о���Ϊ̫�ͣ������й�������\n");
   
   if( (string)me->query("class")!="bonze") 
     return notify_fail("����û�г��ң���ʲô���ģ�\n");

   if (me->is_busy() || me->query_temp("pending/exercising"))
     return notify_fail("��������æ���ء�\n");

   if( me->is_fighting() )
     return notify_fail("ս���л�Ҫ�о���\n");

   if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
     return notify_fail("���������ǲ��壬��������Ҫ�߻���ħ��\n");

   if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
     return notify_fail("����������������������Ҫ�����ˣ�\n");
   
   if( (int)me->query("water") < 10 )
     return notify_fail("�����ڿڸ��������ЪЪ�ɡ�\n");

   level=(int)me->query_skill("chanting",1);
   time= level/2 + random(20);
// time=level of chanting/2, max 60-70 seconds.
   constant= level/10 + 15;
// not the real constang, divid by 25. the constant is from 17/25-1.
//   exp_gain= (level/5)*(k/25) is the formula, exp_gain=level/4.
//   so max. 1 minutes, about 20-25 exp. that's about 1.2k-1.5k/h
//   also a little random. (that's for a player with 100 level)
//   maybe a little high?
   exp_gain= (level*constant)/125;
   exp_gain= exp_gain/2 + random(exp_gain) + random((int)me->query("spi")/5) + 1;
   if( exp_gain > 30 ){
     exp_gain=20 +random(10);
   }
//   pot_gain=time/10, so each hour 400-500 exp.
   pot_gain= time/10 + random((int)me->query("int")/5) + 1;

   message_vision(HIY "$Nϯ�ض�����˫Ŀ΢�գ��������������˾��ġ�\n" NOR, me);
   me->start_busy(time);
   call_out("finish",time, me, exp_gain,pot_gain);
   return 1;
}

void finish(object me,int exp_gain, int pot_gain)
{
   string *msg=({
     "����Ϊ�࣬����ƣ�ͣ���̰����������Ϊ���������ڡ�",
     "и��׹�䣬���о������Ʒ��ն񣬴ݷ���ħ������������",
     "�޳����������������ѧ���ţ������ǻۣ��ɾͱ�ţ��̻�һ�У�Ϥ�Դ��֡�",
     "ƶ���Թ������Ե��������ʩ������Թ�ף�����ɶ񣬲������ˡ�",
     "������ȼ������������������ģ��ռ�һ�С�",
     "Ը���������������࣬�����������Ͼ����֡�",
     "Ը�Դ˹��£�ׯ�Ϸ������ϱ����ض����¼���;�ࡣ",
     "���м����ߣ�Ϥ�������ģ���������������������顣",
     });
   message_vision(HIY "$N���������"+msg[random(sizeof(msg))]+"\n" NOR, me);
   message_vision(HIY "$N���������۾�������һ����վ��������\n" NOR, me);

   me->add("combat_exp", exp_gain);
   tell_object(me, HIC "��ĵ���������" + chinese_number(exp_gain*3) + "ʱ����\n" NOR);
   me->add("chanting/exp", exp_gain); 
        if ((me->query("potential") - me->query("learned_points")) < 100){
                me->add("potential", pot_gain);
     me->add("chanting/pot", pot_gain);
     tell_object(me, HIC "���Ǳ��������" + chinese_number(pot_gain) + "�㣡\n" NOR);
   }

   if (me->query("water") >= pot_gain) me->add("water",-pot_gain*2);
   else me->set("water", 0);

   me->receive_damage("sen", me->query("int"));
   me->receive_damage("kee", me->query("int"));
   me->improve_skill("chanting", random(pot_gain), 1);

   me->start_busy(1);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : chanting

�о���������ߵ��С�
HELP
        );
        return 1;
}
