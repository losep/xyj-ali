// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

�����̿ɣ����ھ��ˣ�������м������������ϲ����Ž���ҫ�ճ�������
�������ݣ����ƷǷ���
LONG);

    set("exits", ([ /* sizeof() == 3 */
        "west" : __DIR__"jieyindian",
    ]));
    setup();
}

