//sgzl
inherit ROOM;

void create()
{
    set("short", "ѩ��");
    set("long", @LONG

ѩ�����м�����ѩ���˷����ˣ���֪��(mai)��ʲô������ȥ��
��˵�⸽���а�������û������ҪС��Щ��
LONG);

    set("exits", ([ //sizeof() == 2
        "east" : __DIR__"no4-w1",
        "north" : __DIR__"no4-wn2",
    ]));

    set("have_ji",0);

    set("outdoors", "xueshan");

    setup();
}

void init()
{
    add_action("do_mai", "mai");
}

int do_mai(string arg)
{
    object me = this_object();
    object who = this_player();
    object ji;

    if (!arg && arg != "gong ji"  && arg != "ji")
        return notify_fail("��Ҫ��ʲô��\n");
    if(!(ji = present(arg, who)))
        return notify_fail("������û���ⶫ����\n");
    if (me->query("have_ji"))
        return notify_fail("���Ѿ�����һ������߰���Ķ����ˣ�������Ⱦѩɽ�ķ羰�ˡ�\n");

    me->set("have_ji", 1);
    message_vision("$N��һֻ���������ѩ�\n",who);
    destruct(ji);
    call_out("wugong",10+random(10),who);
    return 1;
}

void wugong(object who)
{
    object wugong;
    message_vision("һֻ������������˹�����\n",who);
    wugong = new(__DIR__"npc/wugong");
    wugong->move(this_object());
}
