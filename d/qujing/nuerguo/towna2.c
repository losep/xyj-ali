// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 4/4/1997
// room: /d/nuerguo/towna2.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

������������İ������С�������һ�߸ߵĴ��ţ���������
������Ҫ��ڡ�����Ů������������Χ��һ��̸��������
�������µ�����һ�¡�

LONG);

  set("exits", ([
        "northup" : __DIR__"entry",
        "west"    : __DIR__"towna1",
        "east"    : __DIR__"towna3",
        "south"   : __DIR__"townb2",
    ]));
  set("outdoors", __DIR__"");

  setup();
}






