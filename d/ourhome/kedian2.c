// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /city/kedian2.c

inherit ROOM;

void create ()
{
  set ("short", "�Ľ�Ұ��");
  set ("long", @LONG
�������ڻĽ�Ұ���һ�����С·�ϣ�ֻ��һЩС����
�����������ȥ�� 
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "south" : __DIR__"kedian3",
]));

  setup();
}
