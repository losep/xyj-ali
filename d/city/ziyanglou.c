// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "ϲ����");
        set ("long", @LONG

ϲ�����ǳ���������������һ�������ˡ����ﲻ�������о�����Ĵ�
�ٹ��˵��ų����룬��ÿ��Ӵ��ŴӸ���Ľ�����������ˡ����һ̤
���ţ���С�������ڵ�ӭ��������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"baihu-w3",
     "up" : __DIR__"xifuhui",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoer1" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


