// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "�ϳǿ�ջ��¥");
  set ("long", @LONG

������轲�����õĲ;߶��ǴӾ������������ڵ����ζ��Ǻ�ľ�ģ�
�ڹ���֮�·���������ĵĹ����ƴ���ȥ�����������ľ����۵ס�
һȺ�ƿ��Ʊ���յ�����ȵ����֡�
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/haoke1" : 1,
  __DIR__"npc/haoke2" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"kezhan",
]));

  setup();
}
