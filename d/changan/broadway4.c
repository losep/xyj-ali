// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/broadway4.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"broadway5",
  "north" : __DIR__"broadway3",
]));
  set("outdoors", 1);

  setup();
}






