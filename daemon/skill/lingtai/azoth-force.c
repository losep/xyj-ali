// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// azoth-force.c
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
    return notify_fail("�𵤴��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
    return CLASS_D("puti") + "/azoth-force/" + func;
}

int help(object me)
{
    write(@HELP
����ת������
��ת�������˵�����������֮���������֮�컯���������

��Ӧ�÷��š�
�� ����    exert heal
HELP);
    return 1;
}