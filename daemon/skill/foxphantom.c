// ALi

// foxphantom.c  ��ǧ���������
inherit SPELLS;

string name() { return "ǧ�������"; }

int valid_enable(string usage) { return usage=="force"; }

string cast_spell_file(string spell)
{
    return CLASS_D("fox") + "/foxphantom/" + spell;
}

