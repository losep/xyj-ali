// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//fabao-road1.c
inherit ROOM;

void create ()
{
    set ("short", "��ʯ·");
    set ("long", @LONG

һ�����ѵ�С·�������ȥ�����������˸������ι�״�Ĳ���
��ʯ��������һЩ����ɫ�ʰ�쵣���֪�ǴӺζ�����
LONG);

    set("exits", 
    ([ //sizeof() == 2
        "west" : __DIR__"kunlun",
        "east" : __DIR__"fabao-road2",
    ]));

    set("outdoors", "1");

    setup();
}

