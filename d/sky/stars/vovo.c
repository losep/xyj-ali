//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star vovo","vovo","star"}));
  set("gender", "����");
  set("title", "�����ǹ�");
  set("age", 0);
  set("long", "    \n����ԡ�����������أ���Ȼ���������쳤����\n����������٣����о�ʱ�����߳�����Ϊ���ҡ�\n��������������־��ǧ���ʿĺ�꣬׳�Ĳ��ѡ�\n����ӯ��֮�ڣ��������죻����֮�����ɵ����ꡣ\n��ӭ��������ף���������ˮ���ţ�ֻ��������Ӣ��������˭��\n");

  set("attitude", "heroism");
  set("class", "fighter");
  set("combat_exp", 726749);
  set("kee", 732);
  set("max_kee", 732);
  set("sen", 106);
  set("max_sen", 106);
  set("force", 1239);
  set("max_force", 620);
  set("mana", 3859);
  set("max_mana", 1930);
  set("force_factor", 31);
  set("mana_factor", 97);
  set("str", 21);
  set("per", 28);

setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/spear")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="spear";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","С�ײˡءء�");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","��С���š��");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","ͭ��ѡѡѡ�");
}
