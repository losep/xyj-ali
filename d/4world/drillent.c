
inherit ROOM;

void create()
{
    set("short", "���䳡���");
    set("long", @LONG

�ڰ��������䳡����ڣ�վ���ż�������Ľ�����ͷ��
������������治ʱ������׳�ĺŽ�����
LONG
    );

    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"drill",
        "west"  : __DIR__"northgate",
    ]));
    set("out_doors", __DIR__);
    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/jiaotou" : 2,
    ]));

    setup();
}
