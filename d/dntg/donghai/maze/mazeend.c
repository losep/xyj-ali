
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
    
�յ����ĺ�����ֱ����һ�������ӣ��������
�յ����������ۡ�
LONG );

    set("exits", ([
        "up"    : "/d/changan/eastseashore",
    ]));

    setup();
}

void init()
{
    object helper = this_player()->query_temp("dntg_helper");
    if (helper) helper->make_shentie();
}
