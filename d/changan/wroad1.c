// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/wroad1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG

����·�൱���ߡ�������Զ���ǹᴩ�����ϱ��Ĵ�ٵ�����
��ֱ���������·�ϳ����٣�����һ�ӶӵĹٱ�Ѻ��һ
���������ͨ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"wroad2",
  "northeast" : __DIR__"nanyue",
]));
  set("outdoors", 1);

  setup();
}






