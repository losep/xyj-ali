// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/8/1997
// room: /d/westway/jincheng.c

inherit ROOM;

void create ()
{
  set ("short", "��ǿ���");
  set ("long", @LONG

��ǿ���������������Ҫ����������ȥ��ããһƬԶ������
ԼԼ��һȺɽ���������ǽ�ǿ����ţ����Ž��գ����Ŷ����
��һСʳ̯������ʲô��������һ����ٵ�����ͨ����ƹ���
�����ǡ�

LONG);

  set("exits", ([
        "west"      : __DIR__"dadao",
        "southeast" : __DIR__"west3",
        "northeast" : "/d/moon/xiaolu3",
      ]));
  set("outdoors", __DIR__);

  set("objects",([
        __DIR__"npc/tanfan" : 1,
       ]));

  setup();
}





