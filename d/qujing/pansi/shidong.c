// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ʯ��������һ����أ���������ɭɭ�̹Ǻ���һ���֩������
����׹������������������ǵء��㲻������һ����ս������
һ�ں�����

LONG);

  set("exits", ([
        "north"    : __DIR__"shiyuan",
        "southwest"    : __DIR__"dongnei",
      ]));
  setup();
}

