// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "���չ�");
    set("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "south"     : __DIR__"caihongqiao",
        "north"     : __DIR__"guijingong",
        "northwest" : __DIR__"liutugong",
        "northeast"      : __DIR__"jingmugong",
    ]));
    set("objects", ([
        __DIR__"stars/glads" : 1,
    ]));
    setup();
}

