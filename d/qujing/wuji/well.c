// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/mimi/zhuziguo/well.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ������ľ������ž������³�������̦��������ɭɭ������
����ڰ������桭��

LONG);

  set("exits", ([ 
    "up" : __DIR__"yuhua",
    "down" : __DIR__"shuijing",
  ]));

  setup();
}
