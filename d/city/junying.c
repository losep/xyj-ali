// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���־�Ӫ");
        set ("long", @LONG

����פ����������������������ϵİ�ȫ�����פ���ڻʹ���Χ��ȷ
���ʹ��İ�ȫ������פ������������˴ӽ��������������������в�
֮ʿ��ƽ���ＸԱ���������������ա�
LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yulinjun" : 3,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

