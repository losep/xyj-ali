// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//meeting.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ǹ���ѩ��ػ�ĳ�Ա���»�ĵط����������Ŵ�Բ����ʮ�������ӡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"living",
]));

  setup();
}


