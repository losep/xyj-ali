//Changed By Rong@YSZZ
//by fly@YSZZ
// Update by waiwai@2003/04/25

#include <ansi.h>
#include <combat.h>
#include "/daemon/skill/eff_msg.h";
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg,*msgpfm,*limb,type,*attack_msg,*msgfail,dodge_skill;
        object weapon;
        object env=environment(me);
        int extra,damage,baihua;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("「漫天飞雪」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("你必须在使用剑时才能使[漫天飞雪」！\n"); 

        if(me->query_skill("snowsword", 1) < 120 )
             return notify_fail("你的风回雪舞剑法还不够娴熟，使不出「漫天飞雪」绝技。\n");

        if(me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法还不够娴熟，使不出「漫天飞雪」绝技。\n");

        if( (int)me->query_skill("force",1) < 120 )
                return notify_fail("你的内功等级不够，使不出「漫天飞雪」绝技。\n");

        if( (int)me->query("max_force") < 1500 )
                return notify_fail("你现在内力太弱，使不出「漫天飞雪」。\n");

        if( (int)me->query("force") < 500 )
                 return notify_fail("你现在内力太弱，使不出「漫天飞雪」。\n");

   if ( file_name(environment(me)) != file_name(environment(target)) )  
               return notify_fail("你要对谁使用「漫天飞雪」?\n");

    if (time()<(me->query_temp("perform/time")+8))
           return notify_fail(HIG"你刚使用完［"+HIR+me->query_temp("perform/name")+NOR+HIG"］，现在无法使用外功！\n"NOR);

    me->set_temp("perform/time",time());
    me->set_temp("perform/name","漫天飞雪");
    limb = target->query("limbs");
    me->set_temp("weapon2",me->query_temp("weapon"));
    damage = me->query_skill("snowsword",1)/4;
    damage = damage+(int)me->query_skill("sword",1)/8;
    damage = damage+(int)me->query_skill("moonforce",1)/8;

    if(me->query_skill_mapped("force")=="moonforce" && userp(me)) 
       damage=damage*2+random(me->query_skill("moonforce",1)/4);
     msg = HIM "$N使出月宫不传之密「漫天飞雪」，身行顿时急若风回，轻灵似雪舞！\n" NOR;
    extra=(me->query_skill("snowsword",1)+me->query_skill("sword",1))/5;

    if(weapon->query("id") == "snowsword"){
          if(random(3)) {
		  me->set_temp("moon_pfm", 1);
                me->add_temp("apply/dodge", 350);
             }
          msg = HIR"\n$N手中"NOR+weapon->name()+HIR"连划数剑，使出月宫不传之密「漫天飞雪」，身行顿时急若风回，轻灵似雪舞！！\n\n"NOR;
          }     
        message_vision(msg, me, target);
        msgpfm = ({
             HIR"\n$N怒喝一声，横过"+ weapon->name()+HIR"一搭，借势跃起，人未至，剑先到，凌虚下击，连施杀手！"NOR,
             HIC"\n$N转过"+ weapon->name()+HIC"，刷刷刷连进两剑，剑法快捷无伦，都是风回雪舞剑中的杀招！"NOR,
             HIM"\n$N突然飞出"+ weapon->name()+HIM"，迎面劈向$n，这剑连戳两下，竟在霎时之间分点$p胸口九处大穴！"NOR,
             HIY"\n$N横剑挥出，变守为攻，发挥出风回雪舞剑中的攻手，连进了两记杀招！"NOR,
         });
       attack_msg= ({ 
            "\n$N使一招"+HIB"「寒芳留照魂应驻」"NOR+"，手中兵器化为一道疾光"+ weapon->name()+"刺向$n",
            "\n只见$N半个急转，使出"+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，"+ weapon->name()+"扫向$n",
            "\n$N淡淡一笑，一式"+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来",
            "\n$N手中"+ weapon->name()+"轻轻一抖，一式"HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。",
            "\n$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，"+ weapon->name()+"直指$n的后胸，"+MAG"「暗香浮动月黄昏」"NOR,  
            "\n$N不闪不避，一式"+HIC"「风波不信菱枝弱」"NOR"，"+ weapon->name()+"蓄势待发，剑光直指$n破绽所在",
        });   
msgfail = ({
     HIB"\n$n"HIB"大惊失色，向后狂退，勉强躲过$N"HIB"的凌厉攻势!\n"NOR,              HIB"\n$n"HIB"察觉$N"HIB"的攻势凌厉，顾不得颜面，向后就倒，总算躲了过去!\n"NOR,             HIB"\n$n"HIB"双眼被满天的雪花所迷，但招式不乱，躲开了$N"HIB"的袭击！\n"NOR,
     HIB"\n$n"HIB"内力疾催，身型急转，侧身躲过了$N"HIB"的这一击! \n"NOR          });
   if (me->query_temp("moon_tian")) {
        if(!random(3)) me->set_temp("perform_tian",1);
   message_vision(HIW"风吹雪舞，雪舞弄风，$N"HIW"的身影渐渐消失......\n"NOR,me);

        message_vision(msgpfm[random(sizeof(msgpfm))]+"\n",me,target);
      if(random(me->query("combat_exp"))>random(target->query("combat_exp")/3)) {

	if( !me->query("vip") && target->query("vip") ) {
        target->receive_damage("kee", damage/3,  me);
        target->receive_wound("kee", damage/6, me);
	} else {
        target->receive_damage("kee", damage*2/3,  me);
        target->receive_wound("kee", damage/3, me);
	}

        msg = damage_msg(damage, "刺伤");
        msg = replace_string(msg, "$w", weapon->name());    
        msg = replace_string(msg, "$l", limb[random(sizeof(limb))]);
        msg += "( $n"+eff_status_msg((int)target->query("kee")*100/(int)target->query("max_kee"))+" )\n";  
        message_vision(msg, me, target);
      }else  message_vision(msgfail[random(sizeof(msgfail))],me,target);

      if(me->query_skill_mapped("unarmed")=="baihua-zhang" && userp(me)) {
	message_vision(WHT"\n$N突然把"NOR+weapon->name()+WHT"激射在空中,$n早已经昏头转向，$N乘机拍出一掌！\n" NOR,me,target); 
        me->delete_temp("weapon");
        me->reset_action();
	if(random(me->query("combat_exp"))>random(target->query("combat_exp")*2/5)) { 
             baihua=me->query_skill("baihua-zhang",1)/4;
             baihua+=(int)me->query_skill("unarmed",1)/2;
             baihua+=(int)me->query_skill("moonforce",1)/4;
             target->receive_damage("kee", baihua*3/4,  me); 
             target->receive_wound("kee", baihua*3/4, me); 
             msg = damage_msg(baihua, "瘀伤"); 


             msg = replace_string(msg, "$w", weapon->name());     
             msg = replace_string(msg, "$l", limb[random(sizeof(limb))]); 
             msg += "( $n"+eff_status_msg((int)target->query("kee")*100/(int)target->query("max_kee"))+" )\n";   
             message_vision(msg, me, target); 
                }else  message_vision(msgfail[random(sizeof(msgfail))],me,target);


        me->set_temp("weapon",weapon);
        me->reset_action();
    }
        message_vision(msgpfm[random(sizeof(msgpfm))]+"\n",me,target);
        if(random(me->query("combat_exp"))>random(target->query("combat_exp")/2)){

	if( !me->query("vip") && target->query("vip") ) {
        target->receive_damage("kee", damage/3,  me);
        target->receive_wound("kee", damage/6, me);
	} else {
        target->receive_damage("kee", damage*2/3,  me);
        target->receive_wound("kee", damage/3, me);
	}

        msg = damage_msg(damage, "刺伤");
        msg = replace_string(msg, "$w", weapon->name());    
        msg = replace_string(msg, "$l", limb[random(sizeof(limb))]);
        msg += "( $n"+eff_status_msg((int)target->query("kee")*100/(int)target->query("max_kee"))+" )\n";  
        message_vision(msg, me, target); 
      }else message_vision(msgfail[random(sizeof(msgfail))],me,target);
        message_vision(msgpfm[random(sizeof(msgpfm))]+"\n",me,target);
        if(random(me->query("combat_exp"))>random(target->query("combat_exp"))/2){
	if( !me->query("vip") && target->query("vip") ) {
        target->receive_damage("kee", damage/3,  me);
        target->receive_wound("kee", damage/6, me);
	} else {
        target->receive_damage("kee", damage*2/3,  me);
        target->receive_wound("kee", damage/3, me);
	}
        msg = damage_msg(damage, "刺伤");
        msg = replace_string(msg, "$w", weapon->name());    
        msg = replace_string(msg, "$l", limb[random(sizeof(limb))]);
        msg += "( $n"+eff_status_msg((int)target->query("kee")*100/(int)target->query("max_kee"))+" )\n";  
        message_vision(msg, me, target); 
      }else message_vision(msgfail[random(sizeof(msgfail))],me,target);
	}else {
        me->add_temp("apply/damage",(int)me->query_skill("snowsword",1)/3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        me->add_temp("apply/damage",-(int)me->query_skill("snowsword",1)/3);
     }
       if(me->query_temp("moon_pfm")){
        me->add_temp("apply/dodge", -350);
        me->delete_temp("moon_pfm");
        }
        me->add("force", -extra/2);
        
//增加一攻击
        
     if(random(3)){
	if( !me->query("vip") && target->query("vip") ) {
        target->receive_damage("kee", damage/2,  me);
        target->receive_wound("kee", damage/4, me);
        target->start_busy(1);
	} else {
        target->receive_damage("kee", damage,  me);
        target->receive_wound("kee", damage/2, me);
        target->start_busy(2);
	}

        type = "瘀伤";
        message_vision(attack_msg[random(sizeof(attack_msg))],me,target);
        msgpfm = ({
            "只听“噗”的一下，最后一剑出其不意的刺向$N的"+limb[random(sizeof(limb))]+"，$P惨叫一声，鲜血横流。",
            "只听“啊”的一声惨叫，这一剑在$N的"+limb[random(sizeof(limb))]+"对穿而出，$P脸上已是全无血色。",
                 }); 
        msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
        if(me->query_skill_mapped("force")=="moonforce" && userp(me)) 
        msg += HIC"$n更是将"CYN"月宫心法"HIG"和"CYN"风回雪舞剑"HIC"融合贯通,一气呵成,剑芒大威.\n" NOR;
        message_vision(msg, target, me);
        msg = COMBAT_D->status_msg((int)target->query("kee") * 100 /(int)target->query("max_kee"));
        message_vision("($N"+msg+")\n", target);
        }
        else if (random(2))
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        me->delete_temp("perform_tian");
        me->delete_temp("weapon2");
        me->start_busy(1+random(2));
	if(me->query_temp("perform/wuxue")){
         remove_call_out("check_fight");
         me->delete_temp("perform/wuxue");
         me->delete_temp("perform/wuxue_time");
         me->set_temp("perform/time",time()-2);         
         message_vision(HIG"\n\n$N一套雪舞使完，天地为之变色，神鬼为之动容！\n"NOR, me, target);
         me->delete_temp("location"); 
        }
	if (me->query_temp("moon_tian")) { 
	message_vision(HIW"风渐息,雪渐止，$N"HIW"的身影重新显现出来...\n"NOR,me);
    }
        return 1;
}


int help(object me)
{
        write(HIR"
此剑法迅急若风回，轻灵似雪舞，敌手极难
躲闪招架。多为气短力弱之女子所喜。连出
多剑，一剑比一剑要快，准，狠。如果配合
风回雪舞剑使用有奇效。另外还可以向西王
母请教该项技能，效果明显啊。\n"NOR+
HIG"
要求:snowsword>120
     sword>120
     基本force>120
     内力>500
     最大内力>1500。\n"NOR);

    return 1;
}

