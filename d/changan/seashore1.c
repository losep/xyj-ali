// ALi by NewX

#include <ansi.h>

inherit ROOM;

void create ()
{
    set ("short", "����֮��");
    set ("long", @LONG

��ǰ���Ƕ�����ãã���������߼ʡ������ϲ�����ӿ������
�ߵ���ͷ����˷�������Ҫ����һ�и��ڵ����ϵĶ�������ֻ
�����ź������ߣ�ϣ�����ҳ�һ����·����
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"eside5",
        "south" : __DIR__"seashore2",
    ]));
    set("outdoors", 2);

    setup();
}
