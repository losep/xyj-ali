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
        "north" : __DIR__"dadao3",
        "south" : __DIR__"dadao1",
    ]));

    set("outdoors", 1);
    setup();
}

