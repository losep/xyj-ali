// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
   if( (int)me->query("bellicosity") > 100 )
     return notify_fail("���ɱ��̫�أ��޷�������ʦ������\n");
   return 1;
}

int practice_skill(object me)
{   
   return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}
