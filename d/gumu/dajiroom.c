// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "�����");
    set ("long", @LONG

槼����޹���
LONG);

    set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"tianjing.c",
    ]));

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/foxqueen.c" : 1,
    ]));

    setup();
}

