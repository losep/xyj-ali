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
�ڵķ����������ȴ����������鰲�ݡ�������һ�Ҳ��ã���������
��Ϊ���֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e4",
                "southwest" : __DIR__"wailiu2",
                "east" : __DIR__"caotang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yiren2" : 1,
                "/d/4world/npc/kid" : 1,
                "/d/4world/npc/kid1" :1,
        ]));


        set("outdoors", "changan");
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}



