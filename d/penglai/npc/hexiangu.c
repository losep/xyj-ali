// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hexiangu.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
    set_name("���ɹ�", ({"he xiangu", "he", "xiangu"}));
    //set("title", "");
    set("nickname", "����֮һ");
    set("gender", "Ů��" );
    set("age", 25);
    set("per", 20);
    set("long", "���ɹ��ǰ�����Ψһ��Ů�ԣ������������˶����չ�����\n");
    set("class", "xian");
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set_skill("unarmed", 60);
    set_skill("wuxing-quan", 60);
    set_skill("dodge", 80);
    set_skill("baguazhen", 80);
    set_skill("parry", 80);
    set_skill("sword", 90);
    set_skill("xiaofeng-sword", 100);
    set_skill("force", 70);   
    set_skill("zhenyuan-force", 70);
    set_skill("literate", 50);
    set_skill("spells", 80);
    set_skill("taiyi", 80);
    map_skill("spells", "taiyi");
    map_skill("force", "zhenyuan-force");
    map_skill("unarmed", "wuxing-quan");
    map_skill("sword", "xiaofeng-sword");
    map_skill("dodge", "baguazhen");
    
    set("max_kee", 500);
    set("max_sen", 500);
    set("force", 1000);
    set("max_force", 800);
    set("mana", 1600);
    set("max_mana", 800);   
    set("force_factor", 40);
    set("mana_factor", 40);
    
    setup();
    carry_object("/d/obj/cloth/skirt")->wear();
    carry_object("/d/obj/cloth/shoes")->wear();
    carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}
