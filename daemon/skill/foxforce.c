// ALi

// foxforce.c  ������ķ���
inherit FORCE;

string name() { return "����ķ�"; }

int valid_enable(string usage) { return usage=="force"; }

string cast_spell_file(string spell)
{
    return CLASS_D("fox") + "/foxforce/" + spell;
}

