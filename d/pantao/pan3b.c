// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3b.c

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
        "west"       : __DIR__"pan3a",
        "east"       : __DIR__"pan3c",
        "north"      : __DIR__"pan2b",  
        "south"      : __DIR__"fenga",  
      ]));

  set("outdoors",1);
  setup();
}

