//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("���",({"star erica","erica","star"}));
  set("gender", "Ů��");
  set("title", "Σ���ǹ�");
  set("age", 47);
  set("long", "    \nһ�ж��Ƕ��ݵ�û�н���ȴ��Ҫ��ʼ��\nһ���ֶ���������û��ֹͣȴҲ������ɡ�\nΪ�˷�����������������Ҳ��ֻ��ʧȥ������ʧȥ��Ҳֻ�ܻӻ���˵���ټ�ȴ��\n�޾��׵�˲�䣬��㾭���̻��Ÿе�һ��ͻ�������ı�����\n�κε�·��ѡ��ֻ����ζ��ѡ��������·�Ĳ��ٿ��ܡ�\n���ս��¶���\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1335792);
  set("kee", 1185);
  set("max_kee", 1185);
  set("sen", 1869);
  set("max_sen", 1869);
  set("force", 5099);
  set("max_force", 2550);
  set("mana", 7099);
  set("max_mana", 3550);
  set("force_factor", 115);
  set("mana_factor", 178);
  set("str", 21);
  set("per", 22);

setup();
carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"��"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"��������"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��������"NOR);
}

