// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// seashentong.c ���̺���ͨ��
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if (me->query("class") != "dragon")
        return notify_fail("�����������ѧ�̺���ͨ��\n");
    if ((int)me->query_skill("spells", 1) < 10
    || (int)me->query_skill("spells", 1) <=
            (int)me->query_skill("seashentong", 1))
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ�̺���ͨ��\n");
    return 1;
}

string cast_spell_file(string spell)
{
    return CLASS_D("dragon") + "/seashentong/" + spell;
}

int help(object me)
{
    write(@HELP
���̺���ͨ��
�̺���ͨΪ����ר�������������岻��ϰ����

��  ���񻤷���    cast hufa
��  ѩ����飺    cast freez
HELP);
    return 1;
}
