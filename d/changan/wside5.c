// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

�����Ѿ����볤�����Ѿ���ЩԶ�ˣ�·�ϵ�����Խ��Խϡ��
�ˡ��������ᴹ��΢����棬����ľ�ɫ���ɺ�����������
���л�����һ����������Թ��������ӳ�䣬��Լ�ɼ�һ��С
·ͨ��Զ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/gao/lu1",
  "east" : __DIR__"wside4",
]));
  set("outdoors", 1);

  setup();
}
