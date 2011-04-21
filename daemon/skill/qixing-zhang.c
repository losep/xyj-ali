// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//�������ȷ���qixing-zhang.c
inherit SKILL;

/*
�����ȷ�    dodge  2.5    parry  -6    damage  23
*/

string name() { return "�����ȷ�"; }

mapping *action = ({
   ([   "action":     "$N̤�����ࡹλ������������$w���˼�����Բ��������һ����$n��ͷ����",
     "dodge":     15,
     "parry":     -5,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��Ȼ̤�롸��诡�λ���߽�һ�����������־��ܣ����е�$wһ�ʣ�ɨ��$n$l",
     "dodge":     0,
     "parry":     -15,
     "damage":     15,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��ס�����᡹λ�����е�$w������ɳ��ʯ����ȷ�ѹ��$n��$l",
     "dodge":     5,
     "parry":     -5,
     "damage":     30,
     "damage_type":   "����"
   ]),
   ([   "action":     "ֻ��$N����һ�ˣ�ǡ��̤ס����Ȩ��λ������һ���粽��$w����һ���������$n$l",
     "dodge":     5,
     "parry":     0,
     "damage":     20,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N���$w����̤����⡹λ��������������Ȼ��ֻ����ͷһ�������߰�����$n��$l",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��̤��������λ����$w����һ������;ȴʹ�˸��ɾ�����βಣ���һ��������$n$l",
     "dodge":     -5,
     "parry":     -10,
     "damage":     25,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N�ڡ�ҡ�⡹λ�Ϸ·����˸������μ�ת��������ת�����е�$w��ɨ��$n��$l",
     "dodge":     5,
     "parry":     -10,
     "damage":     25,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_force") < 100)
        return notify_fail("�������������û�а취ѧ�����ȡ�\n");

    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff")
        return notify_fail("���������һ�����Ȳ���ѧ�����ȡ�\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="staff"||usage="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("kee") < 30 || (int)me->query("force") < 5)
        return notify_fail("������̫���ˣ�ǿ�����档\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ�������ȡ�\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
