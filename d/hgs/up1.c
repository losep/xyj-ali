// Room: /4world/up1
inherit ROOM;

void create()
{
    set("short", "�ּ�С·");
    set("long", @LONG

����ɽ�е�һ���ּ�С·��������پ��ᣬ��ľ���죬����
���У�ֻ��һЩ���������䵴����ȥ������ɽɽ����ΰ����
�վ�����ɽ�����߲���������
LONG);

    set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/monkey2" : 1,
        __DIR__"npc/monkey1" : 1,
    ]));
    set("outdoors", __DIR__);
    set("exits", ([ /* sizeof() == 3 */
        "eastup" : __DIR__"up2",
        "southdown" : __DIR__"flowerfruit",
        "northup" : __DIR__"shanlu1",
    ]));

    setup();
}