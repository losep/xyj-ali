// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʮ���޵�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanmenting.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"stars/foxer" : 1,
  __DIR__"stars/acer" : 1,
  __DIR__"stars/smallfox" : 1,
]));

  setup();
}
