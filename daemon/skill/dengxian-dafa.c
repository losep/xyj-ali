// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dengxian-dafa.c �����ɴ󷨡�
inherit SKILL;

string name() { return "���ɴ�"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("dengxian-dafa", 1) )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰ���ɴ󷨡�\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/dengxian-dafa/" + spell;
}


