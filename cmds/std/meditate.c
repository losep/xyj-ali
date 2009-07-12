// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int finish(object me, int sen_cost);

int main(object me, string arg)
{
        int sen_cost, busy_time;

        seteuid(getuid());
        
       if(environment(me)->query("no_fight") || 
           environment(me)->query("no_magic") )
              return notify_fail("��ȫ���ڽ�ֹ������\n");
                        
        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() ) return
notify_fail("ս����ڤ˼����������\n");

        if( !arg
        ||      !sscanf(arg, "%d", sen_cost) )
                return notify_fail("��Ҫ�����پ���ڤ˼��\n");

        if( sen_cost < 10 ) return notify_fail("������Ҫ�� 10
�㡸�񡹲���ڤ˼��\n");

        if( (int)me->query("sen") < sen_cost )
                return
notify_fail("�����ھ���̫���ˣ�����ڤ˼������ʧ����Զ�Ѳ�������\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
                return
notify_fail("����������״��̫���ˣ��޷����о���\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 1 )
                return
notify_fail("����������״��̫�����ˣ��޷�����ڤ˼��״̬��\n");

        write("����ϥ����������ڤ˼��һ�����\n");

        me->receive_damage("sen", sen_cost);

   busy_time=random(1+sen_cost/20)+3;
   me->start_busy(busy_time);

   call_out("finish",busy_time, me, sen_cost);
   return 1;
}

int finish(object me, int sen_cost)
{
   int mana_gain;

        // This function ranged from 1 to 15 when sen_cost = 30
        mana_gain = sen_cost * ((int)me->query_skill("spells") / 10
                + (int)me->query_spi() ) / 30;

        if( mana_gain < 1 ) {
                tell_object(me, "���ǵ��������۾���ֻ��������һƬ�հס�\n");
       me->start_busy(1);
                return 1;
        }

   me->add("mana", mana_gain );
   tell_object(me, "��ڤ����ϣ������۾����˶���վ��������\n");

           if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
                   if( (int)me->query("max_mana") >=
(int)me->query_skill("spells") * 10) {

        tell_object(me, "����ķ������ӵ�˲�����Ȼ��������һƬ���ң��ƺ������������Ѿ�����ƿ����\n");
                } 
     else {
                           tell_object(me, "��ķ�������ˣ�\n");
                           me->add("max_mana", 1);
                   }
                   me->set("mana", me->query("max_mana"));
           }

        me->start_busy(1);   
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : meditate|mingsi [<�ķѡ��񡹵�����Ԥ��ֵ 30>]
 
����ڤ˼��������ľ�������Ч�ؼ������۳��ܹ�����ʩչ����������
�����������Լ��ķ�����

��ο� help stat 
HELP
        );
        return 1;
}

