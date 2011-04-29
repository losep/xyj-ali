inherit ROOM;

void create()
{
    set("short", "ɽ·");
    set("long", @LONG

һ����������ɽ·���Ĵ�������������Ӣ�ͷס���Χ������
��ż��ߥ����ֻ���ӣ�������������ȥ��·�ߵ�С��(grass)
���Ʈ�衣
LONG
    );

    set("item_desc",([
        "grass":"һЩ�����͵�С�ݣ���(ba)����������\n"
    ]));

    set("exits", ([
        "west"   : __DIR__"xiaoxiqian",
        "northup"   : __DIR__"shanya",
        "southdown"   : __DIR__"shanlu1",
    ]));
    set("outdoors", __DIR__);
    set("grass_number", 5);
    setup();
}

void init()
{
    add_action("do_ba", "ba");
}

void reset()
{
    ::reset();
    set("grass_number", 5);
}

int do_ba(string arg)
{
   object me = this_player();
    object cao;

    if (!arg || arg != "grass")
        return notify_fail("��Ҫ��ʲô��\n");
    else if (query("grass_number") == 0)
        return notify_fail("���Ѿ����ι��ˣ���Ѿ��ˡ�\n");
    else if (me->query("kee") < 10)
        me->unconcious();
    else {
        me->receive_damage("kee", 10);
        cao = new (__DIR__"obj/grass");
        cao->move(me);
        message_vision("$N����һ��С�ݡ�\n", me);
        add("grass_number", -1);
    }
    return 1;
}

