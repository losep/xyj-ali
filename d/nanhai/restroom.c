// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/restroom
inherit ROOM;

void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG

����������ɽ����Ϣ�ң�������յ�����ʲôҲû�У���֪����
ɽ���˵���������ô��˯���ġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaoyuan",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
  set("sleep_room", 1);

  setup();
}
