// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// seashentong.c ���̺���ͨ��
inherit SPELLS;

string name() { return "�̺���ͨ"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("�����������ѧ�̺���ͨ��\n");
    return ::valid_learn(me);
}

string cast_spell_file(string spell)
{
    return CLASS_D("dragon") + "/seashentong/" + spell;
}

