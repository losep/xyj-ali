//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star lovesky","lovesky","star"}));
  set("gender", "����");
  set("title", "��ˮ�ǹ�");
  set("age", 51);
  set("long", "    \n������,��ȡ����Ի:�����б�����ʦ֮��.\n");

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 1546018);
  set("kee", 1043);
  set("max_kee", 1043);
  set("sen", 1785);
  set("max_sen", 1785);
  set("force", 3959);
  set("max_force", 1980);
  set("mana", 7179);
  set("max_mana", 3590);
  set("force_factor", 98);
  set("mana_factor", 180);
  set("str", 31);
  set("per", 11);

setup();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"������"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"������"NOR);
}

