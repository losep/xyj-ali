// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit FORCE;

string name() { return "��Ȫ��"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return CLASS_D("fighter") + "/lengquan-force/" + func;
}

