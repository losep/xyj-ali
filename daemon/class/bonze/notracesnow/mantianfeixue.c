// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("��ֻ�ܽ��������ѩ�������Լ������ϡ�\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("feixue") ) return 
	notify_fail("���Ѿ���ʩչ�������ѩ���ˡ�\n");
	skill = me->query_skill_eff_lvl("notracesnow");
	if(skill < 150) return notify_fail("���̤ѩ�޺�̫���ˣ�\n");
	 me->add("force", -100);
        message_vision( HIR
"$N�й����������о�Ȼ��������������е�ѩ����\n" NOR, me);
        me->add_temp("apply/dodge", skill/5);
        me->set_temp("feixue", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/5 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feixue");
        tell_object(me, "��ģ������ѩ��ʩչ��ϣ������ȶ���������\n");
}
 
