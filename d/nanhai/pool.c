// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/pool
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������������ƣ������ߵĿյ��ϻ����ż��Խ�׵�ĵ����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhulin",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/d/penglai/npc/ludongbin" : 1,
]));

  setup();
}
