// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// taoism
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("spells", 1) < 20)
        return notify_fail("���ɵ����ǳ�������ķ�����Ϊ���������\n");
    return 1;
}

string cast_spell_file(string spell)
{
    return CLASS_D("puti") + "/taoism/" + spell;
}

int help(object me)
{
    write(@HELP
������
���ɵ����ǳ�����
̫��������ǧ�Դ�����������ʦ����֮�����Դ�Ϊ������

�����⹥����
��  ������       cast thunder on <object>
��  �����       cast light on <object>
��  ������       cast fenshen
��  ����       cast dingshen on <object>
��  �������     cast invocation
HELP);
    return 1;
}