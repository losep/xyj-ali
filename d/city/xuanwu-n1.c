// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򱱷���Զ
Զ���ܿ����ʹ��ĳ����š�·������������������¥��������������
ΰ׳������ֵ��ǲ�¥��ǰ����ϡ�裬�Ե��������塣
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"center",
                "north" : __DIR__"xuanwu-n2",
                "east" : __DIR__"zuixing",
                "west" : __DIR__"qilin",
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

