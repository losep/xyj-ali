// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/cglaem
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

���������綨�����䣬����ɽ����

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"path1",
]));
  set("no_clean_up", 1);
  setup();
}
