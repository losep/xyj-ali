// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Genaric self-made skills.
// sword
// mon 1/16/98

/*
���ѩ�轣��    dodge  -20    parry  -10    damage  15
*/

inherit SKILL;


mapping *action1 = ({
   ([   "action":
"$Nʹһ�С��������ջ�Ӧפ��������$w��Ϊһ���������$n��$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     10,
     "damage_type":   "����"
   ]),
});

mapping *action = ({
   ([   "action":
"$N����$w��׾�ش���$n��$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     10,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail("�������������û�а취�����ѩ�轣����\n");

   if( (string)me->query_skill_mapped("force")!= "moonforce")
     return notify_fail("���ѩ�轣�������������ɽ��Ů���Բ���ķ���������\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ�������������\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action()
{
        object me=this_player();

   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("�����������������û�а취��ϰ���ѩ�轣����\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("�㰴����ѧ����һ����ѩ�轣����\n");
   return 1;
}
