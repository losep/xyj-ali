// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "��¥");
        set ("long", @LONG

��¥�ǵ�������Ϊ��ʱ���裬��һ�������ε���ש�������������൱
�Ĺ������ء����ϳɹ��Σ��������������档ÿ���������ƵĹ�
���ͻ����Ű���ĺ�����ڴ��С���лص���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"wailiu1",
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



