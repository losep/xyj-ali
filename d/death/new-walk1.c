// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

����������ܵظ�֮�У�ż������������������˾��ǣ��Щ����
��������������ȥ����Χ��һ������¥�󹬵������Ҳ�൱�ĸ�
���ûʣ���ֵ��Ƕ���һ�ȶ��Ž𶤵ĺ�ľ�ź�һ�������ż���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-yinhun",
  "west" : __DIR__"new-zhaopo",
  "north" : __DIR__"new-walk2",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/genggui" : 1,
]));

  setup();
}

