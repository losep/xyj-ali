// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// moonforce.c  ��̫���ľ���
inherit FORCE;

string name() { return "̫���ľ�"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
    return CLASS_D("moon") + "/moonforce/" + func;
}

