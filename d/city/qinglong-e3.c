// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ��������һ���ӻ��У�ʱ�������������ͻ��������ǳ���
������ۣ���Щ��ʿģ�����˳��롣
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"qingxuguan",
                "north" : __DIR__"zahuohang",
                "west" : __DIR__"qinglong-e2",
                "east" : __DIR__"qinglong-e4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

