
//wuchang-w.c

inherit ROOM;

void create ()
{
   set ("short", "���䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

   set("exits", ([ //sizeof() == 4
     "south" : __DIR__"wuchang-sw",
     "north" : __DIR__"wuchang-nw",
     "east" : __DIR__"wuchang-c",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/yingwu-guai" : 1,
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

