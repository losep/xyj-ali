// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "Ԭ�ϲ���");
        set ("long", @LONG

������Ԭ�س��������Բ��ֵĵط�������Ԭ�سϣ������������˲�����
�����ǵ��������̨������Ԭ����常��С�������շÿ����ﲻ����
��Ԭ�����Ǹ�����ס���ˣ������ڳ��������й䣬�������С����Ҳ
����û���ˡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"wailiu1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shouchen" : 1,
                __DIR__"npc/xiushi" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}



