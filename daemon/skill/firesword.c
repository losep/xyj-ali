// ALi by NewX

// firesword. ��������ڽ�����

/*
������ڽ���    dodge  -20    parry  -10    damage  15
�˽���Ѹ������أ�������ѩ�裬���ּ��Ѷ����мܣ���Ϊ
��������֮Ů����ϲ��
*/

// �������ջ�Ӧפ����������ƽɳ
// �ܻ�Ⱦ����˪�ۣ�˪ӡ������Ҳ��
// ��ɸ���������磬���㸡��Ӱ�ƻ�
// �粨������֦��
inherit SKILL;

mapping *action = ({
   ([   "action":
"$Nʹһ�С��������ջ�Ӧפ��������$w��Ϊһ���������$n��$l",
     "dodge":     -5,
                "parry":                -10,
     "damage":     10,
     "damage_type":   "����"
   ]),
   ([   "action":
"ֻ��$N������ת��ʹ������������ƽɳ����һ�������н���������ɨ��$n��$l",
     "dodge":     -35,
                "parry":                -5,
     "damage":     20,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����һЦ��һʽ���ܻ�Ⱦ����˪�ۡ����������Ӱ��$nֻ����������������Ϯ����ȴ��֪���������",
     "dodge":     -10,
                "parry":                -15,
     "damage":     15,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w����һ����һʽ��˪ӡ������Ҳ�ա��ó�һ�麮������$n��$nֻ����������������ס��",
     "dodge":     -30,
                "parry":                -5,
     "damage":     15,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w��һ����ֻ�������㣬Ʈ��������\n��һ�С���ɸ���������硹ֻ����$n�ۻ����ң����ﻹ���м�",
     "dodge":     -20,
                "parry":                -20,
     "damage":     15,
     "damage_type":   "����"
   ]),
        ([      "action":
"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ��أ�����һʽ�����㸡���»ƻ衹",  
                "dodge":                -35,
                "parry":                -5,
                "damage":           20, 
                "damage_type":  "����"
        ]),
   ([      "action":
"$N�������ܣ�һʽ���粨������֦��������ɫ��ţ����ƴ�����һ��������ˮ�����������Ľ���ֱָ$n��������",
                "dodge":                -5,
                "parry":                -10,
                "damage":          10,
                "damage_type":  "����"
        ]),
   
});

int valid_enable(string usage)
{
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("fox-force",1) < 40 )
        return notify_fail("�������ķ���Ϊ��ǳ��û��ѧ���潣��\n");
    if ((int)me->query_skill("moondance", 1) < 50)
        return notify_fail("���������������Ϊ��ǳ��û��ѧ���潣��\n");
    return 1;
}

mapping query_action(object me, object weapon) 
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)(weapon->query("skill_type")) != "sword")
        return notify_fail("�������������û������ô�����潣���� :)\n");
    if ((int)(me->query("kee")) < 50)
        return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("kee", 30);
    return 1;
}

string perform_action_file(string action)
{
    return CLASS_D("gumu") + "/firesword/" + action;
}

