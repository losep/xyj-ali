// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�Ŷ���");
        set ("long", @LONG

��ǳ�����Ǯ�˼Ҷ����ղظ��Ŷ����������������Ҳ�ǲ���������
�������Ļ�������ſ��˿������ۡ����а��Ÿ��ָ����ĹŻ���ǽ��
�Ļ������ϵ�ƿ���������ÿ������������ô������˰������֡�
�������࣬ȴû��֪�����ϰ��Ǵ��Ľ��Ļ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "west" : __DIR__"wailiu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/lin" : 1,
                "/d/obj/misc/tables" : 3,
                "/d/obj/misc/chairs" : 6,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



