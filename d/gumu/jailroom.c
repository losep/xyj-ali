// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "����");
    set("long", @LONG

��ڵĵ��Σ�������������ŨŨ��Ů��������ζ�����е�����Ѫ��
ζ����Χ�����˸��ֲֿ���SM���ߣ�ľ��Ƥ�ޡ�����������Щ
�����϶�����������Ѫ����
LONG);

    set("exits", ([ /* sizeof() == 1 */
        "up" : __DIR__"dajiroom",
    ]));

    set("objects", ([ /* sizeof() == 1 */
        "/d/moon/npc/xiwangmu" : 1,
    ]));

    setup();
}

