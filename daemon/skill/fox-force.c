// ALI

// fox-force.c  ������ķ���
inherit FORCE;

string name() { return "����ķ�"; }

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
    return
        notify_fail("����ķ�ֻ����ʦ��ѧ�����Ǵ�����(exert/cast)�����������ȡ�\n");
}

string cast_spell_file(string spell)
{
    return CLASS_D("gumu") + "/fox-force/" + spell;
}

