// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// zhenyuan-force.c  ����Ԫ�񹦡�
inherit FORCE;

string name() { return "��Ԫ��"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{
    if ((int)me->query_skill("force", 1) < 10)
//     || (int)me->query_skill("force", 1) <= (int)me->query_skill("zhenyuan-force", 1) )
        return notify_fail("����ڹ���Ϊ����������޷�ѧϰ��Ԫ�񹦡�\n");
    return 1;
}

string exert_function_file(string func)
{
    return CLASS_D("daxian") + "/zhenyuan-force/" + func;
}

