// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//chufang.c

inherit ROOM;

void create ()
{
   set ("short", "����");
   set ("long", @LONG

�����ǳ�����ѩɽ�����ڶ����ȴ���󣬳Զ������õ�����ȥ��
��Ȼ���������������������оͲ͵ĵط����и���ͷ���Ե�С��
��������æ��æȥ�������Ϲ���һ�����ӣ���������չյ�д�ţ�
��С��硱��
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"eroad3",
     //"north" : __DIR__"wuchang-ne",
     "west" : __DIR__"wuchang-e",
     //"east" : __DIR__"chufang",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/xunshi" : 2,
     __DIR__"npc/xiaozuanfeng" : 1,
   ]));


   //set("outdoors", "xueshan");

   setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

