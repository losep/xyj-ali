// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���������ķ������Լ���\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("dragonforce",1);

        me->add("force", -100);
        me->receive_damage("kee", 20);

        message_vision(
                HIR
"$N΢һ�������������ķ����������¶�ʱ�������ɫ�����ۣ����α���쳣�ߴ�վ�����￴�����������ݡ�\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
   me->add_temp("apply/damage",skill/6);
   me->add_temp("apply/unarmed", skill/6);
//   me->add_temp("apply/strength",skill/6);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
   me->add_temp("apply/damage", -amount/2);
        me->add_temp("apply/unarmed", -amount/2);
//      me->add_temp("apply/strength", -amount/2);
        me->delete_temp("powerup");
        tell_object(me, "��������ķ�����һ������ϣ����۽�����ȥ�ˡ�\n");
}

