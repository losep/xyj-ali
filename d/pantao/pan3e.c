// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3e.c

inherit ROOM;

void create ()
{
  set ("short", "��ǧ�����԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

�������һ�΢��С����ǧ��һ�졣

LONG);

  set("exits", ([
        "east"       : __DIR__"pan3f",
        "west"       : __DIR__"pan3d",
        "north"      : __DIR__"pan2e",  
        "south"      : __DIR__"fengc",  
      ]));

  set("outdoors",1);
  setup();
}

