inherit ROOM;

void create()
{
    set("short", "�ٲ���");
    set("long", @LONG

�������ƺ�ʲôҲ���������ֻ�������ܽ�ˮ����������
̽��ǰ���ĳ�·����

LONG);

    set("exits", ([
    ]));

    set("objects", ([
        __DIR__"npc/jing" : 2,
    ]));

    setup();
}

void init ()
{
    add_action("do_go", "go");
}

int do_go(string dir)
{
    object who = this_player();
    string *names = ({"west","east","south","north"});

    if (!dir) return 0;

    if (who->query("kee") <= 50) {
        who->unconcious();
        return 1;
    }

    who->receive_damage("kee", 50);
    if (random(5))
        message_vision("$N���Ժ���̤��һ����һ��С��ˤ���ڵء�\n", who);
    else {
        message_vision ("$N���ٲ����ҵ�һ˿ϸ�죬���˳�ȥ��\n",who);
        if (dir != names[random(sizeof(names))])
            who->move(__DIR__"fall5");
        else
            who->move(__DIR__"fall3");
    }

    return 1;
}
