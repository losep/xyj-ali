// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// /u/wuliao/firemount/longzhuang

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "��ɫׯԺ");
  set ("long", @LONG
���߸ǵķ��ᣬ��ש����ԫǽ���������ȣ������齣�һƬ���Ǻ��
��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhou2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));

  setup();
}
