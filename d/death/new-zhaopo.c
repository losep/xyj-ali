// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "�л�˾");
  set ("long", @LONG

�л�˾�ں���ɭɭ���������಼Χᣣ������ý���˿������Щ���
��ͼ������ǰ�����������У��������ڡ�����һ�Ź�ľ���������
����Щ���顣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk1",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baiwuchang" : 1,
]));


  set("hell", 1);

  setup();
}

