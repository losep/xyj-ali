// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

���������ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�������м������������ϲ����Ž���ҫ�ճ���
����һ�����������������������죬�������߸���һ����
Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ���������֮������
���˲��١�

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "south" : __DIR__"nantian",
        "north" : __DIR__"caihongqiao",
        "west" : __DIR__"caifengdian",
        "east" : __DIR__"jinlongdian",
    ]));

    create_door("south", "������", "north", DOOR_CLOSED);
    setup();
}

