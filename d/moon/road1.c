// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

���߰�ʯ��㣬�����֣��������ޣ��ݺ����������̦޺�ɰߣ�������
ӳ������΢¶��С����
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"ontop.c",
  "north" : __DIR__"road2",
]));

  setup();
}






