// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�ɴ������������������������ס�����档һ������̨�׶����á�����
�����ɣ���������������ʿ���������ף�ɷ�����硣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"inside3.c",
  "westdown" : __DIR__"yujie3.c",
]));

  setup();
}
