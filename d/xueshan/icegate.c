// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//icegate.c

inherit ROOM;

void create ()
{
   set ("short", "��������");
   set ("long", @LONG

������ȥ����������ͨ��ѩ����������Ρ��׳�ۡ����Ǵ˿̹���
���գ�һλ�������׵�׳����һλ��Ŀ��ɭ��������������ŵ�
������ǰ��
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"wuchang-n",
     //"north" : __DIR__"icegate",
     //"west" : __DIR__"wuchang-nw",
     //"east" : __DIR__"wuchang-ne",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/tuying-zunzhe" : 1,
     __DIR__"npc/baixiang-zunzhe" : 1,
   ]));


   set("outdoors", "xueshan");

   setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

