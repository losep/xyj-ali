// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/up1
inherit ROOM;

void create ()
{
  set ("short", "�ּ�С·");
  set ("long", @LONG

����ɽ�е�һ���ּ�С·��������پ��ᣬ��ľ���죬����
���У�ֻ��һЩ���������䵴����ȥ������ɽɽ����ΰ����
�վ�����ɽ�����߲���������
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monkey2" : 1,
  __DIR__"npc/monkey1" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"up2",
  "southdown" : __DIR__"flowerfruit",
]));

  setup();
}
