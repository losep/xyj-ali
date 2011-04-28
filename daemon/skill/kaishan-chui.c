/*
��ɽ��  dodge  15    parry  -15    damage  30
�䴸��ֱ��ֱȥ������Ϊʵ���ƴ����ͣ��мֵܵ�
��Ϊ���ף�һ���������˺����󡣵������ǲ�����
ӯ��
*/
inherit SKILL;

void hitagain(object me, object victim, object weapon,int damage);

string name() { return "��ɽ��"; }

mapping *action = ({
    ([   "action":   "$N����$wһת������һ��ǿ���ķ�������$n��$l��\n��һ���ּ����ͣ��ƴ����ݣ��ۼ��͵���$n��ǰ",
        "dodge":   10,
        "parry":   -10,
        "damage":   30,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
    ([   "action":   "$N˫��һ������$w�д������װ����������ͷ�����ؾ���$n���˹�ȥ",
        "dodge":   15,
        "parry":   -15,
        "damage":   30,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
    ([   "action":   "$N��$w�߾ٹ��磬�����������׼$n��$l��������һ��",
        "dodge":   20,
        "parry":   -20,
        "damage":   35,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
    ([   "action":   "$N�������飬����$w���Ϻ��£�����׽������ȥ·��\n����$nһ��㱼䣬��ৡ�������$n��$l",
        "dodge":   0,
        "parry":   -10,
        "damage":   25,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
    ([   "action":   "$N����$n����֮������ת$w�����Ѵ�����$n��\n��һ���������о��������Ϣ�ĵ�����$n��$l",
        "dodge":   10,
        "parry":   -10,
        "damage":   20,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
    ([   "action":   "$N����$w�ͻ��˸���Բ�����������ɳ�����\n��$n���ܱ���֮�ǣ�����$wбб������$n��$l",
        "dodge":   20,
        "parry":   -25,
        "damage":   30,
        "damage_type":   "����",
        "post_action":      (: hitagain :),
    ]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("str") < 25)
        return notify_fail("��ɽ��Ҫ��ǿ��׳���ܷ������á�\n");

    if ((int)me->query("max_force") < 100)
        return notify_fail("�������������û�а취ѧ��ɽ����\n");

    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "hammer")
        return notify_fail("���������һ�Ѵ��Ӳ���ѧ��ɽ����\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="hammer"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("str") < 25)
        return notify_fail("��ɽ��Ҫ��ǿ��׳���ܷ������á�\n");

    if ((int)me->query("kee") < 30 || (int)me->query("force") < 5)
        return notify_fail("������̫���ˣ�ǿ�����档\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ�鿪ɽ����\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void hitagain(object me, object victim, object weapon,int damage)
{
    if (damage != -2) return;

    // if victim parried out the attack, we attack again...
    message_vision("$N������۷��飬��������$n�û�����������\n", victim, me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
