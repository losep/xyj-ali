// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�ܹܸ���");
        set ("long", @LONG

�����ǵ����ܹ���ɽ�ĸ��ڡ�������������ͷ�ߴ��ʯʨ�ӡ�Ժ��
�������˻��ݡ�������һ�û����������дУ��ڸ��˴���Ժ�ӡ�һ
�������ߵ�ͨ����Ժ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "north" : __DIR__"baihu-w2",
     "south" : __DIR__"zhongguan2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guanjia" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 3,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


