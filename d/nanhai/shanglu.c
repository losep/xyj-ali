// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/shanglu
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�������۵�ɽ·�����Ͼ�������ɽ��ɽ�š�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shanglu2",
  "northup" : __DIR__"gate",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
