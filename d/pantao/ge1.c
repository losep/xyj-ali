// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/ge1.c

inherit ROOM;

void create ()
{
  set ("short", "���̸�");
  set ("long", @LONG

ֻ�����������ɷ����죬������ݰ���ɫ���ͷס���������
һԲ���ɺ����̨�����б�ź�𵤡��̸��ɰ˸��������߸���
����Χ�����ʺ���衣

LONG);

  set("exits", ([
        "south"     : __DIR__"ge2",
        "southwest" : __DIR__"pan1f",
      ]));

  set("objects", ([
         __DIR__"npc/lishi1"  : 1,
     ]));

  setup();
}

