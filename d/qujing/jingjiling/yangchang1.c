// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG

С·��խ��ֻ����һ�˲�����С�·�߾���������һ��С�ľͻ�
�����Ϲҳ��˿ڡ����������к�ɫҰ����������ժ����Զ������
һ���ǳأ��ϱ���ȥ����ʯͷɽ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/hunter" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shipo3",
  "northwest" : __DIR__"yangchang2",
  "west" : __DIR__"jingji1",
]));

  setup();
}

