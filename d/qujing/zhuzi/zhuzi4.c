// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "���Ͻ�");
  set ("long", @LONG

���Ϲ������Ĵ�����ɸ���ɽ����������ʯ�̳ɣ���ͨ����������
���������Ϲ��ĳ����Ĺ�¥��������һƮ�����ı�Ӫ�������Ͽɼ�
���Ϲ��ʹ���

LONG);

  set("exits", ([ 
    "south" : __DIR__"zhuzi5",
    "north" : __DIR__"gulou",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
