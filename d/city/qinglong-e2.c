// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ���ϱ����ǹ�ģ��С��լԺ�������Ժ�ŵ�������д�Ŷ���
�ġ���Զ�ھ֡����֣������һ��լԺ�ǵ����������屦��լ�ڡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : "/d/jjf/nogate",
                "north" : __DIR__"biaoju",
                "west" : __DIR__"qinglong-e1",
                "east" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));

        set("outdoors", "changan");
    set("no_clean_up", 0);
        setup();
    replace_program(ROOM);
}

