// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���ǲ�ׯ");
        set ("long", @LONG

�������ҵĲ������������ֽ��ϰ���������������������������һ��
�ù�һ�ա�������Ǯ�˼�Ҫ�����׼�ǵ�����ѡ��������һ����ͩ
ľ�ĳ�̨��������й����˸�ʽ���������Ь��֮�ࡣ�������˲�
�ϣ�ȷ��������¡��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/liu" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


