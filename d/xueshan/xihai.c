//standroom.c used by weiqi...others may hate this format:D
//xihai.c

inherit ROOM;

void create ()
{
   set ("short", "����֮��");
   set ("long", @LONG

������һ���޼ʵ�ѩԭ��Ρ����ΰ�ı�ɽ��ͻȻ��̲����꣬��
�׳����ˮ��չ������ǰ�����ʱ����һ����������ӿ����ͷ��
ɽ�������ݣ��񣬷·��ǵ�����һ�����硣
LONG);

   set("exits", ([ //sizeof() == 1
     "east" : __DIR__"xueshan5",
   ]));
   
   set("objects", ([ //sizeof() == 1
     __DIR__"npc/hama" : 1,
   ]));

   set("outdoors", "xueshan");

   setup();
}
