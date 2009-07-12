//Create by jack 2002
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me)
{
	object obj;
	int skill,level,dayphase,n,i;
	me=this_player();
	dayphase =NATURE_D->query_current_day_phase();

	if( (int)me->query_skill("moonforce", 1) < 100 )
		return notify_fail("���Բ���ķ��ȼ�������\n");
        if( (int)me->query("mana") < 300 )     
                return notify_fail("��ķ���������\n");
	if( (int)me->query("kee") < 300 )
		return notify_fail("�����Ѫ���㡣\n");
	if( (int)me->query("sen") < 300 )
		return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("flower_on") ) 
                return notify_fail("�����㣬С�İѻ������ˡ�\n");

        skill = me->query_skill("moonforce",1);


        me->add("mana", -skill*2/3);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        if( skill>=100 && skill<180)
	{
	n=1;
	level=3;
	}else if( skill>=180 && skill<280)
	{
	n=2;
	level=4;
	}else if( skill>=280 && skill<400)
	{
	n=3+random(2);
	level=n+2;
	}else if( skill>400)
	{
	n=5;
	level=7;
	}
	if (dayphase < 6)
	{
        message_vision(HIR"$N�����������ֳ�����ָ״�������ڿ���һ�㣬\n�����������������������Ϊ"+chinese_number(n)+"�����̫������\n" NOR, me);
	}else{
        message_vision(HIB"$N�����������ֳ�����ָ״�������ڿ���һ�㣬\n�����¹����������������Ϊ"+chinese_number(n)+"����������������\n" NOR, me);
	}

        for(i=1;i<=n;i++)
        {
	if (dayphase < 6)
	{
        obj=new("/d/obj/flower/sunflower");
	}else{
        obj=new("/d/obj/flower/moonflower");
	}
	obj->move(me);
        }

        me->set_temp("flower_on", 1);

        call_out("remove_flower", level, me);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_flower(object me)
{
        me->delete_temp("flower_on");
	return;
}

