// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rootshentong.c ���������󷨡�
// ��Ԫ�ӵı�����ͨ������������������

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    return notify_fail("��û���������ı��ʣ��޷��������������󷨡���\n");
}

string cast_spell_file(string spell)
{
    return CLASS_D("zhenyuan") + "/rootshentong/" + spell;
}

int help(object me)
{
    write(@HELP
���������󷨡�
��Ԫ�ӵı�����ͨ������������������

�����ⷨ�š�
��  Ǭ�����䣺      cast qiankun
HELP);
    return 1;
}
