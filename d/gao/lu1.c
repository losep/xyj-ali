// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "�ľ�С·");
    set ("long", @LONG

·���˲��Ǻܶ࣬ż���м������ͣ�ǰ����һ��С��������
һ�������˼ң�ȴ���ⷽԲ�������ص����ˣ�������ũ����
�ǿ���߼ҵ�����գ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"lu2",
        "east" : "/d/changan/wside5",
    ]));
    set("outdoors", 1);

    setup();
}
