// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan2f.c

inherit ROOM;

void create ()
{
  set ("short", "���԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

LONG);

  set("exits", ([
        "northeast"  : __DIR__"ge3",
        "east"       : __DIR__"ge4",
        "southeast"  : __DIR__"ge5",
        "west"       : __DIR__"pan2e",
      ]));

  set("outdoors",1);
  setup();
}

