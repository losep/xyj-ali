
inherit ROOM;

void create()
{
    set("short", "����Ҷ��");
    set("long", @LONG
���ܻ���������֦Ҷ��ï��ȴ�ѿ������ء�
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "up" : __DIR__"tree2",
        "down" : __DIR__"ontop2",
    ]));

    set("objects", ([
        "/d/obj/flower/guihua.c" : 2,
    ]));

    setup();
}






