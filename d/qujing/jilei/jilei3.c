// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ���絶��һ�㣬Ⱥ�������ι�״��Ȯ������ɽ������
����һ�ɹ�Ũ�ҵ���������������Х���չȻ�����Ұ�޵ĺ�
�����Ѿ��ܽ��ˡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"jilei1",
        "southwest"   : __DIR__"shidong",
      ]));
  set("outdoors", __DIR__);

  setup();
}



