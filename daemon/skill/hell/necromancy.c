// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ������

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("spells", 1) < 10
    ||  (int)me->query_skill("spells", 1) <= (int)me->query_skill("necromancy", 1) )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��������\n");
    return 1;
}

string cast_spell_file(string spell)
{
    return CLASS_D("ghost") + "/necromancy/" + spell;
}

int help(object me)
{
    write(@HELP
����������
���������������ܡ����꣬�����ܡ���꡻��

С���꣺cast gouhun
��ڤ���죺cast miwu
HELP);
    return 1;
}