//standroom.c used by weiqi...others may hate this format:D
//xueshan1.c

inherit ROOM;

void create ()
{
  set ("short", "ããѩ��");
  set ("long", @LONG

�����Х����ѩãã������������ȥ�������Ӳ�����ѩ�壬����ǰ�߱�Ҫ
��������������ˡ����Ϸ�������Ⱥɽ�����ֻ�Ǳ�ѩ�Ѳ������ڣ�Ҫ��
����ѩɽ�ǳɹ������ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : "/d/moon/kunlun",
    "north" : __DIR__"xueshan2",
  ]));

  set("outdoors", "xueshan");
  setup();
}


