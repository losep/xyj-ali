
inherit ROOM;

void create()
{
    set("short", "���䳡���");
#if 1
    set("long", @LONG

�����ǰ��������䳡����ڡ�������˵�����Ǿ����صأ������˵�
�ǲ��ܳ���ģ�������Ϊ��������ƽ�վã��䱸�ɳڣ����������
���䳡�Ѿ��ܶ���û��ʹ�ù��ˣ�����������ڸ���û��������
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
