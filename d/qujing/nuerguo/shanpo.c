// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 4/4/1997
// room: /d/nuerguo/shanpo.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��������һ��бб��ɽ���ϣ����ߵ�����ӰӰԼԼ������һ
��ͤ�ӡ��ٳ��Լ��Ľ��¿�һ����ԶԶ����һƬ�����ԡ�

LONG);

  set("exits", ([
        "westup"   : __DIR__"changbie",
      ]));
  set("outdoors", __DIR__"");

  setup();
}






