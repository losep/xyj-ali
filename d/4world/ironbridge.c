// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/none/newtoy/ironbridge
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ٲ�Ȫ��ԭ�����������š�
��������֮ˮ�������ʯ��֮�䣬��������ȥ���ڱ������š�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"dragonpalace",
  "out" : __DIR__"fall",
  "cave" : __DIR__"cave",
]));

  setup();
}
