// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

���߼�ľ���У��滨���ƣ�һ���������ӻ�ľ�����к��ʯ϶֮�¡���
����ȥ��·�ƽ���ƽ̹������
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "south" : __DIR__"road1.c",
]));

  setup();
}






