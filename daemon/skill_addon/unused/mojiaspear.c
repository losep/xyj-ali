// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// cloudstaff.c

inherit SKILL;

mapping *action = ({
   ([   "action":     "$Nʹһ�С�ӭ����������������$w��������$n���ţ���ɤ��ǰ�ģ�",
     "damage":     40,
     "dodge":     10,
     "parry":     -10,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����$w��һ�С�����Ѱ�ߡ�����$n$l��",
     "damage":     30,
     "dodge":     20,
     "parry":     -10,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����$wһ˳��ʹ������Ů���롹����$n$l��",
     "damage":     35,
     "dodge":     20,
     "parry":     -20,
     "damage_type":   "����"
   ]),
   ([   "action":     "$Nһת��ʹ��һ�С�����ǹ����$wһͦ����$n$l��",
     "damage":     50,
     "dodge":     10,
     "parry":     -30,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 100 )
     return notify_fail("�������������û�а취��ħ��ǹ����\n");
   if( !(ob = me->query_temp("weapon"))
   ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");

   return 1;
}

int valid_enable(string usage)
{
   return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   object weapon;

   if( !objectp(weapon = me->query_temp("weapon"))
   ||   (string)weapon->query("skill_type") != "staff" )
     return notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");

   if( (int)me->query("kee") < 30 
   ||    (int)me->query("force") < 5  )
     return notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
        write("�㰴����ѧ����һ��ǧ��������\n");
   return 1;
}
