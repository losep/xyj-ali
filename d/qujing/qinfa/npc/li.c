// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997


inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("��Ѹ�", ({"li guafu", "li", "guafu", "fu"}));
  set("gender", "Ů��");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "choupao" : "/d/obj/cloth/choupao",
    "magua" : "/d/obj/cloth/magua",
    "ziyi" : "/d/obj/cloth/ziyi",
    "hat" : "/d/obj/cloth/hat",
    "buxie" : "/d/obj/cloth/buxie",
  ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}
