// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("�𶥴���", ({ "jinding daxian", "jinding", "daxian" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 100);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 80);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1000000);
  set_skill("spells", 120);
  set_skill("taoism", 120);
  set_skill("unarmed", 120);
  set_skill("puti-zhi", 120);
  set_skill("dodge", 120);
  set_skill("cloud-steps", 120);
  set_skill("parry", 120);
  set_skill("force", 120);
  set_skill("azoth-force", 120);
  set_skill("staff", 120);
  map_skill("spells", "taoism");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "cloud-steps");
  map_skill("force", "azoth-force");

  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

