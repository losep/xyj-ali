// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ�����Ҷ���Ȼ�γɵĶ�Ѩ��������Щ����������������Ƥ��
�ݣ�����һЩ�������Ĺ�ͷ�����ڿ���һ�����ӣ����в���
�������ӡ�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"obj/rou" : 8,
      ]));
  setup();
}

