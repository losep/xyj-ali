// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/yaob.c

inherit ROOM;

#define FILE __DIR__"npc/taibai"

void create ()
{
  set ("short", "����");
  set ("long", @LONG

                       �����ء�

�������ƣ������ͷף���̨�̲ʽᣬ����ɢ�뵡����������
��翣�������Ӱ����������������ǧ�������衣��������
�η��裬�����ɴ������ʰ�ζ��������������ɫɫ�¡�

LONG);

  set("exits", ([
        "south" : __DIR__"palace1",
        "west"  : __DIR__"yaoa",
        "east"  : __DIR__"yaoc",
      ]));

  set ("no_fight", 1);
  set ("no_magic", 1);
  setup();
}

void init()
{
   if(sizeof(filter_array(children(FILE),(:clonep:)))<1)
       new(FILE)->move(this_object());
}

