// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }


int valid_learn(object me)
{
   if( (int)me->query_skill("buddhism") <= (int)me->query_skill("chanting") )
     return notify_fail("��Ĵ�˷���Ϊ����������޷�ѧϰ�о���\n");
   if( (int)me->query("bellicosity") > 100 )
     return notify_fail("���ɱ��̫�أ��޷������о���\n");
   return 1;
}





