//binggu.c

inherit ROOM;

void create ()
{
   set ("short", "����");
   set ("long", @LONG

��ǰ���龰���㾪���ˡ�û�뵽������������ı���ѩ���л���
��ôһ��ط����������������ı��°�����Χ����һ����Բ��ʮ
���ɽ�ȡ����������д�С������ʮ����
LONG);

   set("exits", ([ //sizeof() == 3
     "north" : __DIR__"wuchang-s",
     "west" : __DIR__"wroad1",
     "east" : __DIR__"eroad1",
   ]));
   
   set("objects", ([ //sizeof() == 1
     __DIR__"npc/zhangmen" : 1,
   ]));

   set("outdoors", "xueshan");

   setup();
}



