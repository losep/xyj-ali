// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/up2
inherit ROOM;

void create ()
{
  set ("short", "�ּ�С·");
  set ("long", @LONG

����ɽ�е�һ���ּ�С·��������پ��ᣬ��ľ���죬����
���У�ֻ��һЩ���������䵴����ȥ������ɽɽ����ΰ����
�վ�����ɽ�����߲��������������Ϻܿ�͵�ɽ���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"up1",
  "northup" : __DIR__"entrance",
]));
  set("outdoors", 1);

  setup();
}
