
//wuchang-s.c

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
     "south" : __DIR__"binggu",
     "north" : __DIR__"wuchang-c",
     "west" : __DIR__"wuchang-sw",
     "east" : __DIR__"wuchang-se",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/xunshi" : 2,
   ]));

   set("outdoors", "xueshan");

   setup();
}
