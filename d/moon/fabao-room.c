// ALi By NewX

//self-made fabao room

inherit ROOM;

void create ()
{
    set ("short", "Ů洲��촦");
    set ("long", @LONG

������һƬ�����ء�����������һ����һ�����ι�״ɫ�ʰ�쵵�
������ʯ����ѩɫӳ����������⡣����һ���ʯ�Ͽ��ż��д�
�֣�

    ���ؾ���
    Ů洲���
    ��ʯδ��
    �Ÿ�����

���»���������ؿ���һƪС��(words)����Զ��Ҳ������˵����
ʲô��
LONG);

    set("item_desc", ([ "words" : "�������Ҳ����û�����\n", ]));

    set("exits", 
    ([ //sizeof() == 1 
            "east" : __DIR__"fabao-road2",
    ]));

    setup();
}
