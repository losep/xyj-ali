// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//fabao-road2.c
inherit ROOM;

void create ()
{
    set ("short", "��ʯ·");
    set ("long", @LONG

һ�����ѵ�С·�������ȥ�����������˸������ι�״�Ĳ���
��ʯ��������һЩ����ɫ�ʰ�쵣���֪�ǴӺζ�����ǰ����һƬ
�����أ�����ԼԼ������Ѥ����˸��������һ����������ɵü�
���˽Ų���
LONG);

    set("exits", 
    ([ //sizeof() == 2
        "west" : __DIR__"fabao-road1",
        "east" : __DIR__"fabao-room",
    ]));

    set("outdoors", "1");

    setup();
}

