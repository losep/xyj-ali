// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//Ħ����


inherit SKILL;

mapping *action = ({
   ([   "action":     "$Nһ�С���벶��ʽ��������ץ��$n�ĵ������$n�����Է���һ˲�䣬����ȴ��������$n��$l",
     "dodge":     10,
     "parry":     10,
     "force":     160,
     "damage_type":   "����",
                        "weapon":     "����ʳָ",
   ]),
   ([   "action": "$N˫��һ��������÷����䡻��˫���紩������һ�����·��ɡ�\n$n�������ۣ�ɲ�Ǽ�$N����������ǰ",
     "dodge":     5,
     "parry":     -15,
     "force":     180,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
   ([   "action":     "ֻ��$Nһת��һָ��в�´���������$n��$l��ȴ����һ�С��������ߡ�",
     "dodge":     5,
     "parry":     10,
     "force":     100,
     "damage_type":   "����",
                        "weapon":     "����ʳָ",
   ]),
   ([   "action":     "$N˫��һ������������ƶ�������һ�С���ʿ��ɽ������һ�������$n��$l",
     "dodge":     20,
     "parry":     20,
     "force":     140,
     "damage_type":   "����",
                        "weapon":     "����", 
   ]),
            ([   "action":     "$Nһ�С������������������ڿ����黮�˸��뻡������$n��$l",
     "dodge":     30,
     "parry":     10,
     "force":     70,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
            ([   "action":     "����$Nһ��ŭ�����ָ߸߾���һʽ��������ɽ��������$n��$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
});

int valid_learn(object me)
{
   
   if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("��Ħ���ֱ�����֡�\n");
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
   if( (int)me->query("mud_age") > 100 )
     return notify_fail("Ħ����ֻ��ѧ����������\n");
   
   return 1;
}
void skill_improved(object me)
{
        if ((int)me->query_skill("kugu-blade", 1) % 10 == 0 ) {
                tell_object(me, "\n�����֮�࣬����һ�������᲻��������һ�������˵��ϡ�\n\n");
                me->add("max_force", -10);
     me->start_budy(5+random(2));
        }
}

