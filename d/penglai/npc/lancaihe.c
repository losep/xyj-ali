// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
    set_name("���ɺ�", ({"lan caihe", "lan", "caihe"}));
    set("title", "����֮");
    set("gender", "����");
    set("age", 18);
    set("per", 20);
    set("long", "һλ������Ƶ����ꡣ\n");
    set("class", "xian");
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set_skill("unarmed", 60);
    set_skill("wuxing-quan", 60);
    set_skill("dodge", 80);
    set_skill("bagua-zhen", 80);
    set_skill("parry", 80);
    set_skill("sword", 90);
    set_skill("xiaofeng-sword", 100);
    set_skill("force", 70);   
    set_skill("zhenyuan-force", 70);
    set_skill("literate", 80);
    set_skill("spells", 80);
    set_skill("taiyi", 80);
    map_skill("spells", "taiyi");
    map_skill("force", "zhenyuan-force");
    map_skill("unarmed", "wuxing-quan");
    map_skill("sword", "xiaofeng-sword");
    map_skill("dodge", "bagua-zhen");
    
    set("max_kee", 500);
    set("max_sen", 500);
    set("force", 1000);
    set("max_force", 800);
    set("mana", 1600);
    set("max_mana", 800);   
    set("force_factor", 40);
    set("mana_factor", 40);
    
    setup();
    carry_object("/d/obj/cloth/linen")->wear();
    carry_object("/d/obj/weapon/sword/zhuban")->wield();
}
