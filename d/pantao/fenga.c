// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/fenga.c

inherit ROOM;

void create ()
{
  set ("short", "�ʷ���");
  set ("long", @LONG

����̨����Ϊ�ʷ��������ڱ������ɣ������Ų�����յ����
����������Ů���������ɴ�£����ǳ����á����⿪��ǧǧ��
��л��������

LONG);

  set("exits", ([
        "north" : __DIR__"pan3b",
        "east"  : __DIR__"fengb",
      ]));

  set("objects", ([
         __DIR__"npc/female" : 1,
      ]));

  setup();
}

