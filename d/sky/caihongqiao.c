// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ʺ���");
    set("long", @LONG

���м������ţ����Ͽ��ż�����ɫ�ʺ硣����������ʮ�����칬��
��ǲ�ƹ�����ɳ������������̫��������ҩ��������һ��������
�����ޣ�������ʮ���ر���˳���������������
���ٵ���� һ������������롣

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "south" : __DIR__"jieyindian",
        "north" : __DIR__"xingrigong",
    ]));
    setup();
}

