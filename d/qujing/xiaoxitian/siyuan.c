// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ����ʯɽ��ͤ������컨��䣬ͤ����ˮ������ˮ�ߴ���
����������һ�㡣Ժ��һ��ʯ·��������һ����Ժ�ӵı�
��ͨ�����⣬���Ͻ���һ��԰��

LONG);

  set("exits", ([
        "north"   : __DIR__"simen",
        "southwest"   : __DIR__"caiyuan",
        "east"   : __DIR__"daxiong",
      ]));
  set("outdoors", __DIR__);

  setup();
}



