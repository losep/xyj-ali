// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ�������ǼҴ�ľ�¥�������������£����ַǷ�������ȴ��
�ҹ�ģ��С����Ժ�������Ϳ�Ҫ�����ˡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"huashengsi",
                "north" : __DIR__"ziyanglou",
                "west" : __DIR__"baihu-w4",
                "east" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


