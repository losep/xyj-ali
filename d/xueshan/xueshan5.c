//standroom.c used by weiqi...others may hate this format:D
//xueshan5.c

inherit ROOM;

void create ()
{
   set ("short", "ããѩ��");
   set ("long", @LONG

���ӵ�ɽ���ڴ��ƺ����ƽ̹�������������ǰ�ѩãã��ֻ�Ǳ�
���Ѳ�����ô��Ű�����Ƶ�Ⱥɽ���������һ��ȱ�ڣ���һ��
ϸ΢��ů�����϶�������Ʈ����
LONG);

   set("exits", ([ //sizeof() == 3
     "south" : __DIR__"xueshan4",
     "north" : __DIR__"xueshan6",
     "west" : __DIR__"xihai",
   ]));

   set("outdoors", "xueshan");

   setup();
}

