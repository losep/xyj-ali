// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tao
inherit SKILL;

string name() { return "���ڵ���"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("spells", 1) < 20)
        return notify_fail("���ɵ����ǳ�������ķ�����Ϊ���������\n");
    return 1;
}

string cast_spell_file(string spell)
{
    return CLASS_D("puti") + "/tao/" + spell;
}

