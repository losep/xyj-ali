
//wuchang-ne.c

inherit ROOM;

void create ()
{
   set ("short", "�����䳡");
   set ("long", @LONG

���Ǳ����е�һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

   set("exits", ([ //sizeof() == 4
     "south" : __DIR__"wuchang-e",
     "west" : __DIR__"wuchang-n",
   ]));

   set("outdoors", "xueshan");

   setup();
}
