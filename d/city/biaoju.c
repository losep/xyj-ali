// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�ھִ�Ժ");
        set ("long", @LONG

��Զ�ھֵĴ�ʼ������Ӣ������Զ������Ӣ�������Ѹߣ����Ѳ�����
�����Ƿ��ˡ������ھֵĶ�������������Զ�Ĵ�������������Ժ
�������᷿����ǽ����Щ������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qinglong-e2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoshen" : 1,
     __DIR__"npc/biaotou" : 2,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

