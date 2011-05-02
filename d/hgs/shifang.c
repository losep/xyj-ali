
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "ʯ��");
    set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ����
ʯ�ʣ����ּҵ�����һ���������İ���֮�������м����
һ�˴���(flag)�����滹��һ��ʯ��(bed)��
LONG
    );

    set("item_desc", ([
        "flag":"һ��ӭ����չ����ɫ���죬�ڿտ�֮��ӭ�����(wave)����һ��ɷ�Ǻÿ������ƺ����Ѱ�(ba)����\n",
        "bed": "һ��ʯ��(gosleep,gobed,bed)�� \n", 
    ]));

    set("exits", ([
        "west"   : __DIR__"ironbridge",
        "east"  : __DIR__"dongnei",
    ]));

    create_door("west", "ʯ��", "east", DOOR_CLOSED);
    setup();
}

void init()
{
    object me = this_player();
    object houzi;
    object where = this_object();

    if (me->query("dntg/huaguo")=="allow") {
        message_vision("һȺ���Ӹ���$N�ı����������˹�����\n", me);
        if (!present("hou zi 3", where)) {
            houzi = new(__DIR__"npc/hou-ok");
            houzi->move(where);
        }
    }
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
