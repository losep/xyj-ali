// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/cangjing.c

inherit ROOM;

void create ()
{
  set ("short", "�ؾ�¥");
  set ("long", @LONG

�ؾ�¥���ɫ���㣬�ű���һ���ͭ¯������ð���������̣�
�ź�ǽͷ����һЩͭ�壬���ڷ���һ����ֵ�̴����񡣶���
�����г���ͨ���

LONG);

  set("exits", ([
        "southeast"    : __DIR__"houdian",
      ]));

  set("objects", ([
         "/d/obj/book/daode"    : 1,
      ]));
  setup();
}

void init ()
{
  add_action ("do_spell","spell");
}

int do_spell (string arg)
{
  object who = this_player();

  if (! arg)
    return 0;

  if (arg != "shugui")
    return 0;

  tell_object (who,"�������ض�������˼������һ��罫����˹�ȥ��\n");
  who->move(__DIR__"miyuan");
  return 1;
}
