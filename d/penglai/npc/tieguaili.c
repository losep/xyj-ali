// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tieguaili.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
    set_name("������", ({"tieguai li", "tieguai", "li"}));
    //set("title", "");
    set("nickname", "����֮һ");
    set("gender", "����" );
    set("age", 42);
    set("per", 12);
    set("long", "���ŵ�һ˫�ò�Ь������һ�����û�˱�����Ŀ�����ۣ���������ߵ�С����һ��������̬��\n");
    set("class", "xian");
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set_skill("unarmed", 60);
    set_skill("wuxing-quan", 60);
    set_skill("dodge", 80);
    set_skill("baguazhen", 80);
    set_skill("parry", 80);
    set_skill("staff", 90);
    set_skill("fumo-zhang", 100);
    set_skill("force", 70);   
    set_skill("zhenyuan-force", 70);
    set_skill("literate", 20);
    set_skill("spells", 80);
    set_skill("taiyi", 80);
    map_skill("spells", "taiyi");
    map_skill("force", "zhenyuan-force");
    map_skill("unarmed", "wuxing-quan");
    map_skill("staff", "fumo-zhang");
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
    carry_object("/d/obj/cloth/pobuyi")->wear();
    carry_object("/d/obj/cloth/lancaoxie")->wear();
    carry_object("/d/obj/weapon/staff/tieguai")->wield();
}
