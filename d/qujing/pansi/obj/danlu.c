// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat 11/16/1997

inherit ITEM;

void create()
{
  set_name("ͭ��¯", ({ "tong danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ���������������Ĵ�ͭ¯��\n");
    set("value", 2000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  remove_call_out ("smoking");
  call_out ("smoking",3+random(3),this_object());
  add_action ("do_penetrate", "penetrate");
  add_action ("do_enter", "enter");
  add_action ("do_fly", "fly");
  add_action ("do_dive", "dive");
  add_action ("do_teleport", "teleport");
  add_action ("do_jump", "jump");
}

int do_penetrate (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai1");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

int do_enter (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai2");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

int do_fly (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai3");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

int do_dive (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai4");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

int do_teleport (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai5");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/qujing/pansi/yuanwai6");
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
    who->unconcious();
  return 1;
}

void smoking (object me)
{
  object where = environment (me);
  tell_room (where,"ͭ��¯ð�����������̡�\n");
}
