// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/broadway3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�������һ����ʯ·��
������ͨ���������
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"broadway4",
  "north" : __DIR__"nanyue",
]));
  set("outdoors", 1);

  setup();
}






