// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����֮�ϻ��Ƿǳ�������Χǽ�ϵ��Ŵִ���͵ƣ��Ѵ�����
��ͨ�������и�̨�Ϸ�������̫ʦ�Σ�����С�������߶���
LONG);

  set("exits", ([
        "south" : __DIR__"lu2",
      ]));
//  set("outdoors", __DIR__);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yin" : 1,
  __DIR__"npc/xiong" : 1,
  __DIR__"npc/niu" : 1,
]));

  setup();
}





