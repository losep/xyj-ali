// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�ּ��ֵܼ���ǰ�Ͽ����������̣����������Ͻ��������в����ط���
������һ�պù�һ�գ��ڳ���Ҳ���������������а���ʮ���Ű�������
����С��������ػ�æ���š�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"wailiu1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jia" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



