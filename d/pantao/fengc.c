// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/fengc.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����̨����Ϊ��������������ϼ�ϻϣ������Ž���ҫ�ճ�������
�����콫������緽���ܽ�عڣ����赻Ի͡����ⳤ��������
�������ݡ�

LONG);

  set("exits", ([
        "north" : __DIR__"pan3e",
        "west"  : __DIR__"fengb",
      ]));

  set("objects", ([
        __DIR__"npc/male"   : 1,
      ]));

  setup();
}

