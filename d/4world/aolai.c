// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// /4world/aolai.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��ʤ���޺���һС�������������ٴ󺣣���������ɽ��ֻ��
�����һ����խ��ƽԭ�ش��Ͻ���һ���ǳء�һ����·ֱͨ
�Ϸ���·������Ҳ�ǴҴҶ�����
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"northgate.c",
  "west" : "d/changan/aolaiws",
  "east" : __DIR__"flowerfruit",
]));
  set("outdoors", 1);

  setup();
}
