// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ʷ��");
    set("long", @LONG

�����̿ɣ����ھ��ˣ�������м���������յ������ϼ�ϻ�
ӳ��⣬���������ڶ��ڡ�

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "east" : __DIR__"jieyindian",
    ]));
    setup();
}

