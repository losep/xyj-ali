// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/wroad3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG

������ȥ·�����У���ʯ·�ѿ�ʼ�����·�ˡ�ǰ������
���Ǵ�˵�еĹ཭�ڣ��㲻�ɵüӿ��˲�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : "d/meishan/guanjiang1",
  "northeast" : __DIR__"wroad2",
]));
  set("outdoors", 1);

  setup();
}






