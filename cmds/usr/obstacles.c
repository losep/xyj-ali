inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
    object ob;
    string opt;

    if (!arg || arg == "-qujing") {
        ob = me;
        opt = "qujing";
    } else if (arg == "-dntg") {
        ob = me;
        opt = "dntg";
    } else if (wizardp(me)) {
        if (sscanf(arg, "-dntg %s", arg))
            opt = "dntg";
        else if (sscanf(arg, "-qujing %s", arg))
            opt = "qujing";
        else
            opt = "qujing";
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) ob = LOGIN_D->find_body(arg);
        if (!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
    } else
        return 0;

    write(OBSTACLES_D->check_obstacles_long(ob, 0, ob != me, opt));

    return 1;
}

int help()
{
    write(@TEXT
ָ���ʽ��obstacles [-dntg] <ĳ��>

��ʾĳ�˵Ĺ��ؼ�¼��
Ĭ����ʾ������ȡ�澭�ļ�¼����[-dntg]��������ʾ�����칬�ļ�¼��

�����help qujing
TEXT
    );
    return 1;
}

