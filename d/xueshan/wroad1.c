
//wroad1.c

inherit ROOM;

void create ()
{
   set ("short", "���µ�");
   set ("long", @LONG

������ǰ���ǹ���ȥ�ˡ�������·��һ������Ӷ�������������
��Ŀ�Ĵ���д�ţ������Ƚ��أ��ô�����������
LONG);

   set("exits", ([ //sizeof() == 1
     "east" : __DIR__"binggu",
   ]));

   set("outdoors", "xueshan");

   setup();
}
