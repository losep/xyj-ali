// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//�����β����� dragonstep.c
// cglaem...12/19/96.

inherit SKILL;

string *dodge_msg = ({
            "����$n����һ�Σ���$N������Ử����\n",
            "ֻ��$n����һ�ˣ�����һ�Ű����У�$N��һ�ж�ʱû��Ŀ�ꡣ\n",
            "$nһת��һ�Ű���ð�𣬸�����$N�Ĺ��ơ�\n",
            "$n��������ڵ���һ�㣬����צ���������ڰ�գ��ܿ���$N�Ĺ��ơ�\n",
            "$n�ƺ��е�����������ۿ���Ҫ���С�����$N��ǰ���һ������֪���ľ��˿��ˡ�\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("�����������ѧ���β�����\n");
    return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("����������������β�����\n");
    if ((int)me->query("kee") < 30
    ||   (int)me->query("force") < 3 )
        return notify_fail("��������������������������β�����\n");
    me->receive_damage("kee", 30);
    me->add("force", -3);
    return 1;
}

int help(object me)
{
    write(@HELP
�����β�����
���β���Ϊ����ר�����������岻��ϰ����
HELP);
    return 1;
}
