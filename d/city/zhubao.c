// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�鱦��");
        set ("long", @LONG

�鱦������ⱦ�����䣬ѣ������Щ�������۾������µĳ����г���
�Ÿ��������鱦�������������м������ſ�����ѡ�����鱦��һ����
��ľ���ϰ��ſ����߶�ߵ����������֮����͸�ŵ������������ۺ�
��֮�������߳�ȥ����ȸ��֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"zhuque-s2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jin" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

