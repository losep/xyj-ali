// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/rainy/sea/huayuan7.c
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

��԰֮�еĲ�ľ������ʢ����ϸ��ȥ����Щ�ڷ����ѵ�һ������Ʒ������
���֣�������Щ�����С���ζ���Ϊ��԰���˼�����Ȥ��������������
���˽��٣�Զû��ǰ�������������
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beinu" : 1,
]));

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan6",
  "west" : __DIR__"huayuan8.c",
]));
  setup();
}
