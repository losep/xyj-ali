// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// taiyi.c ��̫���ɷ���
inherit SPELLS;

string name() { return "̫���ɷ�"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
    return CLASS_D("daxian") + "/taiyi/" + spell;
}
