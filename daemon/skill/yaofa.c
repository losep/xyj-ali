// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yaofa
inherit SPELLS;

string name() { return "����"; }

int is_exclusive() { return 1; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
        return CLASS_D("yushu") + "/yaofa/"+spell;
}


