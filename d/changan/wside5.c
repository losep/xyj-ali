// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

�����Ѿ��ӽ���ˮ��Դͷ���˼�Խ����ϡ�١����ܾ�����Զ�����
����Ҳ��������������������ӳ�У���Լ�ɼ�һ��С·ͨ��Զ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/gao/lu1",
  "east" : __DIR__"wside4",
]));
  set("outdoors", 1);

  setup();
}
