// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//�����촸��

/*
  dodge  15    parry  -15    damage  30
�䴸��ֱ��ֱȥ������Ϊʵ���ƴ����ͣ��мֵܵ�
��Ϊ���ף�һ���������˺����󡣵������ǲ�����
ӯ��
*/

inherit SKILL;

mapping *action = ({
   ([   "action":   "$N����$wһת������һ��ǿ���ķ�������$n��$l��
��һ���ּ����ͣ��ƴ����ݣ��ۼ��͵���$n��ǰ",
     "dodge":   10,
     "parry":   -10,
     "damage":   30,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N˫��һ������$w�д������װ����������ͷ�����ؾ���$n���˹�ȥ",
     "dodge":   15,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N��$w�߾ٹ��磬�����������׼$n��$l��������һ��",
     "dodge":   20,
     "parry":   -20,
     "damage":   35,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N�������飬����$w���Ϻ��£�����׽������ȥ·��
����$nһ��㱼䣬��ৡ�������$n��$l",
     "dodge":   0,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$n����֮������ת$w�����Ѵ�����$n��
��һ���������о��������Ϣ�ĵ�����$n��$l",
     "dodge":   10,
     "parry":   -10,
     "damage":   20,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$w�ͻ��˸���Բ�����������ɳ�����
��$n���ܱ���֮�ǣ�����$wбб������$n��$l",
     "dodge":   20,
     "parry":   -25,
     "damage":   30,
     "damage_type":   "����",
   ]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_force") < 50)
        return notify_fail("�������������û�а취�����촸��\n");

    if (!(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "hammer")
        return notify_fail("���������һ���󴸲��������촸��\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("kee") < 50
    ||  (int)me->query("force") < 50)
        return notify_fail("�����������������û�а취��ϰ���촸��\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ����촸��\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

