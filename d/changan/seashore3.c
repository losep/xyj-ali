// ALi by NewX

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����֮��");
    set("long", @LONG

��ǰ���Ƕ�����ãã���������߼ʡ������ϲ�����ӿ������
�ߵ���ͷ����˷�������Ҫ����һ�и��ڵ����ϵĶ�������ֻ
�����ź������ߣ�ϣ�����ҳ�һ����·����
LONG);

    set("outdoors", 1);
    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"seashore2",
        "south" : __DIR__"eastseashore",
    ]));

    setup();
}
