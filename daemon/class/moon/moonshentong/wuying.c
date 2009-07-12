
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
		return notify_fail("你还没学会使用「舞影七星」。。。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想对谁施展「舞影七星」？\n");  

	if((int)me->query("mana") < 1000 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 300 )
		return notify_fail("你无法集中精力！\n");

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
                return notify_fail(HIR"没有太阳花没法施展「舞影七星」！\n"NOR);
	}else{
	if((int)number < 2)
                return notify_fail(HIB"没有月亮花没法施展「舞影七星」！\n"NOR);
	}

	if( (int)me->query_temp("flower_on") ) 
		return notify_fail("你慢点，小心把花打碎了。\n");

	if( (int)me->query_temp("flower_off") ) 
		return notify_fail("刚施展了「天女散花」，好累啊。\n");

	if( (int)me->query_temp("wuying_busy") ) 
		return notify_fail("刚施展了「舞影七星」，法力还没恢复。\n");

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
"$N"HIR"妩媚一笑，手中飞出"+chinese_number(number)+"朵太阳花，在$N"HIR"周围画了个圈，落在地上，发出火红的光芒。\n\n" 
NOR;
	msg += HIR
"接着$N"HIR"忽左忽右的，犹如跳舞一般，正在$n"HIR"不防备之际，$N"HIR"用发力催动"+chinese_number(number)+"朵太阳花。\n\n" 
NOR;
	msg += HIR
"迅速向$n"HIR"旋转而至，把$n"HIR"困在其中。\n\n" 
NOR;
	su=HIR"太阳花";
	}else{
	msg = HIB
"$N"HIB"妩媚一笑，手中飞出"+chinese_number(number)+"朵月亮花，在$N"HIB"周围画了个圈，落在地上，发出幽蓝的光芒。\n\n" 
NOR;
	msg += HIB
"接着$N"HIB"忽左忽右的，犹如跳舞一般，正在$n"HIB"不防备之际，$N"HIB"用发力催动"+chinese_number(number)+"朵月亮花。\n\n" 
NOR;
	msg += HIB
"迅速向$n"HIB"旋转而至，把$n"HIB"困在其中。\n\n" 
NOR;
	su=HIB"月亮花";
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
	msg +=  HIR "$n"HIR"见$N"HIR"舞姿翩翩，艳丽而奔放，陶醉之时，"+chinese_number(number)+"朵太阳花从不同方向对$n"HIR"攻来。\n" NOR;
        me->set_temp("wuying_busy", 1);
        call_out("remove_busy", 4+random(2), me);
	call_out("add_damage", 1, me,target,number,su,dayphase);
	}else{
	msg +=  HIB "$n"HIB"见$N"HIB"舞姿翩翩，轻盈而朦胧，陶醉之时，"+chinese_number(number)+"朵月亮花从不同方向对$n"HIB"攻来。\n" NOR;
        me->set_temp("wuying_busy", 1);
        call_out("remove_busy", 4+random(2), me);
	call_out("add_damage", 1, me,target,number,su,dayphase);
	}
		me->start_busy(2+random(2));
		if( living(target) ) target->kill_ob(me);
	}else{
	if (dayphase < 6)
	{
	msg +=  HIR "结果$n"HIR"不为所动，施展法力，震开了所有的花。\n" NOR;
	msg +=  HIR "$N"HIR"不得已，大手一挥，"+su+HIR"又回到了$N"HIR"的手中\n" NOR;
	}else{
	msg +=  HIB "结果$n"HIB"不为所动，施展法力，震开了所有的花。\n" NOR;
	msg +=  HIB "$N"HIB"不得已，大手一挥，"+su+HIB"又回到了$N"HIB"的手中\n" NOR;
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
		"左",
		"右",
		"上",
		"下",
		"前",
		"后",
		"左上",
		"右下",
		"左下",
		"右上",

	});
	string *body=({
		"手部",
		"头部",
		"脚部",
		"肩部",
		"右脚",
		"左脚",
		"左肩",
		"右肩",
		"背后",
		"胸口",
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
	message_vision(HIR"\n"+su+"从"+hit[random(10)]+"对准了$N"HIR"的"+body[random(10)]+"对穿而出\n"NOR, target);
	}else{
	message_vision(HIB"\n"+su+"从"+hit[random(10)]+"对准了$N"HIB"的"+body[random(10)]+"对穿而出\n"NOR, target);
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
