// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan1b.c

inherit ROOM;

void create ()
{
  set ("short", "��ǧ�����԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

������������罺ˣ���ǧ��һ�졣

LONG);

  set("exits", ([
        "west"       : __DIR__"pan1a",
        "east"       : __DIR__"pan1c",
        "north"      : __DIR__"yaoa",  
        "south"      : __DIR__"pan2b",  
      ]));

  set("outdoors",1);
  setup();
}

