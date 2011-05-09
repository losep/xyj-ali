// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("��߸", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "��̳����֮��");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set("class", "xian");
  set("long", "һλ����ݰ׵������ꡣ\n");
  set("gender", "����");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "С̫��");
  set("rank_info/rude", "���δ�ɵ�С��");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 1800);
  set("max_gin", 1800);
  set("max_sen", 1800);
  set("force", 2600);
  set("max_force", 2600);
  set("force_factor", 100);
  set("max_mana", 2700);
  set("mana", 2700);
  set("mana_factor", 120);
  set("combat_exp", 1200000);
  set_skill("spells", 180);
  set_skill("tao", 180);
  set_skill("unarmed", 170);
  set_skill("yinfeng-claw", 170);
  set_skill("dodge", 180);
  set_skill("lingfu-steps", 170);
  set_skill("parry", 190);
  set_skill("force", 180);
  set_skill("huntian-force", 170);
  set_skill("spear", 170);
  set_skill("huoyun-qiang", 150);
  set_skill("blade", 170);
  set_skill("sword", 160);
  map_skill("spells", "tao");
  map_skill("unarmed", "yinfeng-claw");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-force");
  set("inquiry", ([
   "name": "��������������̫����߸��Ҳ��",
   "here": "������������������",
   "rumors": "���뷷����Ϊ��ħ��Ԫ˧������Ϊ��̳����֮��ר�ܽ�����ħ��",
   "����": "�޵׶������󾫣������ҵ�����Ů��",
   ]));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-ling");
  else
    carry_object("/d/obj/fabao/huntian-fake");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-quan");
  else
    carry_object("/d/obj/fabao/qiankun-fake");
}

void attempt_apprentice(object ob)
{
  command("say �������С��ͽ�����ǲ��յġ�");
  if ((string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�") {
   command("say "+RANK_D->query_respect(ob)+"��Ը��ѧ�����������ӵķ��ϣ��ҵ����Ե㲦һ����");
  }
  else {
   command("sorry");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "tao") {
   if(myyaofa!=0) {
     command("sigh");
     command("say "+RANK_D->query_respect(me)+"����̫�أ�����ѧ�����ɷ���");
     return 1;
   }
  }
  return 0;
}

