// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//��Ůɢ�� 
// dream 7/17/97
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
   int number, size, i, four;
   object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����Ůɢ������\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

   if((int)me->query_skill("baihua-zhang", 1) <80)
     return notify_fail("��İٻ��Ƽ��𻹲�����\n");

   tar=all_inventory(me);
        size = sizeof(tar); 
   if(size) {
           for(i=0;i<size;i++)
      if(tar[i]->query("material") == "flower") {
        number++;
     }
     }

   
   if((int)number < 5)
     return notify_fail("��Ļ�������ʩչ����Ůɢ������\n");

        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

   msg = HIC
"\n$N΢΢һЦ��������ն����������컨�꣬һʱ��������\n"
"$nֻ������������Ӱ��ס�ˣ�һʱ��Ȼ��֪����мܣ�������˵�����ˣ�\n" NOR;

        ap = me->query_skill("baihua-zhang", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("kee");
   dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
     msg += HIC "˭֪$n��������ʤ������һ�ڣ��ѽ����л�����䣡\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = (int)me->query_skill("baihua-zhang",1) / 10 +
        (int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 400 + random((int)me->query("kee") / 200 );
     msg += HIC "��Щ���꿴������������ȴ�缲�����������$n,�����Ƕ�����\n" NOR;
     if (number < 10) damage +=random(number+1);
     else damage +=random(10);
                        target->receive_damage("sen", me->query("eff_sen")*damage/100, me);
                        target->receive_damage("kee", me->query("eff_kee")*damage/70, me);
                        me->improve_skill("baihua-zhang", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
    }


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
   for (i = 0; i< size; i++){
     if (tar[i]->query("material") == "flower"){
     four++;
     if (four <= 5)
     destruct(tar[i]);
     else
     break;
     }
   }
        me->start_busy(3);
        return 1;
}

int help(object me)
{
    write(@HELP
����Ůɢ����
��������������ǿ�󡣵�����Է��书̫�ߣ����ܷ��������˺���

��ָ�    perform flower on <object>
��Ҫ��    �ٻ��ƣ���������������������ʻ�
HELP);
    return 1;
}