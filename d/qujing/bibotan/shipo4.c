// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

��ʯ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľΨ
�к���������ɽ������һ�ź��ơ��򶫿ɿ����̲�̶��һ��̶ˮ
������Χ��ɽ�С�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/jaguar" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shipo2",
]));

  setup();
}

