// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat
// Room: luzhou

inherit ROOM;

void create ()
{
  set ("short", "ɳĮ����");
  set ("long", @LONG

�����ļ����ȣ�Զ������������ľ��󡣲�����Ȼˮ�ݷ��������
�������ա����ذ��հ�����ҵ����Ҳ��Ȼ�Եá�

LONG);

  set("exits", ([
    "west" : __DIR__"shalu2",
    "east" : __DIR__"luzhou2",
  ]));
  set("outdoors", "firemount");

  setup();
}
