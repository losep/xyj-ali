
//wuchang-nw.c

inherit ROOM;

void create ()
{
   set ("short", "�����䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹��򡣶����һ�����Ӷ���һ�ɴ���ȽȽ��������ǳ�
���ˡ�
LONG);

   set("exits", ([ //sizeof() == 4
     "south" : __DIR__"wuchang-w",
     "east" : __DIR__"wuchang-n",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"obj/ice" : 2,
   ]));

   set("outdoors", "xueshan");

   setup();
}
