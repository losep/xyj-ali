// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "�겻����",
                "action":
"$N�Ӷ�$w��һ�С��겻���᡹����$n��$l��$nֻ��û����ɣ������ң���������ֵ�",
                "dodge":                -10,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ʬ����",
                "action":
"$Nһ�С���ʬ���⡹������$w�л��㱣�����ԼԼ���������޵���$n����",
                "dodge":                -50,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������ʩ",
                "action":
"$N����$w���ᣬ���ص�������С�������ʩ������Ʈ�ݣ��ɴ�$n��$l",
                "dodge":                -40,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��;ĩ·",
                "action":
"$N����$w��$n��ͷ���䣬����δ�����ѽ�$n������·��������һ�С���;ĩ·��",
                "dodge":                -40,
                "damage":               20,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "��������",
                "action":
"$Nʹ�����������С���$w��$n���벻���ĵط�ʹ����Ū��$nһʱ�����޴�",
                "dodge":                -40,
                "damage":               30,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "��������",
                "action":
"$N����ͻ��ɷ������������$w������$n$l���䣬��һ�С����������������ֿ��ֺ�",
                "dodge":                -40,
                "damage":               40,
                "damage_type":  "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취ѧ�޳��ȷ�������������������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("���������һ�����Ȳ���ѧ�޳��ȷ���\n");

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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return
notify_fail("�����������������û�а취��ϰ�޳��ȷ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���޳��ȷ���\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

