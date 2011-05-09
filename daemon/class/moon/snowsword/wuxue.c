//��ѩ
//requirement:force,dodge,sword all over 100
//Last modified by waiwai@2001/05/21

#include <ansi.h>

inherit F_SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
    int skill_sword, skill_dodge, dodge_amount, attack_amount;

    if (me->query_skill_mapped("dodge") != "moondance")
            return notify_fail("�㻹û��ʩչ�����������ء�\n");

    skill_dodge = me->query_skill("moondance",1);            

    if (skill_dodge<80)
        return notify_fail("���輼������������\n");

    if (me->query_skill_mapped("force")!="moonforce")
        return notify_fail("��ѩ�������̫���ľ�����ʹ�á�\n");

    if (me->query_skill("moonforce",1)<80) 
        return notify_fail("���̫���ľ��������졣\n");

    skill_sword=me->query_skill("sword");

    if (skill_sword<80) 
        return notify_fail("��Ľ���̫��ˡ�\n"); 

    if ((int)me->query("force") < 50)
        return notify_fail("�������������\n");

    if ((int)me->query_temp("powerup"))
            return notify_fail("���Ѿ����˹����ˡ�\n");
    
    me->add("force", -50);
    message_vision(
            HIW"\n$N��һ�����������Ṧ���ν����衣ֻ��$N�㲻մ�أ����н�Խ��Խ�죬�𽥻���һ�Ű������ù�����\n" NOR, me);
 
    attack_amount=skill_sword*random(6)/6;
    dodge_amount=skill_dodge*(5+random(6))/6; 
    me->add_temp("apply/attack", attack_amount);  
    me->add_temp("apply/dodge",dodge_amount);  //trade offense for defense.  
    me->set_temp("powerup", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", 
        me, dodge_amount,attack_amount:), skill_sword/10);
 
    return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
    me->add_temp("apply/dodge", -dodge_amount);
    me->add_temp("apply/attack", -attack_amount);
    me->delete_temp("powerup");
    message_vision(HIW"$N����������֧�����ò������Ų����Ż����С�\n"NOR,me);
}


