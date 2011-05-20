
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "ʯ��");
    set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ��(bed)��
ʯ�ʣ����ּҵ�������ȫ����һ���������İ���֮�������м����
һ�˴���(flag)��
LONG
    );

    set("item_desc", ([
        "flag": "һ��ӭ����չ����ɫ���죬�ڿտ�֮��ӭ�����(wave)����һ��ɷ�Ǻÿ������ƺ����Ѱ�(ba)����\n",
        "bed": "һ��ʯ��(gosleep,gobed,bed)��\n", 
    ]));

    set("exits", ([
        "west"   : __DIR__"ironbridge",
        "east"  : __DIR__"throne",
    ]));
    set("no_clean_up", 1);
    set("have_flag", 1);

    create_door("west", "ʯ��", "east", DOOR_CLOSED);
    setup();
}

void init()
{
    add_action("do_bed", ({"bed","gobed","gosleep"}));
    add_action("do_ba", "ba");
}

int do_bed()
{
    object me = this_player();
    message_vision("$N��ʯ����һ�ɣ�׼��˯���ˡ�\n\n", me);
    me->move(__DIR__"shichuang");
    message_vision("\n$N�굽�˱����\n", me);
    return 1;
}

int do_ba(string arg)
{
    if (query("have_flag")) {
        if (!arg || arg != "flag")
            return notify_fail("��Ҫ��ʲô��\n");

        return notify_fail("��ʹ�����̵�����Ҳû������γ�����\n", me);
    }
    return 0;
}

void reset_flag_desc(int have_flag)
{
    if (!have_flag) {
        set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ��(bed)��
ʯ�ʣ����ּҵ�������ȫ����һ���������İ���֮����
LONG);
        delete("item_desc/flag");
        set("have_flag", 0);
    } else {
        set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ��(bed)��
ʯ�ʣ����ּҵ�������ȫ����һ���������İ���֮�������м����
һ�˴���(flag)��
LONG);
        set("item_desc/flag",
            "һ��ӭ����չ����ɫ���죬�ڿտ�֮��ӭ�����(wave)����һ��ɷ�Ǻÿ������ƺ����Ѱ�(ba)����\n");
        set("have_flag", 1);
    }
}

void start_call_out(string func, int time, string arg)
{
    call_out(func, time, arg);
}
