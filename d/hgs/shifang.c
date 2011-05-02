
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

    create_door("west", "ʯ��", "east", DOOR_CLOSED);
    setup();
}

void init()
{
    add_action("do_bed", ({"bed","gobed","gosleep"}));
}

int do_bed()
{
    object me = this_player();
    message_vision("$N��ʯ����һ�ɣ�׼��˯���ˡ�\n\n", me);
    me->move(__DIR__"shichuang");
    message_vision("\n$N�굽�˱����\n", me);
    return 1;
}

void start_call_out(string func, int time, string arg)
{
    call_out(func, time, arg);
}
