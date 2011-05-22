
inherit ROOM;

void setup()
{
    string *ways;
    
    set("short", "�����Թ�");
    set("long", @LONG

��ˮ�ֱ���峺�ˣ������Ѿ������ҵ������ˡ�
���ܵľ������һ����Ҫ��û����·�Ļ�����
���ѳ�ȥ�ˡ�
LONG );

    ways = query("ways");
    if (!query("exits/east")) set("exits/east", ways[random(sizeof(ways))]);
    if (!query("exits/west")) set("exits/west", ways[random(sizeof(ways))]);
    if (!query("exits/north")) set("exits/north", ways[random(sizeof(ways))]);
    if (!query("exits/south")) set("exits/south", ways[random(sizeof(ways))]);

    if (!query("objects")) {
        set("objects", ([
            __DIR__"xiaoyu" : 1,
        ]));
    }

    ::setup();
}

void init()
{
    if (this_player()->query("id") == "xiao hong yu"
    ||  this_player()->query("id") == "xiao qing yu"
    ||  this_player()->query("id") == "xiao lan yu"
    ||  this_player()->query("id") == "xiao bai yu"
    ||  this_player()->query("id") == "xiao hua yu"
    ||  this_player()->query("id") == "xiao jin yu"
    )
        message_vision("$N���˹�����\n", this_player());
}

int valid_leave(object me, string dir)
{
    if (this_player()->query("id") == "xiao hong yu"
    ||  this_player()->query("id") == "xiao qing yu"
    ||  this_player()->query("id") == "xiao lan yu"
    ||  this_player()->query("id") == "xiao bai yu"
    ||  this_player()->query("id") == "xiao hua yu"
    ||  this_player()->query("id") == "xiao jin yu"
    )
        message_vision("$N����β�������ˡ�\n", this_player());
    return ::valid_leave(me, dir);
}
