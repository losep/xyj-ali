// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ��������һ���ӻ��У�ʱ�������������ͻ����ϱ���һ��
�������ӣ��ǳ��ڵ���Զ�ھֿ��ģ�ר��һЩ������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"bingqipu",
                "north" : __DIR__"zahuohang",
                "west" : __DIR__"center",
                "east" : __DIR__"qinglong-e2",
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

