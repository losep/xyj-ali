// ALI

// fox-force.c  ������ķ���
inherit FORCE;

string name() { return "����ķ�"; }

int valid_enable(string usage) { return usage=="force" || usage=="spells" || usage=="magic"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("spells") <= (int)me->query_skill("fox-dao"))
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ�������\n");
    return 1;
}

int practice_skill(object me)
{
    return
        notify_fail("����ķ�ֻ����ʦ��ѧ�����Ǵ�����(exert/cast)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return CLASS_D("gumu") + "/fox-force/" + func;
}

string cast_spell_file(string spell)
{
    return CLASS_D("gumu") + "/fox-force/" + spell;
}

