// center.c

inherit ROOM;

void create()
{
    set("short", "Ʈ���ɾ�");
    set("long", @LONG

����һ��������翵ĵط��������������ơ���Ҳ��֪���Լ����ںδ���
Ҳ��֪��������ȥ(back)�����������������
LONG);

    set("exits", ([ /* sizeof() == 4 */
        "southeast" : __DIR__"zuixing",
        "northwest" : __DIR__"qilin",
        "northeast" : __DIR__"yingfang",
        "southwest" : __DIR__"gate",
    ]));

  setup();
}

void init()
{
    add_action("do_back", "back");
}

int do_back(string arg)
{
    return 0;
}
