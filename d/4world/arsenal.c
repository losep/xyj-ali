
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

�����ǰ������ı����⣬һ��ùζ�˱Ƕ���������ʮ����û���˽�
�����˰ɡ�ż�����������ҵ�һ��������Ҳ���Ѿ��⼣�߰ߡ�
LONG);

    set("exits", ([
        "north"   : __DIR__"drill",
    ]));

    set("no_magic", 1);

    setup();
    replace_program(ROOM);
}
