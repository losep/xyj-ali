// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/wroad2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG

����·�൱���ߡ������Ѿ��������������ˡ�·�ϳ����٣�
����һ�ӶӵĹٱ�Ѻ��һ���������ͨ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"wroad3",
  "northeast" : __DIR__"wroad1",
]));
  set("outdoors", 1);

  setup();
}






