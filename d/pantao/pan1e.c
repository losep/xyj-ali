// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan1e.c

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
        "east"       : __DIR__"pan1f",
        "west"       : __DIR__"pan1d",
        "north"      : __DIR__"yaoc",  
        "south"      : __DIR__"pan2e",  
      ]));

  set("outdoors",1);
  setup();
}

