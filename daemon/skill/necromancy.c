// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ������

inherit SPELLS;

string name() { return "������"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
    return CLASS_D("ghost") + "/necromancy/" + spell;
}
