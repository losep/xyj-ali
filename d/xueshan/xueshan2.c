//standroom.c used by weiqi...others may hate this format:D
//xueshan2.c

inherit ROOM;

void create ()
{
   set ("short", "ããѩ��");
   set ("long", @LONG

�����Х����ѩãã��������ȥ�������Ӳ�����ѩ�塣���֮��
���Ѻ�������������ѩ����ѩ��
LONG);

  set("exits", ([ //sizeof() == 2
     "south" : __DIR__"xueshan1",
     "northwest" : __DIR__"xueshan3",
   ]));

   set("outdoors", "xueshan");

   setup();
}

