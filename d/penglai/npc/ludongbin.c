// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ludongbin.c...weiqi, 98.02.24.

string give_book();
string ask_jinguzhou();

inherit NPC;
void create()
{
    set_name("������", ({"lu dongbin", "lu", "dongbin"}));
    set("title", "����֮");
    set("nickname", "������");
    set("gender", "����" );
    set("age", 35);
    set("per", 30);
    set("long", "����������������Ȼ�㲻��ǿ�ߣ���������������ȴʵ�ڴ�Ĳ����ˣ��Ĳɷ�����ɫ�����졣\n");
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
    set_skill("literate", 120);
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

    set("inquiry", ([
        "name" : "��ׯ�۴�������Ҳ��\n",
        "here" : "���ںδ����������ӡ�\n",
        "rumors": (: ask_jinguzhou :),
        "�ĵ�" : (: give_book :),      
        "�����ĵ�" : (: give_book :),
    ]) );

    set("no_book", 0);

    setup();
    carry_object("/d/obj/cloth/xianpao")->wear();
    carry_object("/d/obj/weapon/sword/changjian")->wield();
}

string give_book()
{
    object me = this_player();

    if (query("no_book") == 0)
    {
        carry_object("/d/obj/book/chunyang");
        command("give xinde to " + me->query("id"));
        set("no_book", 1);
        return "������˵�����ã���Ȼ�������ˣ����Ҿ͸���ɡ�\n";
    }
    else
    {
        return "������˵����̫�����ˣ����Ѿ������ˡ�\n";
    }
}

string ask_jinguzhou()
{
    if (this_player() -> query_temp("aware_of_jinguzhou")) 
        return "��������˵������ô�����ʣ�\n";
    this_player() -> set_temp("aware_of_jinguzhou", 1);
    command("whisper " + this_player() -> query("id") 
        + " ��˵������������������͵Ľ����䡣");
    return "��Ե�ߵ�֮����Ե����֮���Ϳ����ĸ����ˡ�\n";
}
