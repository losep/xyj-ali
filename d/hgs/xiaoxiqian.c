inherit ROOM;

void create()
{
    set("short", "СϪǰ");
    set("long", @LONG

����ɽ·һת��һ���峺��СϪ�����������ǰ��
���õ�������ҫ�£�СϪ�в�����������ʱ����
�����������ˮ�棬ʹ�����뵽Ϫ����(swim)һ
����
LONG );

    set("exits", ([
        "east"   : __DIR__"shanlu2",
    ]));

    set("objects", ([
        __DIR__"npc/cihu"   : 1,
        __DIR__"npc/huabao"   : 1,
    ]));

    set("outdoors", __DIR__);
    setup();
}

void init()
{
    add_action("do_swim", "swim");
}

int do_swim()
{
    object me = this_player();

    message_vision("$N����Ծ��СϪ��\n", me);
    me->move(__DIR__"xiaoxi");
    tell_object(this_object(), "ֻ��СϪ��ˮ���Ľ�������С������������\n");
    return 1;
}

