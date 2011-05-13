
// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object ob;
    string *skname;
    mapping skills;
    int i;

    if (!arg || !ob = present(arg, environment(me)))
        return notify_fail("��Ҫ��˭���ʦ�ţ�\n");
    if (!ob->is_character())
        return notify_fail("��Ҫ���˭����\n");
    if (!userp(ob))
        return notify_fail("��ֻ�ܿ�����������ݵ����\n");

    if (!me->expell_apprentice(ob)) return 0;

    ob->save();
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : expell <ĳ��>

���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������뿪������£�����
����������ɣ�������㴫Ͷ��������ʦ����

HELP
    );
    return 1;
}
