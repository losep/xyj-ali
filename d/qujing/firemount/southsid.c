// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/wuliao/firemount/nonameroad

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG
�����Ǵ���ɽ����������һ��Сɽ����ǻ���ɽ��
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xiaomiao",
  "south" : __DIR__"cuiyunshan4",
  "northup" : __DIR__"southside2",
]));
  set("outdoors", "/u/wuliao");

  setup();
}
