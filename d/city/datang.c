// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
  set ("short", "����������");
  set ("long", @LONG

����֮����һ������֮�ƣ����������ľ�������ǰ��һ�Ŵ���������
����֪�����ˡ�����һ�����ң�д�ţ������������ĸ��̽���֡���
������һλ��������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhongdu",
]));

        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}

