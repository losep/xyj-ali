// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// force.c

#include <ansi.h>

inherit SKILL;

string name() { return "�ڹ��ķ�"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/daemon/class/force/" + func;
}


