// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// baguazhou
inherit SKILL;

string name() { return "������"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20
        ||      (int)me->query_skill("spells") <= (int)me->query_skill("baguazhou") )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰ�����䣮\n");
        return 1;
}

string scribe_spell_file(string spell)
{
    return CLASS_D("fighter") + "/baguazhou/" + spell;
}
