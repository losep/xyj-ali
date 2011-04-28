inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
    object ob;

    if (!arg) {
        ob = me;
    } else if (wizardp(me)) {
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) ob = LOGIN_D->find_body(arg);
        if (!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
    } else
       return 0;

    write(QUEST_D->check_quests_detail(ob, me));

    return 1;
}

int help()
{
    write(@TEXT
ָ���ʽ��quests <ĳ��>

��ʾĳ�˵Ľ��ռ�¼�� 

�����help jiemi
TEXT
    );
    return 1;
}


