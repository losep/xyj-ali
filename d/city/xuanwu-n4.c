// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򱱷���Զ
Զ���ܿ����ʹ��ĳ����š������ǳ����ǵ����̨�������������ʽ
������������С������������־�Ӫ�������Żʹ��İ�ȫ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"xuanwu-n3",
                "north" : "/d/huanggong/chaoyangmen",
                "west" : __DIR__"junying",
                "east" : __DIR__"tianjiantai",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//      __DIR__"npc/japan1": 2,
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

