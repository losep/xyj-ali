// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

�������ǰ׻���ֵ����Σ�����С������Լ����һ������������
�����ǵĳ������Ǹ����ֵĳ�����ˣ��ʽ���յģ���С�Ը��ģ�
�����Կ������Ǹ����̾�������������֮�ء�����������ȴ���ѿ���
������Ӱ��ż������Ҳ�ǵ�ͷ�첽������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"beiyin1",
                "north" : __DIR__"wailiu1",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w3",
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



