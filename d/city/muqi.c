// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
    set ("short", "ľ����");
    set ("long", @LONG

����һ��ר��ľ����С�꣬���治��ȴ�����ࡣ����ľ��������Щ
ľ����ľǹ֮�࣬³�ϰ�Ҳ�����й䣬�������¡���˽����˵������
�洫���գ�ȷ˭Ҳû������
LONG);

    //set("item_desc", ([" *** " : " *** ", ]));

    set("exits", 
    ([ //sizeof() == 4
            "south" : __DIR__"baihu-w4",
    ]));

    set("objects", 
    ([ //sizeof() == 1
            __DIR__"npc/lu" : 1,
    ]));

//        set("outdoors", "changan");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}


