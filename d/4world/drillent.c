
inherit ROOM;

void create()
{
    set("short", "���䳡���");
#if 1
    set("long", @LONG

�ڰ��������䳡����ڣ�һ����ӰҲû�У������˶��������롣
LONG
    );
#else
    set("long", @LONG

�ڰ��������䳡����ڣ�վ���ż�������Ľ�����ͷ��
������������治ʱ������׳�ĺŽ�����
LONG
    );
#endif

    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"drill",
        "west"  : __DIR__"northgate",
    ]));
    set("outdoors", __DIR__);


    setup();
}
