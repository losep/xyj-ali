// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// fonxanforce.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
   return notify_fail("��ɽ���ڹ�\ֻ����ѧ�Ļ��Ǵ�����(exert)�����������ȡ�\n");
