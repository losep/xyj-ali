// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������������Ϸ�����չ��ȥ���������ʯ���̾Ͷ��ɣ���
�г�����·�����߶���һƬƬ���ֵ����ɴ����ľ���������紵
����������

LONG);

  set("exits", ([
        "northwest" : __DIR__"tieta",
        "south" : __DIR__"yuwang2",
      ]));

  set("outdoors", __DIR__);

  setup();
}


