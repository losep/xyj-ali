// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: ylt.c
// AceP

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����������һƬǬ������Ĳݵء���˵�⴦���ֱ������ϵİ칫
֮���������������Ů�������˰ݽ��²��������о��л���һЩ
������ͷ�Ե��ˣ����ֻ����Ǹ���������������������ţ����Σ�
�η򣬴����֣�һӦ��ȫ����ϧ���������ң���Ҳû����������
�����ˣ�����������ʱһ��ǧ�ɡ�
LONG);

  set("objects", ([ /* sizeof() == 5 */
  __DIR__"obj/jiaozi" : 1,
  __DIR__"npc/jiaofu" : 1,
  __DIR__"npc/lgshou" : 1,
  __DIR__"npc/jftou" : 1,
  __DIR__"npc/snshou" : 1,
]));
  set("no_steal", "1");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ontop2",
  "enter" : __DIR__"ylt",
]));
  set("no_sleep_room", "1");
  set("no_fight", "1");
  set("outdoors", 1);

  setup();
}
