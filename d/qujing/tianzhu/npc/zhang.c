// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997


inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("张妈", ({"zhang ma", "zhang", "ma"}));
  set("gender", "女性");
  set("combat_exp", 3000);
  set("age", 35);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("vendor_goods", ([
        "bailangua": "/d/qujing/tianzhu/obj/bailangua",
        "mugua": "/d/qujing/tianzhu/obj/mugua",
        "fanmugua": "/d/qujing/tianzhu/obj/fanmugua",
        "juzi": "/d/qujing/tianzhu/obj/juzi",
        "ganzi": "/d/qujing/tianzhu/obj/ganzi",
        "youzi": "/d/qujing/tianzhu/obj/youzi",
      ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/tianzhu/obj/baojie")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

