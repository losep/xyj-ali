inherit ROOM;

void create()
{
    set("short", "ɽ��");
    set("long", @LONG

���������Ļ���ɽһ·������ֻ�е������һ��һľ������
��Ŀһ�¡��ɴˣ���ɽ��·ͨ��һ���ٲ��������ǻ���ɽ��
�����ǵĽо����������Ǵ�����ȥ����ʱ������׳�ĺŽ�����
LONG );

    set("exits", ([
        "east"   : __DIR__"fall",
        "west"   : __DIR__"playground",
        "southdown"   : __DIR__"shanlu2",
    ]));

    set("objects", ([
        __DIR__"npc/ba-jiangjun" : 1,
        __DIR__"npc/maque" : 1,
    ]));

    set("outdoors", __DIR__);
    setup();
}
