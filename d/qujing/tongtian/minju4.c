// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

��ҳ����˼���������տյģ�һ��ľ�������Ϸ���һ������
�裬�����ʱ��м�ֻСľ�ʡ�ǽ�Ƿ���һ�Ѳ�̣�������һ��
�յ�ˮ�ס�

LONG);

  set("exits", ([
        "out"   : __DIR__"chen1",
      ]));
  set("objects", ([
        __DIR__"npc/kid"  : 1,
      ]));

  setup();
}



