// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/27/1997
// room: /d/pantao/pan2e.c

inherit ROOM;

void create ()
{
  set ("short", "��ǧ�����԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

�������Ҳ㻨��ʵ����ǧ��һ�졣

LONG);

  set("exits", ([
        "east"       : __DIR__"pan2f",
        "west"       : __DIR__"pan2d",
        "north"      : __DIR__"pan1e",  
        "south"      : __DIR__"pan3e",  
      ]));

  set("outdoors",1);
  setup();
}

