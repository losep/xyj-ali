// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "ɽ��С·");
    set("long", @LONG

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
    add_action("do_all", "", 1);
}

int do_all(string arg)
{
    if (this_player()->query("obstacle/firemount")=="done")
        set("exits/southeast", __DIR__"nofire");
    else
        set("exits/southeast", __DIR__"huoyan");
    return 0;
}
