// ALi by NewX
 
inherit ROOM;

void create ()
{
    set ("short", "��Ĺ���");
    set ("long", @LONG

ʼ����ĵ��¾�Ȼ��ı��ж��죬�����п�ʯͷ������д�š���ԯ��Ĺ��
�ĸ��֡���֣�����ʼ��������ô�ֱ����ԯ��Ĺ�ˣ���Ҳ�е�㲻��
����ô�����ˡ�

LONG);

    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"shidong1.c",
        "up": "/d/eastway/bingma.c",
    ]));

    setup();
}

