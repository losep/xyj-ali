// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

С·�������䣬·��������ʯ���ѱ������ĳ���ѹ��������ӡ��
·����һ�ÿ����������Ÿ�������������������·��������
ũ������ׯ�ڡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"xiaolu2",
        "west"   : __DIR__"hedong4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



