// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("��������", ({"beili daxian", "daxian"}));
  set("gender", "����");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 1100000);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("force", 160);
  set_skill("spells", 160);
  set_skill("unarmed", 160);
  set_skill("necromancy", 140);
  set_skill("tonsillit", 140);
  set_skill("ghost-steps", 140);
  set_skill("jienan-zhi", 140);
  set("con", 10);
  set("cor", 10);
  set("int", 10);
  set("per", 10);
  set("spi", 10);
  set("cps", 10);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "necromancy");

  set("eff_dx",-300000);
  set("nkgain",400);

  set("max_gin", 1200);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 1200);
  set("max_force", 1200);
  set("mana", 1200);
  set("max_mana", 1200);
  set("force_factor", 25);
  set("mana_factor", 80);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N����һ��̱�ڵ��ϣ�����һ����ɢ���޹ǡ�\n",
                  this_object());
  destruct(this_object());
}

void die()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N����һ��̱�ڵ��ϣ�����һ����ɢ���޹ǡ�\n",
                  this_object());
  destruct(this_object());
}

