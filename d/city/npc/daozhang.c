// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("��Ԩ����", ({"wuyuan daozhang", "wuyuan", "daozhang","taoist"}));
        set("age", 62);
        set("gender", "����");
        set("long",
"����۵����֣��������ɷ���ǣ�\n");
        set("attitude", "peaceful");
   set("class", "taoist");
        set("combat_exp", 180000);
        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("whip", 90);
   set_skill("force", 90);
   set_skill("spells", 80);
   set_skill("tao", 80);
   map_skill("spells", "tao");
        set("force", 400);
   set("max_force", 400);
   set("force_factor", 10);
   set("mana", 1000);
   set("max_mana", 600);
   set("mana_factor", 30);

   set("max_kee", 800);
   set("max_sen", 700);

        set("eff_dx", 80000);
        set("nkgain", 300);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :)
        }) );


   set("chat_chance", 1);
   set("chat_msg", ({
"��Ԩ����̾���������ѣ���������Ī�ѽ������У�\n",
}) );
        setup();
        carry_object("/d/obj/weapon/whip/fuchen")->wield();
        carry_object("/d/lingtai/obj/cloth")->wear();
}


