// ALi by NewX

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "ѩ����");
    set("long", @LONG

������һƬСƽ̨��ѩɽ����ƽ����ӵĴ������������������
������Ϣ�ң��������ǳ��������ϻ��˺���ѩ��������ѩɽ����
ȴ�Ӳ��е��Ϻ���
LONG);

    set("exits", ([ //sizeof() == 4
        "north" : __DIR__"xuejie-2",
        "sorth" : __DIR__"xuelu",
        "west" : __DIR__"restroom",
        "east" : __DIR__"chufang",
    ]));
    
    set("objects", ([
        __DIR__"obj/rack" : 1,
    ]));

    set("outdoors", "xueshan");

    create_door("east", "������", "west", DOOR_CLOSED);
    set("no_clean_up", 0);

    setup();
}



