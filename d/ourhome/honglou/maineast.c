// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/maineast
inherit ROOM;

int do_serve();

void create ()
{
  set ("short", "׺����");
  set ("long", @LONG

�������¥�����¥��

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main",
]));

  setup();
}

void init()
{
   add_action("do_serve", "bian!");
}

int do_serve()
{
        object who, obn;
        object room;

   who = this_player();

        room = environment(who);

        obn = new("/d/ourhome/obj/wineskin");
        obn->move(room);

        obn = new("/d/ourhome/obj/jitui");
        obn->move(room);
        message_vision("ʳ���ˮ������$N��ǰ��\n", who);

        return 1;
}

