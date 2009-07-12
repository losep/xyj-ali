// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//������ָ�� lotusfinger.c
// dream...12/18/96

inherit SKILL;

mapping *action = ({
   ([   "action":     "$N����ʳָ����ָ��£��һǰһ�����$n��$l",
     "dodge":     -30,
     "parry":     30,
     "force":     80,
     "damage_type":   "����",
                        "weapon":     "$N������ʳ��ָ",
   ]),
   ([   "action":     "$N�������У���ָ��Ҹ������ָ��$n��$l",
     "dodge":     -30,
     "parry":     30,
     "force":     90,
     "damage_type":   "����",     
                        "weapon":     "$N������ʳָ",
   ]),
   ([   "action":     "ֻ��$N����̧�ۣ���ָ���˸���Ȧ������$n��$l",
     "dodge":     -30,
     "parry":     30,
     "force":     100,
     "damage_type":   "����",
                        "weapon":     "$N������ʳָ",
   ]),
   ([   "action":     "$N����΢�࣬���ֱ���$n���󣬸������ֺ�����������$n��$l",
     "dodge":     -30,
     "parry":     30,
     "force":     90,
     "damage_type":   "����",
                        "weapon":     "$N������ʳָ", 
   ]),
            ([   "action":     "ֻ��$N���β�����ֻ������̧������ʳָ������$n��$l����ײ����",
     "dodge":     -30,
     "parry":     30,
     "force":     100,
     "damage_type":   "����",
                        "weapon":     "$N������ʳָ",
   ]),
            ([   "action":     "����$Nһ�����۽�$n���ԣ��������Ĵָ��ʳָ��$n��$l����",
     "dodge":     -30,
     "parry":     30,
     "force":     100,
     "damage_type":   "����",
                        "weapon":     "$N������Ĵָ��ʳָ",
   ]),
});

int valid_learn(object me)
{
   
   if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("������ָ������֡�\n");
   return 1;
}

int valid_enable(string usage)
{
   return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("sen") < 30 )
     return notify_fail("���ľ����޷������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("force") < 10 )
     return notify_fail("�������������ˡ�\n");

   me->receive_damage("sen", 30);
   me->add("force", -10);

   return 1;
}
