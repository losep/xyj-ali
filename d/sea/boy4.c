// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hill.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����ʮ�ֿ���ǽ�ϻ�����һЩ�����ֽ⣬��ǽ�ļ����Ϸ���ʮ
��ѳ�ǹ�������̵��ǲü������ľ�飬��������֨֨���졣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"boy2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long3.c" : 1,
//  "/d/obj/armor/tenjia" : 1,
  __DIR__"obj/mucha" : 1,
]));

  setup();
}
