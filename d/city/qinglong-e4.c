// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

������һ��������ʯ�����ϣ����߾Ϳ�Ҫ���˳��ţ�ԶԶ����һЩ
��������Ѳ�ߡ�����ֱͨ�������ġ������ǳ���һ�����Ӫ��������
��ɭ�ϣ�һ�����ǲ������ڵġ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : "/d/eastway/wangnan1",
                "north" : "/d/jjf/yingfang",
                "west" : __DIR__"qinglong-e3",
                "east" : __DIR__"dongmen",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

