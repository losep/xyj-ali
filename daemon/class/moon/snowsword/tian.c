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
                return notify_fail("�������ѩ��ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ[�����ѩ����\n"); 

        if(me->query_skill("snowsword", 1) < 120 )
             return notify_fail("��ķ��ѩ�轣����������죬ʹ�����������ѩ��������\n");

        if(me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ���������������죬ʹ�����������ѩ��������\n");

        if( (int)me->query_skill("force",1) < 120 )
                return notify_fail("����ڹ��ȼ�������ʹ�����������ѩ��������\n");

        if( (int)me->query("max_force") < 1500 )
                return notify_fail("����������̫����ʹ�����������ѩ����\n");

        if( (int)me->query("force") < 500 )
                 return notify_fail("����������̫����ʹ�����������ѩ����\n");

   if ( file_name(environment(me)) != file_name(environment(target)) )  
               return notify_fail("��Ҫ��˭ʹ�á������ѩ��?\n");

    if (time()<(me->query_temp("perform/time")+8))
           return notify_fail(HIG"���ʹ�����"+HIR+me->query_temp("perform/name")+NOR+HIG"�ݣ������޷�ʹ���⹦��\n"NOR);

    me->set_temp("perform/time",time());
    me->set_temp("perform/name","�����ѩ");
    limb = target->query("limbs");
    me->set_temp("weapon2",me->query_temp("weapon"));
    damage = me->query_skill("snowsword",1)/4;
    damage = damage+(int)me->query_skill("sword",1)/8;
    damage = damage+(int)me->query_skill("moonforce",1)/8;

    if(me->query_skill_mapped("force")=="moonforce" && userp(me)) 
       damage=damage*2+random(me->query_skill("moonforce",1)/4);
     msg = HIM "$Nʹ���¹�����֮�ܡ������ѩ�������ж�ʱ������أ�������ѩ�裡\n" NOR;
    extra=(me->query_skill("snowsword",1)+me->query_skill("sword",1))/5;

    if(weapon->query("id") == "snowsword"){
          if(random(3)) {
		  me->set_temp("moon_pfm", 1);
                me->add_temp("apply/dodge", 350);
             }
          msg = HIR"\n$N����"NOR+weapon->name()+HIR"����������ʹ���¹�����֮�ܡ������ѩ�������ж�ʱ������أ�������ѩ�裡��\n\n"NOR;
          }     
        message_vision(msg, me, target);
        msgpfm = ({
             HIR"\n$Nŭ��һ�������"+ weapon->name()+HIR"һ�����Ծ����δ�������ȵ��������»�����ʩɱ�֣�"NOR,
             HIC"\n$Nת��"+ weapon->name()+HIC"��ˢˢˢ��������������������ף����Ƿ��ѩ�轣�е�ɱ�У�"NOR,
             HIM"\n$NͻȻ�ɳ�"+ weapon->name()+HIM"��ӭ������$n���⽣�������£�������ʱ֮��ֵ�$p�ؿھŴ���Ѩ��"NOR,
             HIY"\n$N�ὣ�ӳ�������Ϊ�������ӳ����ѩ�轣�еĹ��֣�����������ɱ�У�"NOR,
         });
       attack_msg= ({ 
            "\n$Nʹһ��"+HIB"���������ջ�Ӧפ��"NOR+"�����б�����Ϊһ������"+ weapon->name()+"����$n",
            "\nֻ��$N�����ת��ʹ��"+HIG"����������ƽɳ��"NOR+"��һ�������н���������"+ weapon->name()+"ɨ��$n",
            "\n$N����һЦ��һʽ"+HIY"���ܻ�Ⱦ����˪�ۡ�"NOR+"���������Ӱ��$nֻ����������������Ϯ��",
            "\n$N����"+ weapon->name()+"����һ����һʽ"HIW"��˪ӡ������Ҳ�ա�"NOR+"�ó�һ�麮������$n��",
            "\n$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n���"+ weapon->name()+"ֱָ$n�ĺ��أ�"+MAG"�����㸡���»ƻ衹"NOR,  
            "\n$N�������ܣ�һʽ"+HIC"���粨������֦����"NOR"��"+ weapon->name()+"���ƴ���������ֱָ$n��������",
        });   
msgfail = ({
     HIB"\n$n"HIB"��ʧɫ�������ˣ���ǿ���$N"HIB"����������!\n"NOR,              HIB"\n$n"HIB"���$N"HIB"�Ĺ����������˲������棬���͵���������˹�ȥ!\n"NOR,             HIB"\n$n"HIB"˫�۱������ѩ�����ԣ�����ʽ���ң��㿪��$N"HIB"��Ϯ����\n"NOR,
     HIB"\n$n"HIB"�������ߣ����ͼ�ת����������$N"HIB"����һ��! \n"NOR          });
   if (me->query_temp("moon_tian")) {
        if(!random(3)) me->set_temp("perform_tian",1);
   message_vision(HIW"�紵ѩ�裬ѩ��Ū�磬$N"HIW"����Ӱ������ʧ......\n"NOR,me);

        message_vision(msgpfm[random(sizeof(msgpfm))]+"\n",me,target);
      if(random(me->query("combat_exp"))>random(target->query("combat_exp")/3)) {

	if( !me->query("vip") && target->query("vip") ) {
        target->receive_damage("kee", damage/3,  me);
        target->receive_wound("kee", damage/6, me);
	} else {
        target->receive_damage("kee", damage*2/3,  me);
        target->receive_wound("kee", damage/3, me);
	}

        msg = damage_msg(damage, "����");
        msg = replace_string(msg, "$w", weapon->name());    
        msg = replace_string(msg, "$l", limb[random(sizeof(limb))]);
        msg += "( $n"+eff_status_msg((int)target->query("kee")*100/(int)target->query("max_kee"))+" )\n";  
        message_vision(msg, me, target);
      }else  message_vision(msgfail[random(sizeof(msgfail))],me,target);

      if(me->query_skill_mapped("unarmed")=="baihua-zhang" && userp(me)) {
	message_vision(WHT"\n$NͻȻ��"NOR+weapon->name()+WHT"�����ڿ���,$n���Ѿ���ͷת��$N�˻��ĳ�һ�ƣ�\n" NOR,me,target); 
        me->delete_temp("weapon");
        me->reset_action();
	if(random(me->query("combat_exp"))>random(target->query("combat_exp")*2/5)) { 
             baihua=me->query_skill("baihua-zhang",1)/4;
             baihua+=(int)me->query_skill("unarmed",1)/2;
             baihua+=(int)me->query_skill("moonforce",1)/4;
             target->receive_damage("kee", baihua*3/4,  me); 
             target->receive_wound("kee", baihua*3/4, me); 
             msg = damage_msg(baihua, "����"); 


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

        msg = damage_msg(damage, "����");
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
        msg = damage_msg(damage, "����");
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
        
//����һ����
        
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

        type = "����";
        message_vision(attack_msg[random(sizeof(attack_msg))],me,target);
        msgpfm = ({
            "ֻ�����ۡ���һ�£����һ�����䲻��Ĵ���$N��"+limb[random(sizeof(limb))]+"��$P�ҽ�һ������Ѫ������",
            "ֻ����������һ���ҽУ���һ����$N��"+limb[random(sizeof(limb))]+"�Դ�������$P��������ȫ��Ѫɫ��",
                 }); 
        msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
        if(me->query_skill_mapped("force")=="moonforce" && userp(me)) 
        msg += HIC"$n���ǽ�"CYN"�¹��ķ�"HIG"��"CYN"���ѩ�轣"HIC"�ںϹ�ͨ,һ���ǳ�,��â����.\n" NOR;
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
         message_vision(HIG"\n\n$Nһ��ѩ��ʹ�꣬���Ϊ֮��ɫ�����Ϊ֮���ݣ�\n"NOR, me, target);
         me->delete_temp("location"); 
        }
	if (me->query_temp("moon_tian")) { 
	message_vision(HIW"�罥Ϣ,ѩ��ֹ��$N"HIW"����Ӱ�������ֳ���...\n"NOR,me);
    }
        return 1;
}


int help(object me)
{
        write(HIR"
�˽���Ѹ������أ�������ѩ�裬���ּ���
�����мܡ���Ϊ��������֮Ů����ϲ������
�ལ��һ����һ��Ҫ�죬׼���ݡ�������
���ѩ�轣ʹ������Ч�����⻹����������
ĸ��̸���ܣ�Ч�����԰���\n"NOR+
HIG"
Ҫ��:snowsword>120
     sword>120
     ����force>120
     ����>500
     �������>1500��\n"NOR);

    return 1;
}

