// spells.c

inherit SKILL;

int valid_learn(object me)
{
    mapping skills;
    object skill;
    string *names, name;
    int i, basic_level, limit_level;
    
    basic_level = me->query_skill("spells", 1);
    limit_level = this_object()->query_basic_limit();
    if (basic_level < limit_level)
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��" + this_object()->name() + "����\n");

    if (mapp(skills = me->query_skills())) {
        names = keys(skills);
        for (i = 0; i < sizeof(names); i++) {
            name = names[i];
            if (!skill = find_object(SKILL_D(name)))
                skill = load_object(SKILL_D(name));
            skill = find_object(SKILL_D(name));
            if (skill == this_object()) {
                if (!this_object()->override_basic_level() && basic_level <= skills[name])
                    return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��" + this_object()->name() + "����\n");
            }
            else if (wizardp(me) && skill->valid_enable("spells")) {
                if (this_object()->is_exclusive())
                    return notify_fail("����ͼ��ϰ" + this_object()->name()
                            + "ȴ�о������Ť���������Ϊ���������Ĵ��ڸ�����" + this_object()->name() + "��������\n");
                if (skill->is_exclusive())
                    return notify_fail("����ͼ��ϰ" + this_object()->name()
                            + "ȴ�о������Ť���������Ϊ" + skill->name() + "�Ĵ��ڸ���������������������\n");
            }
        }
    }
    return 1;
}

int practice_skill(object me)
{
    return notify_fail(this_object()->name() + "ֻ����ѧ�ģ����Ǵ�����(cast)�����������ȡ�\n");
}
