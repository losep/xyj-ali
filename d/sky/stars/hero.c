//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����Ӣ��",({"star hero","hero","star"}));
  set("gender", "����");
  set("title", "��ˮ�ǹ�");
  set("age", 46);
  set ("long", @LONG
������:
-------------------------------------------------------------------------
����33 : ���� 303.33.3, ���һս��ʱ33m, Ȼ��� green ���  :)
����46 : �����޳ɲ����ֻ�, �����ϲ���  :D
����53 : ��������������ն�Ľ�����, ����ѧѧ���ֺ���(��������Ļ�)  :P
-------------------------------------------------------------------------
LONG);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1564041);
  set("kee", 1221);
  set("max_kee", 1221);
  set("sen", 1770);
  set("max_sen", 1770);
  set("force", 5133);
  set("max_force", 2567);
  set("mana", 6101);
  set("max_mana", 3051);
  set("force_factor", 140);
  set("mana_factor", 153);
  set("str", 25);
  set("per", 15);

setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"Ӣ�۰�"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"Ӣ��ս��"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"ս��"NOR);
}

