// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�ӻ���");
        set ("long", @LONG

�ӻ����в����Ǻܴ���������ѵĶ��ǻ���������ǳ���ӵ����
������Ϊ���ͻ�Ϊ����֮·�����������൱�ĺá������м���С���
��æ��װж����Ա�һ��С������װ����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/huoji" : 3,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

