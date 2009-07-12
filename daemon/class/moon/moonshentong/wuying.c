
inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
	string msg,su;
	int ap, dp;
        int number, size, i;
	int dayphase = NATURE_D->query_current_day_phase();
        object *tar;


	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 180
	 || (int)me->query_skill("moonshentong",1) < 180)
		return notify_fail("�㻹ûѧ��ʹ�á���Ӱ���ǡ�������\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("�����˭ʩչ����Ӱ���ǡ���\n");  

	if((int)me->query("mana") < 1000 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 300 )
		return notify_fail("���޷����о�����\n");

	if (dayphase < 6)
	{
        tar=all_inventory(me);
        size = sizeof(tar); 
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "sun flower") {
                        if (tar[i]->query_amount())
                              number+=tar[i]->query_amount();
                        else number++;
                }
        }
	}else{
        tar=all_inventory(me);
        size = sizeof(tar); 
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "moon flower") {
                        if (tar[i]->query_amount())
                              number+=tar[i]->query_amount();
                        else number++;
                }
        }
	}
	if (dayphase < 6)
	{
	if((int)number < 2)
                return notify_fail(HIR"û��̫����û��ʩչ����Ӱ���ǡ���\n"NOR);
	}else{
	if((int)number < 2)
                return notify_fail(HIB"û��������û��ʩչ����Ӱ���ǡ���\n"NOR);
	}

	if( (int)me->query_temp("flower_on") ) 
		return notify_fail("�����㣬С�İѻ������ˡ�\n");

	if( (int)me->query_temp("flower_off") ) 
		return notify_fail("��ʩչ�ˡ���Ůɢ���������۰���\n");

	if( (int)me->query_temp("wuying_busy") ) 
		return notify_fail("��ʩչ�ˡ���Ӱ���ǡ���������û�ָ���\n");

	me->add("mana", -(int)me->query_skill("moonshentong"));
	me->receive_damage("sen", 10);
	if((int)me->query_skill("spells") >= 180
	 && (int)me->query_skill("moonshentong",1) < 280)
	{
	if(number>3) number=3+random(2);
	}else if((int)me->query_skill("spells") >= 280
	 && (int)me->query_skill("moonshentong",1) < 380)
	{
	if(number>4) number=4+random(3);
	}else if((int)me->query_skill("spells") > 380)
	{
	if(number>7) number=7;
	}

	if (dayphase < 6)
	{
	msg = HIR
"$N"HIR"����һЦ�����зɳ�"+chinese_number(number)+"��̫��������$N"HIR"��Χ���˸�Ȧ�����ڵ��ϣ��������Ĺ�â��\n\n" 
NOR;
	msg += HIR
"����$N"HIR"������ҵģ���������һ�㣬����$n"HIR"������֮�ʣ�$N"HIR"�÷����߶�"+chinese_number(number)+"��̫������\n\n" 
NOR;
	msg += HIR
"Ѹ����$n"HIR"��ת��������$n"HIR"�������С�\n\n" 
NOR;
	su=HIR"̫����";
	}else{
	msg = HIB
"$N"HIB"����һЦ�����зɳ�"+chinese_number(number)+"������������$N"HIB"��Χ���˸�Ȧ�����ڵ��ϣ����������Ĺ�â��\n\n" 
NOR;
	msg += HIB
"����$N"HIB"������ҵģ���������һ�㣬����$n"HIB"������֮�ʣ�$N"HIB"�÷����߶�"+chinese_number(number)+"����������\n\n" 
NOR;
	msg += HIB
"Ѹ����$n"HIB"��ת��������$n"HIB"�������С�\n\n" 
NOR;
	su=HIB"������";
	}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

	ap=(int)me->query_skill("moonshentong");
	ap+=ap*ap*ap/10 + random( (int)me->query("mana"));

	dp=(int)target->query_skill("spells");
	dp+=dp*dp*dp/10 + random( (int)target->query("mana"));

	if ( ap +random(dp)+random(dp/90) > random( ap + dp ) ) {
	if (dayphase < 6)
	{
	msg +=  HIR "$n"HIR"��$N"HIR"�������棬���������ţ�����֮ʱ��"+chinese_number(number)+"��̫�����Ӳ�ͬ�����$n"HIR"������\n" NOR;
        me->set_temp("wuying_busy", 1);
        call_out("remove_busy", 4+random(2), me);
	call_out("add_damage", 1, me,target,number,su,dayphase);
	}else{
	msg +=  HIB "$n"HIB"��$N"HIB"�������棬��ӯ�����ʣ�����֮ʱ��"+chinese_number(number)+"���������Ӳ�ͬ�����$n"HIB"������\n" NOR;
        me->set_temp("wuying_busy", 1);
        call_out("remove_busy", 4+random(2), me);
	call_out("add_damage", 1, me,target,number,su,dayphase);
	}
		me->start_busy(2+random(2));
		if( living(target) ) target->kill_ob(me);
	}else{
	if (dayphase < 6)
	{
	msg +=  HIR "���$n"HIR"��Ϊ������ʩչ�������������еĻ���\n" NOR;
	msg +=  HIR "$N"HIR"�����ѣ�����һ�ӣ�"+su+HIR"�ֻص���$N"HIR"������\n" NOR;
	}else{
	msg +=  HIB "���$n"HIB"��Ϊ������ʩչ�������������еĻ���\n" NOR;
	msg +=  HIB "$N"HIB"�����ѣ�����һ�ӣ�"+su+HIB"�ֻص���$N"HIB"������\n" NOR;
	}
		me->start_busy(1+random(2));
	} 

	message_vision(msg, me, target);
	return 1;
}
int add_damage(object me, object target,int number,string su,int dayphase)
{
	int damage;
        int num, size, i, four,amount;
        object *tar;
	string *hit=({
		"��",
		"��",
		"��",
		"��",
		"ǰ",
		"��",
		"����",
		"����",
		"����",
		"����",

	});
	string *body=({
		"�ֲ�",
		"ͷ��",
		"�Ų�",
		"�粿",
		"�ҽ�",
		"���",
		"���",
		"�Ҽ�",
		"����",
		"�ؿ�",
	});
	if( !target
	|| !me
	|| !target
        || target->is_corpse()
        || !target->is_character()
	|| !target->is_fighting(me)
	|| environment(me) != environment(target)) {
		remove_call_out("add_damage");
		return 1;
	}
	if (dayphase < 6)
	{
	message_vision(HIR"\n"+su+"��"+hit[random(10)]+"��׼��$N"HIR"��"+body[random(10)]+"�Դ�����\n"NOR, target);
	}else{
	message_vision(HIB"\n"+su+"��"+hit[random(10)]+"��׼��$N"HIB"��"+body[random(10)]+"�Դ�����\n"NOR, target);
	}
	damage=(int)me->query("max_mana")/9 - random((int)target->query("max_mana")/10);
	damage+=(int)me->query("mana_factor");
	damage = random(damage);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/3);
		COMBAT_D->report_status(target);
		me->receive_damage("kee", 25);
		me->add("mana", -25);

	number--;
        tar=all_inventory(me);
        size = sizeof(tar);

	if( number ) {
	if (dayphase < 6)
	{
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "sun flower") {
                        if (tar[i]->query_amount())
                              num+=tar[i]->query_amount();
                        else num++;
                }
        }
	if(num<=0) return 1;
	}else{
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "moon flower") {
                        if (tar[i]->query_amount())
                              num+=tar[i]->query_amount();
                        else num++;
                }
        }
	if(num<=0) return 1;
	}
		call_out("add_damage", 1, me, target, number,su,dayphase);
	}





	if (dayphase < 6)
	{
        for (i = 0; i< size; i++){
           if (tar[i]->query("material") == "sun flower"){
                amount=tar[i]->query_amount();
                if (amount) four+=amount;
                  else four++;
                if (four <= 1)
                destruct(tar[i]);
                else {
                       tar[i]->set_amount(four-1);
                       four=1;
                       break;
                }
           }
        }
	}else{
        for (i = 0; i< size; i++){
           if (tar[i]->query("material") == "moon flower"){
                amount=tar[i]->query_amount();
                if (amount) four+=amount;
                  else four++;
                if (four <= 1)
                destruct(tar[i]);
                else {
                       tar[i]->set_amount(four-1);
                       four=1;
                       break;
                }
           }
        }
	}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }


	return 1;
}
void remove_busy(object me)
{
        me->delete_temp("wuying_busy");
	return;
}
