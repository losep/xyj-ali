// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 4/4/1997
// room: /d/nuerguo/changshi.c

inherit ROOM;

void create ()
{
  set ("short", "����ͤ");
  set ("long", @LONG

��ɽ����ƽ���ϣ�����һ��ͤ�ӣ����Ϸ��������������
����ͤ����һС��д��������ͤ������������һ��С·��ͨ
�������⡣


LONG);

  set("exits", ([
        "northwest" : __DIR__"end",
        "eastdown"  : __DIR__"shanpo",
        "southdown" : __DIR__"xiaolu4",
      ]));

  setup();
}






