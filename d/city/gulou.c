// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "��¥");
        set ("long", @LONG

������¥��ǰ�����������������ڳ����������ĵġ���Ϊ�����Ƕ��
�Ľ��������Ѿ��𽥱������ˡ����¥��һ�������ε���ש��������
�����൱�Ĺ������أ����ϳɹ��Σ��������������档ÿ������
���ƵĹ����ͻ����Ű���ĺ��������ƫƧ��С���лص��������ǳ���
��ǰ�������������˵��Ǻܶࡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"wailiu2",
                "west" : __DIR__"baozipu",
                "south" : __DIR__"wailiu4",
                "north" : __DIR__"chenghuang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



