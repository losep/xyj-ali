// dengxian-dafa.c �����ɴ󷨡�
inherit SPELLS;

string name() { return "���ɴ�"; }

int query_basic_limit() { return 10; }

int valid_enable(string usage) { return usage=="spells"; }

string cast_spell_file(string spell)
{
    return CLASS_D("dapeng") + "/dengxian-dafa/" + spell;
}


