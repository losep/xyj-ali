// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// sixue

// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c

inherit ROOM;

void create ()
{
  set ("short", "����ٸ��");
  set ("long", @LONG

������һ���޴�ı���ٸ���У������������ǧ�������
�������ı���ٸ���гɼ�ʮ·�ݶӣ��·����ڴ�����˷�
��Х�������㲻���������ΰ�ĳ��澪����

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
    add_action("do_dig", "dig");
}

int do_dig(string arg)
{
    object me;
    me = this_player();
    if ((arg!="ground") && (arg!="��"))
        return notify_fail("������ʲô��\n");
    message_vision("$N�ڵ����ڿ�һ���������˽�ȥ��\n", me);
    me->move("/d/gumu/door");
    return 1;
}
