
//wuchang-e.c

inherit ROOM;

void create ()
{
   set ("short", "���䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

   set("exits", ([ //sizeof() == 3
     "south" : __DIR__"wuchang-se",
     "north" : __DIR__"wuchang-ne",
     "west" : __DIR__"wuchang-c",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/huanghe-shier" : 1,
   ]));

   set("outdoors", "xueshan");

   setup();
}

