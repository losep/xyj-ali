// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ��֮��������������һƬ�����ش���һ����ɽ����һ����Ұ
�֣��м�������һ���ߴ����Ժ����Ժ����ǰ��һ����д�ţ�
��С�����¡��������֡�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"lindao11",
        "south"   : __DIR__"siyuan",
      ]));
  set("outdoors", __DIR__);

  setup();
}



