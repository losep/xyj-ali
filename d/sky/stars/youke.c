//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("�ο�",({"star youke","youke","star"}));
  set("gender", "����");
  set("title", "��ľ�ǹ�");
  set("age", 73);
  set("long", "    \n�ֹ�����  ���Ͻ�����������ְ˳\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1451258);
  set("kee", 1395);
  set("max_kee", 1395);
  set("sen", 1851);
  set("max_sen", 1851);
  set("force", 6519);
  set("max_force", 3260);
  set("mana", 7501);
  set("max_mana", 3751);
  set("force_factor", 140);
  set("mana_factor", 188);
  set("str", 21);
  set("per", 10);

setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/ring")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="ring";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","ľ��");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"����"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��ָ"NOR);
}

