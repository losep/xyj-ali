// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "�ݾ�");
    set ("long", @LONG

�����ƺ���һ���ݾ���̧ͷ��ȥ�����Կ���һСƬ��ա�
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"dajiroom.c",
        "south" : __DIR__"shidong4.c",
    ]));

    set("outdoor", "xuanyuan");
    set("valid_startroom", 1);
    setup();
}

