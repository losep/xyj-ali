// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "ʯ��");
    set ("long", @LONG

һ��������ʯ������������ͷ��������һ��С�ң���Լ����һЩ��ֵ�
������
LONG);

    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"shidong4.c",
        "south" : __DIR__"shidong2.c",
        "east" : __DIR__"testroom1.c",
    ]));

  setup();
}

