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
        "northeast"   : __DIR__"shilu5",
        "eastup"   : __DIR__"shanpo2",
        "southup"   : __DIR__"shanpo4",
        "southwest"   : __DIR__"shanpo3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



