// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�����������ʢ������������Ӽ���ƽ����������¡֮�ࡣ����ǰ
��һ���װ����֣���������ĳ��������һλ�ֳ��ʲ���ë�ʵ���
�١�һλ��ף��ǰ�ߺ󣬺ʹ�Ҵ����к���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
            "south" : __DIR__"gulou",
        ]));

        set("objects", 
        ([ //sizeof() == 1
            __DIR__"npc/keeper" : 1,
        ]));
    set("no_fight", 1);
    set("no_magic", 1);

//        set("outdoors", "changan");
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}



