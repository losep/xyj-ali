
//wuchang-n.c

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
     "south" : __DIR__"wuchang-c",
     "north" : __DIR__"xuelu",
     "west" : __DIR__"wuchang-nw",
     "east" : __DIR__"wuchang-ne",
   ]));
   
   set("objects", ([ //sizeof() == 1
     __DIR__"npc/xunshi" : 2,
   ]));


   set("outdoors", "xueshan");

   setup();
}
