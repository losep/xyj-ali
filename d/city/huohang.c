// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
        set ("short", "���вֿ�");
        set ("long", @LONG

�����ǼҴ���еĲֿ⣬��������϶��Ų��ٻ�����»��в��ٻ�
�񡣻����ǿ������ͻ�Ϊ�������û��ǲ�����ʱ��������װж��
�æ����һ�ԵĻ�ơ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "northwest" : __DIR__"wailiu3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dai" : 1,
                __DIR__"npc/huoji" : 3,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

