// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997


inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("֣�Ѹ�", ({"zheng guafu", "zheng", "guafu", "fu"}));
  set("gender", "Ů��");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "guo" : "/d/qujing/qinfa/obj/guo",
    "wan" : "/d/qujing/qinfa/obj/wan",
    "chong" : "/d/qujing/qinfa/obj/chong",
  ]));
  setup();
  set_temp("no_guo",0);
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}

int buy_object (object who, string item)
{
  object me = this_object ();

  if (item != "guo" &&
      item != "yeshen guo")
  {
    return ::buy_object (who, item);
  }

  if (me->query_temp("no_guo"))
  {
    message_vision ("$N��$n˵�����Բ�����Ұ�ι���һ�������������\n",me,who);
    return -1;
  }
  me->set_temp("no_guo",1);
  remove_call_out("reset_no_guo");
  call_out("reset_no_guo",900);
  return ::buy_object (who, item);
}

void reset_no_guo ()
{
  set_temp("no_guo",0);
}
