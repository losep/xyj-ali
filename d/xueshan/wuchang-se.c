
//wuchang-se.c

inherit ROOM;

void create ()
{
   set ("short", "�����䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

   set("exits", ([ //sizeof() == 2
     "north" : __DIR__"wuchang-e",
     "west" : __DIR__"wuchang-s",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"obj/ice" : 2,
   ]));

   set("outdoors", "xueshan");

   setup();
}

