// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ice-force.c  ��������Ѫ����
inherit FORCE;

string name() { return "������Ѫ��"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
    return notify_fail("������Ѫ��ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
    return CLASS_D("avian") + "/ice-force/" + func;
}

