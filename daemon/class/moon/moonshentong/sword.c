// Created by waiwai@2001/05/13

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int  skill;
	skill=me->query_skill("sword",1);

	if(!wizardp(me) && userp(me)) {
	if(!skill||skill<40)
	return notify_fail("��������̫�ͣ�\n");

       if (userp(me) && !me->query("vip") )
          return notify_fail(HIW"VIP��Աר�ã�����Ȩʹ�ã�\n"NOR);

	if((int)me->query("family/family_faith") < 100 )
		return notify_fail("������Ҳ�����\n");

	if((int)me->query_skill("moonshentong", 1) < 50)
        	return notify_fail("����¹��ɷ�������\n");

//	if( (string)me->query("occupation") != "fighter" || (string)me->query("zhongzu") != "man" )
//      return notify_fail("�㲢��������ʿ���޷�ʹ����ѵ���\n");
	}

	if(me->query_temp("execration"))
		return notify_fail("���������䡣\n");

	if(me->query_temp("weapon"))
		return notify_fail("�������Ѿ��������ˡ�\n");

	if((int)me->query("mana") < 100 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
	return notify_fail("��ľ���û�а취��Ч���У�\n");
        me->add("mana", -100);
	me->receive_damage("sen", 50);
	msg=HIC"$N�����дʣ�ƾ����ʿ������,�����������£����к�ҹ�����в��ա�\n"NOR;
	message_vision(msg,me);
	me->set_temp("execration",1);
	call_out("do_execration",2,me,skill);
	return 1;
}

int do_execration(object me,int skill)
{
	string msg;
	object sword;

	me->delete_temp("execration");

	if(me->query_temp("weapon")) {
	    tell_object(me,"���Ѿ��������ˡ���ֹʩ��\n");
	    return 1;
	}

	sword=new("/daemon/class/obj/magicsword");

	if(!sword) {
	    tell_object(me,"/daemon/class/obj/magicsword.c�ļ�����\n");
	    return 1;
	}

        msg=HIW"ֻ���ĵ��ƻ�ǻ��ƹ�ǹ��ǿ�⣬�ɶ����������ĵ��棬�����\n"
            "���������������$N�����ϣ����γ���һ�ѽ�״����----"HIR"��֮�� \n"NOR;

	message_vision(msg,me);
	sword->move(me);
	sword->wield();
	sword->do_dest(me,skill*2);
	if(skill>=500) skill=500;
       sword->set("weapon_prop/damage",skill/3);
	me->set_temp("apply/damage",skill/3);
	return 1;
}

