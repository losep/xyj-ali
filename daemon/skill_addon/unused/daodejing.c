// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//daodejin.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷��������¾���\n");
        return 1;
}

