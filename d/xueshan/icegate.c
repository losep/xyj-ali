//standroom.c used by weiqi...others may hate this format:D
//icegate.c

inherit ROOM;

void create ()
{
   set ("short", "��������");
   set ("long", @LONG

������ȥ����������ͨ��ѩ����������Ρ��׳�ۡ����Ǵ˿̹���
���գ�һλ�������׵�׳����һλ��Ŀ��ɭ��������������ŵ�
������ǰ��
LONG);

   set("exits", 
   ([ //sizeof() == 1
     "south" : __DIR__"wuchang-n",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/tuying-guai" : 1,
     __DIR__"npc/baixiang-xiaow" : 1,
   ]));


   set("outdoors", "xueshan");

   setup();
}
