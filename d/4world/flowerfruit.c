// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/flowerfruit
inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

��ɽ��ʮ��֮����������֮�������Կ����Ƕ����������к�
���ɡ������ɽ���дʸ�Ϊ֤����Ի��

���������������󣬳�ӿ��ɽ����Ѩ��
����������������������ѩ������Ԩ��

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aolai",
  "northup" : __DIR__"up1",
]));
  set("outdoors", 1);

  setup();
}
