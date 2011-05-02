// Room: /d/hgs/inner.c
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ڰ���");
    set("long", @LONG

������ɽ���е�һ���ܶ�������һƬ�ڰ���ʯ��(gap)����ϡ���Կ���
ʲô�����ں����ġ�
LONG
    );
    set("item_desc", ([
        "gap" : "ʯ���ƺ���������(expand)������������ȡ���Ǽ�������\n",
    ]));
    set("exits", ([]));

    setup();
}

void init()
{
    add_action("do_expand", "expand");
}

int do_expand(string arg)
{
    object me = this_player();
    object ob; 

    if (!arg || (arg != "gap" && arg != "ʯ��"))
        return notify_fail("��Ҫ�ǿ�ʲô��\n");
    if (!(ob = me->query_temp("weapon")))
        return notify_fail("û�й�����ô�ɻ\n");
    if (me->query_str() < 50)
        return notify_fail("�������������\n");

    if (me->query("kee") < 200) {
        message_vision(HIR "\nֻ���ú��һ����һ���ʯ��������������$N�����˹�ȥ��\n\n" NOR, me);
        me->unconcious();
    } else {
        me->receive_damage("kee", 200);
        message("vission", HIR "\nֻ���ú��һ����һ���ʯ������������\n\n" NOR, environment(me));
    }

    if ("/d/dntg/helper"->in_mud()) {
        message("vission", HIR "�㿴��ʯ��֮�пտ���Ҳ��\n" NOR, me);
        return 1;
    }

    ob = new("/d/dntg/helper");
    ob->move(environment(me));
    message("vission", HIR "�㿴��ʯ��֮��¶��һ�ѽ𹿰���\n" NOR, me);
    return 1;
}

void open_door()
{
    object room;

    if (!query("exits/up")) {
        if (!(room = find_object(__DIR__"entrance")))
            room = load_object(__DIR__"entrance");
        if (room = find_object(__DIR__"entrance")) {
            message("vision", "��ʯ��Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",
                this_object());
            set("exits/up", __DIR__"entrance");
            room->set("exits/down", __FILE__);
            message("vision", "��ʯ��Ȼ����������������¶��һ�����µĽ��ݡ�\n",
                room);

            call_out((: call_other,  __DIR__"entrance", "close_passage" :), 10);
        }
    }
}
