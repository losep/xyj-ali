
inherit ROOM;

void create()
{
    set("short", "���䳡");
    set("long", @LONG

�����ǰ��������䳡���ô�һƬ�յأ�һ����Ҳû�С��㲻������
һ��������ĳ嶯�������뵽����Ͼ����˼ҹ��ҵ����䳡������
�㻹����ס�ˡ�
LONG);

    set("exits", ([
        "north"   : __DIR__"drillent",
        "south"   : __DIR__"arsenal",
    ]));

    set("outdoors", __DIR__);

    setup();
    replace_program(ROOM);
}
