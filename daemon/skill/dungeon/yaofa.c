// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dao
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("yaofa") )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ����������\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/yaofa/"+spell;
}

