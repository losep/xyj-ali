// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�ɷ��");
  set ("long", @LONG

����ɽ�߶������ܣ�Ψɽ����������ƣ���ͬ�������ǻ�����
�ò�ɢ�����˾��졣���཭��С�򣬽�é���ݶ��������ʣ���
Ȼ�������ŵ���Ȥ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/erlang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"cuiping",
]));

  setup();
}


