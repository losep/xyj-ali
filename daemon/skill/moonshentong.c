// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// moonshentong.c ��̫���ɾ���
inherit SPELLS;

string name() { return "̫���ɾ�"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
    return CLASS_D("moon") + "/moonshentong/" + spell;
}

