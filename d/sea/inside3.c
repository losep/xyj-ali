// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// inside3.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

����֮����һ���飬��ŵ��һ���յ�ͨ��������������ʯ������ɣ�����
���л�Ƕ�������鱦������ǽ�Ϲ������������������൱�ĳ¾ɡ�������
�ϱ�������ƫ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
  setup();
}
