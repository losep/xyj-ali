// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tao
inherit SPELLS;

string name() { return "���ڵ���"; }

int query_basic_limit() { return 20; }

int override_basic_level() { return 1; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
    return CLASS_D("puti") + "/tao/" + spell;
}

