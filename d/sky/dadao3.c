// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�칬���");
    set("long", @LONG

һ���������ֱ����չ��ȥ��ֱͨ�����š����ϲ�ʱ�߹�����
Ѳ���������ֵ��������������ݡ�

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"dadao4",
        "south" : __DIR__"dadao2",
    ]));

    set("outdoors", 1);
    setup();
}

