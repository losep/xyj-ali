// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// buddhism.c

inherit SPELLS;

string name() { return "��˷�"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if ((int)me->query("bellicosity") > 100)
        return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
    return ::valid_learn(me);
}

string cast_spell_file(string spell)
{
    return CLASS_D("bonze") + "/buddhism/" + spell;
}

