// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "��¥̨");
  set ("long", @LONG

���˹���һС̨��Զ���ɾ���������������ϼ������ǧ������
�̡�Զ�ϳ��ű����ɣ��칬����ӳ�ƹ⡣�����������������ɾ���
�����˼�����ࡣ
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("outdoors", 1);
  setup();
}


