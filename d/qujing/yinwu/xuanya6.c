// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��ɽ���룬���ƴ�Ρ��ֻ�����ϰ���ƮƮ����ǰ��Ӱ��������
���ɰ�ǧǧ����ͷ���񼸸ɡ��Ĵ���ʯ���ף�ʹ���ĸв�����
�������Ծٲ���

LONG);

  set("exits", ([
        "northeast"    : __DIR__"xuanya1",
        "southdown"    : __DIR__"xuanya8",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

