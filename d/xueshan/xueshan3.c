// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//xueshan3.c

inherit ROOM;

void create ()
{
   set ("short", "ããѩ��");
   set ("long", @LONG

�����Х����ѩãã��������ȥ�������Ӳ�����ѩ�塣���֮��
���Ѻ�������������ѩ����ѩ��
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "southeast" : __DIR__"xueshan2",
     "north" : __DIR__"snowmaze1",
     //"west" : __DIR__"wroad1",
     //"east" : __DIR__"eroad1",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/***" : 1,
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



