//sgzl
inherit ROOM;

void create()
{
    set("short", "ѩ��");
    set("long", @LONG

�����Ʈ���ѩ����ס��������ߣ�ֻ����������ǰ�����һ��
СС��֩����(net)��
LONG);

    set("item_desc", ([
        "net" : "һ��֩������\n", 
    ]));

    set("exits", ([ //sizeof() == 2
        "south" : __DIR__"no4-w1",
        "west" : __DIR__"no4-wn2",
    ]));

    set("outdoors", "xueshan");

    setup();
}

void init()
{
    remove_call_out("check_hudie");
    call_out("check_hudie", 5);
}

void check_hudie()
{
    object where = this_object();
    object hudie;

    if (hudie = present("hu die", where)) {
        remove_call_out("catch_hudie");
        call_out("catch_hudie",3);
    }
    remove_call_out("check_hudie");
    call_out("check_hudie", 5);
}

void catch_hudie()
{
    object where = this_object();
    object hudie;

    if (hudie = present("hu die", where)) {
        message_vision("$N��һ�ɾ޴�����������֩������\n", hudie);
        hudie->move(__DIR__"zhuwang");
        message_vision("$N�����˽�����\n", hudie);
    }
}
