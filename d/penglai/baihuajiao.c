inherit ROOM;

void create()
{
    set("short", "�ٻ���");
    set("long", @LONG

һ���ܲ�͸���Ҥ����������ǰٻ�������Ƶ������ˡ�

LONG);
    set("exits", ([
        "west" : __DIR__"hongyandong",
    ]));
    set("objects", ([
        __DIR__"obj/baihuaniang" : 1,
    ]));
    setup();
}
