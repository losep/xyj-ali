// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/chaoyindong.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������Ϻ�����ɽ����������ȴ󱯾ȿ���ѹ�������������
��֮���ڡ�ֻ��������������������̨�ϣ�΢���ƿڣ����ݴ�
��������������������������䣬�������ϡ�����������Χ�ƣ�
�����ͷס����ǣ���������ǧ���£������庭�����졣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"guangchang.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shizhe" : 1,
  __DIR__"npc/longnu" : 1,
  __DIR__"npc/guanyin" : 1,
]));
  set("light_up", 1);

  setup();
}
