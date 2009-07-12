// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//���һ�ޡ�hellfire-whip.c

/*
�һ��    dodge  -10    parry  -10    damage  20
�һ���Ʋ��ƹ��У�һ���������乥����Χ�������⣬
�Ҵ˱�����ת�գ���ȥ���٣�Ҫ�мֵܵ�Ҳ��Ϊ���ס�
�ص���ɱ�˲���

Attention: �һ��ֻ��ǰ���У������ߣ��������ǿ�ɥ��
�;������У����� Perform �ģ������ƽ���������õ���
*/

#include <ansi.h>

inherit SKILL;
inherit SSERVER;

void second_attack();

mapping *action = ({
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����$w���ñ�ֱ������һ����Х�ʹ�$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "����",
     "post_action":     (: second_attack :),
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ����С���ճ����������š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -20,
                "parry":                -20,
                "damage":               30,
                "damage_type":  "����",
                "post_action":          (: second_attack :),
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����$w���ض��ɣ��ټ�����ϣ��·�����˵����е��һ𣬼�ͷ���Ե�����$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               25,
                "damage_type":  "����",
                "post_action":          (: second_attack :),
        ]),
        ([      "name":                 "�����һ�",
                "action":
"Ҳ��֪$N��ζ���һ�����������������һ����$nֻ��$w�ѻ�����$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "����",
                "post_action":          (: second_attack :),
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N������ǰ����������$w��ž������һȦ��һȦ�ؾ���$n",
                "dodge":                -5,
                "parry":                0,
                "damage":               15,
                "damage_type":  "����",
                "post_action":          (: second_attack :),
        ]),
        ([      "name":                 "�����һ�",
                "action":
"��Ц����$Nһ������������$w���ʣ�������Բ�����ɳ��ʯ�������ݺᣡ\n$n��֪��β���������������������",
                "dodge":                -15,
                "parry":                -20,
                "damage":               25,
                "damage_type":  "����",
                "post_action":          (: second_attack :),
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l���������ġ�С¥ҹ�ޡ�",
                "dodge":                -15,
                "parry":                -15,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":        "��ع�",
     "action":     "$N������Σ�����ƮƮ�����ĳʱ��̣�һ�С���ع�������$n$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                30,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���һ�ޡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������һ�ޡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   if (!me) me = this_object();
   i=me->query("HellZhen");
   if( !me->query("HellZhen") ) {
        return action[random(6)];
   }else {
   return action[i];
   }
}
     

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�һ�ޡ�\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("�㰴����ѧ����һ���һ�ޡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("ghost") + "/hellfire-whip/" + func;
}


void second_attack()
{
   object me, target, first, second;
   string attack_skill, martial_skill;
   int i;

//Find a target to submit second attack.

   me=this_player();
   target=offensive_target(me);
   if( !target ) return;

//Check weapon&weapon_second, weapon might be useless.

   if( me->query_temp("weapon")){
     first=me->query_temp("weapon");
   }else{
     return;
   }

   if( me->query_temp("weapon_second")){
     second=me->query_temp("weapon_second");
   }else{
     return;
   }

//Check weapon_second and it's mapped skills, only
//appointed skills can be used as second attack.

   attack_skill=second->query("skill_type");
   martial_skill=me->query_skill_mapped(attack_skill);

   if( !martial_skill || martial_skill!="zhuihun-sword" ){
     return;
   }

//Check second attack possibility, not literate, but
//another possible skills.

   i=(int)me->query_skill("literate",1);
   if( i < random(100) ) {
     return;
   }   

//Reset weapon&action for the attack.

   first->delete("equipped");
   second->set("equipped", "wielded");
   me->set_temp("weapon", second);
   me->reset_action();

   message_vision(RED"\n$Nһ��ռ���Ȼ�����������������\n"NOR, me);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
   second->set("equipped", "second_wield");
        first->set("equipped", "wielded");
        me->set_temp("weapon", first);
        me->reset_action();
   return;
}
