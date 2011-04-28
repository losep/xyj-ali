// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhangguolao.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
    set_name("�Ź���", ({"zhang guolao", "zhang", "guolao"}));
    //set("title", "");
    set("nickname", "����֮һ");
    set("gender", "����" );
    set("age", 50);
    set("per", 20);
    set("long", "һλЦ�����Ļ�����ͷ��\n");
    set("class", "xian");
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set_skill("unarmed", 60);
    set_skill("wuxing-quan", 60);
    set_skill("dodge", 80);
    set_skill("baguazhen", 70);
    set_skill("parry", 80);
    set_skill("hammer", 90);
    set_skill("liuhe-chui", 100);
    set_skill("force", 70);   
    set_skill("zhenyuan-force", 70);
    set_skill("literate", 50);
    set_skill("spells", 80);
    set_skill("taiyi", 80);
    map_skill("spells", "taiyi");
    map_skill("force", "zhenyuan-force");
    map_skill("unarmed", "wuxing-quan");
    map_skill("hammer", "liuhe-chui");
    map_skill("dodge", "baguazhen");

    set("max_kee", 500);
    set("max_sen", 500);
    set("force", 1000);
    set("max_force", 800);
    set("mana", 1600);
    set("max_mana", 800);   
    set("force_factor", 40);
    set("mana_factor", 40);

    set("chat_chance", 10);
    set("inquiry", ([
        "name" : "�Ǻǣ��Ź�����Ҳ��\n",
        "here" : "��������ˣ����汻���ʵ��ˡ�\n",
        ]) );

    set("chat_msg", ({
        "�Ź�����������Ц�˼�����\n",   
        "�Ź�������ƺ�«�ֹ���һ�ڣ�������������졣\n",
        "�Ź��ϴ��˸���ָ���������ҵ�Сë¿����������\n",
        (: random_move :)
    }) );

    set("maolu", 0);
    
    setup();
    carry_object("/d/obj/cloth/linen")->wear();
    carry_object("/d/obj/cloth/pobuxie")->wear();
    carry_object("/d/obj/weapon/hammer/jiuhulu")->wield();
}

void init()
{
    object ob=this_player();
    object me=this_object();
    
    ::init();

    if (query("maolu") == 0) {
        call_out("qi_maolu", 1);
        set("maolu", 1);
    }
}

void qi_maolu()
{
    object maolu;
    
    maolu = new(__DIR__"xiaomaolu.c");
    maolu->move(environment(this_object()));
    command("mount maolu");
    return;   
}
