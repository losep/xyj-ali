// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "���й·�");
  set ("long", @LONG

�·��ں���Ư���������ǰ�ãã��һƬ����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"aolaiws.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
