// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/mimi/zhuziguo/eastroom.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG

���Ǳ����µ��������Թ��η�ɮ�˽���һ�ޣ����ڳ����ª����ǽ
���м���ľ����

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"backyard",
    "west" : __DIR__"zheng",
  ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}
