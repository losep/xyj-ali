
//wuchang-sw.c

inherit ROOM;

void create ()
{
   set ("short", "�����䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

   set("exits", ([ //sizeof() == 3
     "north" : __DIR__"wuchang-w",
     "east" : __DIR__"wuchang-s",
   ]));

   set("outdoors", "xueshan");

   setup();
}
