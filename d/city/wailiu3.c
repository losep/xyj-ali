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
�ڵķ����������ȴ����������鰲�ݡ����ϱ���һ���ֿ⡣
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"wailiu2",
                "west" : __DIR__"wailiu4",
                "southeast" : __DIR__"huohang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/obj/book/misc" : 1,
        ]));


        set("outdoors", "changan");
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}



