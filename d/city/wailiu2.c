// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

���������ǳ��е��������������Գ�Ť��״�������������������
ʯ�̳ɵĴ�·�������ߣ���������ש�߷����������﹧���������
�ڵķ����������ȴ����������鰲�ݡ�������ǳ�����ǰ������
��������˺ܶࡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"wailiu1",
                "north" : __DIR__"chenghuang",
                "west" : __DIR__"caotang",
     "northeast": __DIR__"wailiu3",
                "east" : __DIR__"gudongdian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yiren1" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



