// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���Ĺ�");
  set ("long", @LONG

���Ĺ����湩��һ������󰸣���������ͭ��¯�������������ð��
���������̡����Ķ������߶����Ÿ������񣬱���ͨ��������ͬ�Ĺ�
��ϱ��ǳ��ڡ�

LONG);

  set("exits", ([
        "south" : __DIR__"wanshou",
        "north" : __DIR__"ningxin",
      ]));

  setup();
}

void init ()
{
  object who = this_player();


  if (who->query_temp("kaifeng_qingxin") &&
      who->query_temp("kaifeng_ningxin") &&
      who->query_temp("kaifeng_jingxin"))
  {
    who->start_busy (1,1);
    who->delete("quest/pending");
    who->delete_temp("kaifeng_qingxin");
    who->delete_temp("kaifeng_ningxin");
    who->delete_temp("kaifeng_jingxin");

    who->set_temp("kaifeng_donate_silver",0);
    // delete temp after finish san-xin.

    call_out ("feeling",1,who);
  }
}

void feeling (object who)
{
  who->interrupt_me();
  message_vision ("$N�߽����Ĺ�������һ��������ʱ�ľ������羵��\n",who);
}

