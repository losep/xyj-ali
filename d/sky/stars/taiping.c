//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("̫ƽ����",({"star taiping","taiping","star"}));
  set("gender", "����");
  set("title", "��ˮ�ǹ�");
  set("age", 53);
  set("long", "    \n����ɽ���Ƕ�����������  ̫ƽ����(Taiping)\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1491193);
  set("kee", 1248);
  set("max_kee", 1248);
  set("sen", 1764);
  set("max_sen", 1764);
  set("force", 5345);
  set("max_force", 2673);
  set("mana", 6565);
  set("max_mana", 3283);
  set("force_factor", 140);
  set("mana_factor", 165);
  set("str", 16);
  set("per", 27);

setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/ring")->wear();
carry_object(__DIR__"obj/shoes")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="ring",armor2_id="shoes";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"̫ƽ����"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"̫ƽ�ֱ�"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"̫ƽ��ѥ"NOR);
}
