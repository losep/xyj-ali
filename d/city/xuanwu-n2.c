// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򱱷���Զ
Զ���ܿ����ʹ��ĳ����š����洫������˿�����ͻ�Ц�����������
���������ġ������ַ����������ǳ��е�һ����ݡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"xuanwu-n1",
                "north" : __DIR__"xuanwu-n3",
                "west" : __DIR__"club",
                "east" : __DIR__"wuguan",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

