// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ���ϱ���һ����ۡ����ǽ���ߣ�һ����ʲô���ס�ĵط���
���������˳��롣�����ǳ����ǵ��ܶ����ţ����ܹҽǣ��Եļ���
���ơ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"zhongguan",
                "north" : __DIR__"zhongdu",
                "west" : __DIR__"baihu-w3",
                "east" : __DIR__"baihu-w1",
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


