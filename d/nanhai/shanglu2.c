// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/shanglu2
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�������۵�ɽ·������ͨ�����ߡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tingjing",
  "eastup" : __DIR__"shanglu",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
