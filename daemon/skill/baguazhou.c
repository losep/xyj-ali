// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// baguazhou
inherit SPELLS;

string name() { return "������"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

string scribe_spell_file(string spell)
{
    return CLASS_D("fighter") + "/baguazhou/" + spell;
}
