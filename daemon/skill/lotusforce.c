// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// lotusforce.c

inherit FORCE;

string name() { return "��̨�ķ�"; }

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1;}

string exert_function_file(string func)
{
    return CLASS_D("bonze") + "/lotusforce/" + func;
}

