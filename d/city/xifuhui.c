// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "ϲ����");
        set ("long", @LONG

�������ھ���һ��ϲ�磬�����ŵƽ�ʣ�̨�ϸߵ����һЩ��Ů��
�������ֶ��裬�����С����������ϲ��;ơ���Χ������ǰ��ף��
�Ŀ��ˣ����ַǷ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "down" : __DIR__"ziyanglou",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 4,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


