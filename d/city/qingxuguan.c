// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG

������ǳ�������������һ�����ۡ������Ƴ��Ļʵۺ͵�����������
ͬ�գ���˵��̱���Ϊ�Ƴ��Ĺ��̡������ڷ�̵Ĵ��룬���̵�״��
�Ѵ������ǰ����������û�м������ˣ�������ԭ�е����ƻ�û��
�䡣�㰸�Ϲ���Ԫʼ����̫���Ͼ�����ٵ���������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/daozhang" : 1,
     "/d/lingtai/npc/xiao" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

