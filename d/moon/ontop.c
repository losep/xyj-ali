// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ������״��С�ţ����������񣬾���ϸ�����ʻ������������Ϳ�Σ�һ
ɫˮĥȺǽ�������ʯ̨�ף����÷����������һ������ѩ�׷�ǽ������
��Ƥʯ��������ȥ���ſ���һ�����(tree)�������Բԡ��������䣬ȴ��
����ϰϰ�����˾���ˬ��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "tree" : "һ��������ƵĴ���� �����������Ĺ�
��ɢ�����������㣬��֪���������ܲɼ�����
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/guishuzhi" : 1,
  __DIR__"npc/girl" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"road1",
  //"down" : __DIR__"tree2",
]));

  setup();
}

void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    object me = this_player();

    if (!arg || (arg != "tree" && arg != "����"))
        return notify_fail("��ʲô��\n");

    message_vision("$N˳�����ɳ�������ȥ��\n", me);
    me->move(__DIR__"tree2.c");
    message_vision("$N�ӹ����ϳ�����������\n", me);
    return 1;
}
