// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/yaoc.c

inherit ROOM;

void create ()
{
  set ("short", "���ض���");
  set ("long", @LONG

���ض���һ�����������ſ������������ɾơ���������˱ǣ�
�м�����Ƶ��ɹ٣��������ʿ���켸����ˮ�ĵ��ˣ��ջ��
ͯ�ӣ��ڴ�������Һ������������

LONG);

  set("exits", ([
        "west"  : __DIR__"yaob",
        "south" : __DIR__"pan1e",
      ]));

  setup();
}

