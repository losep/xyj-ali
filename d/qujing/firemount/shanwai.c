// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "ɽ��С·");
    set ("long", @LONG

��ͻȻ���˻���ɽ�������棬�������Ǻ�ͨͨ�Ļ���ɽ����������
��һ��ǿ�ҵĺ�ζ���ȵ������������ܡ�������һ��С����ͨ��ɽ
����������

LONG);

    set("exits", ([
        "northdown"  : __DIR__"hongyan",
        "southeast"  : __DIR__"huoyan",
        ]));
    set("outdoors", "firemount");

    setup();
}

void init()
{
    add_action("do_look", "look");
    add_action("do_se", "go");
    add_action("do_se", "southeast");
}

int do_look(string arg)
{
    if (arg=="southeast") {
    if (this_player()->query("obstacle/firemount")=="done")
        set("exits/southeast", __DIR__"nofire");
    else
        set("exits/southeast", __DIR__"huoyan");
    }
    return this_player()->force_me("look "+arg);
}

int do_se(string arg)
{
    object me = this_player();
    string verb = query_verb();
    if ((verb == "go" && arg == "southeast") || verb == "southeast") {
        if (me->query("obstacle/firemount")!="done") {
            set("exits/southeast", __DIR__"huoyan");
            me->set_temp("burnt_in_mount",0);
            me->set_temp("fanned_in_mount",0);
            me->set_temp("fan_times_in_mount",0);
        }
        else {
            set("exits/southeast", __DIR__"nofire");
        }
    }
    return 0;
}
