// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /moon/kunlun.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

��ã���أ�����ǧ�������ȥ������νǧ����⣬����ѩƮ���������
���ƣ���������������Ů�塣��˵����ĸ����������Ů���������������
��һ�����ѵ�С·��
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/xueshan/xueshan1",
  "southeast" : __DIR__"xiaolu1",
  "west" : "/d/moon/yunu1",
  "east" : __DIR__"fabao-road1",
]));

  setup();
}






