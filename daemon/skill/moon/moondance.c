// Ali by NewX
 
//�����������衿 moondance.c
// cglaem...12/07/96.

inherit SKILL;

mapping *action = ({
    ([   "action":     "$NǳǳһЦ��һ�С����ڷɻ������Ρ��������޵�����$n��$l",
     "dodge":     -5,
     "parry":     -5,
     "force":     50,
     "damage_type":   "����",
    ]),
    ([   "action":     "$N����һ�٣��������⡣$n����������\n����$N������ָ��ֱ��$n˫Ŀ�����ǡ��ٻ��ơ�֮ɱ�֡�һ֦���ӳ�ǽ����",
     "dodge":     -10,
     "parry":     -10,
     "force":     120,
     "damage_type":   "����",
                        "weapon":     "������",
    ]),
    ([   "action":     "ֻ��$N��ȻһЦ��˫�Ʒ��ɣ�һ�С������һ���ӳ�졹�����������",
     "dodge":     -20,
     "parry":     -20,
     "force":     70,
     "damage_type":   "����",
    ]),
    ([   "action":     "$N����һ�ڣ���Ȼ�������ߣ�����˳��һ�С��ƾ�֦ͷ����������$n��$l��ȥ",
     "dodge":     15,
     "parry":     15,
     "force":     60,
     "damage_type":   "����",
    ]),
    ([   "action":     "ֻ��$N˫�����գ���ɫ���أ�һ�С��˻��������޻���ȫ������$n��$l",
     "dodge":     5,
     "parry":     5,
     "force":     80,
     "damage_type":   "����",
    ]),
});

string *dodge_msg = ({
     "$n��ͷϸ��ȹ�ޣ���˼��������������֮���ƺ�����������ȴ��$N����һһ�������Ρ�\n",
     "ֻ��$nһ��ת����Ȼ����һЦ��$Nһ��֮�£����ﻹ�����ڡ�\n",
     "����$n���һЦ�����˷��������ξ���$NƮ����\n$Nֻ��һ��������ǣ���һ�о�������֮����\n",
     "$n�����飬��֫��š����Ȼ�ó��߲���Ӱ��$N��һ��������ֵó����ˣ���Ӱ��\n",
     "$nȹ��ƮƮ�������橣���Ȼ��$Nͷ���ɹ������Ů�����֮�ˣ��������֮�Σ�$N���ɵÿ����ˣ�\n",
     "$n�Ų���ӯ��������Ȼ�����ӱ�����ˮ����Ʈ��һ���ӹ�������$N����Ϯ��������Ȼ��ȥ��\n",
     "$n����΢����������磬���Ὣ$N�ľ�������һ�ԣ��������⡣\n",

});

int valid_enable(string usage)
{
    return ( usage=="dodge" || usage=="fascination" || usage=="unarmed" );
}

int valid_learn(object me)
{
    if ((string)me->query("gender") != "Ů��")
        return notify_fail("����������ֻ��Ů�Բ�������\n");
    if ((int)me->query("spi") < 10)
        return notify_fail("������Բ�����û�а취�����������衣\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if ( (int)me->query("sen") < 30 )
        return notify_fail("��ľ���̫���ˣ����������������衣\n");
    me->receive_damage("sen", 30);
    return 1;
}

string perform_action_file(string func)
{
    return CLASS_D("moon") + "/moondance/" + func;
}
