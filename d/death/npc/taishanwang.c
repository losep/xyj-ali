// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("̩ɽ��", ({"taishan wang", "wang", "taishan"}));
       set("title", "����ʮ��֮");
   set("class", "ghost");
       set("gender", "����");
       set("age", 100);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 20);
       set("combat_exp", 700000);
   set_skill("spells", 100);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
   set_skill("necromancy", 100);
   set_skill("tonsillit", 100);
   map_skill("force", "tonsillit");
   map_skill("spells", "necromancy");

create_family("���޵ظ�", 2, "���");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

