//standroom.c used by weiqi...others may hate this format:D
//xueshan6.c

inherit ROOM;

void create ()
{
   set ("short", "ããѩ��");
   set ("long", @LONG

�����Х����ѩãã�����治Զһ���޴�ı�����ᶫ�������
��������ߡ����֮��������Լ��ƺ����ޱ��������
LONG);

   set("exits", ([ //sizeof() == 2
     "south" : __DIR__"xueshan5",
     "north" : __DIR__"bingchuan",
   ]));

   set("outdoors", "xueshan");

   setup();
}

