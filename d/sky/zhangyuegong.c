// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "���¹�");
    set("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "south"     : __DIR__"guijingong",
        "north"     : __DIR__"zhuquedian",
        "southwest" : __DIR__"yihuogong",
        "southeast" : __DIR__"zhenshuigong",
    ]));
    set("objects", ([
        __DIR__"stars/lady" : 1,
    ]));
    setup();
}

