// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "ʯ��");
    set("long", @LONG

һ��������ʯ������������ͷ��
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"shidong3",
        "south" : __DIR__"shidong1",
    ]));

  setup();
}

