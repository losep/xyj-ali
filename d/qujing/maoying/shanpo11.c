// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ���ϳ��Ź������٣�·�Ͽ�֦��Ҷ��أ��±߸߸ߵ͵ͳ���
��ľ��ݣ�������һЩ���СС����ʯ���������������ʱ
�ɼ�������Ѩ��

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanpo9",
        "southeast"   : __DIR__"shanpo13",
      ]));
  set("outdoors", __DIR__);

  setup();
}



