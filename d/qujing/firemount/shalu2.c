// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4/11/1997
// Room: shalu2

inherit ROOM;

void create ()
{
  set ("short", "ɰ����");
  set ("long", @LONG

С��������һƬ���ޣ�����ͨ��ɽ�վ��С�����ϣ��Ѿ����Ը�
����ɽ�ϵ�����һ�����ӿ����

LONG);

  set("exits", ([
        "west" : __DIR__"shalu",
        "east" : __DIR__"luzhou",
      ]));
  set("outdoors", "firemount");

  setup();
}
