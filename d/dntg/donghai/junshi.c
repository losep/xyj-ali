inherit NPC;

void create()
{
    set_name("��ʿ",({"wu shi","shi"}));
    set("gender", "����");
    set("title", "������");
    set("age", 25);
    set("long", "һ������������ʿ����������Ĳ�����\n");

    set("attitude", "heroism");
    set("combat_exp", 25000);

    set("kee", 400);
    set("max_kee", 400);
    set("sen", 420);
    set("max_sen", 420);
    set("force", 350);
    set("max_force", 350);
    set("mana", 100);
    set("max_mana", 100);
    set("force_factor", 15);
    set("mana_factor", 0);

    set_skill("dodge", 50);
    set_skill("spells", 30);
    set_skill("unarmed", 50);
    set_skill("parry", 50);
    set_skill("spear", 30);

    set("chat_chance", 5);
    set("chat_msg", ({
        "һ����ʿ�ڳ�������Ѵ�ǹˣ�û�����ڣ�������ΧһƬ�Ȳʡ�",
        "��ʿ�Ǿ۾�����Ĳ����Ŷ��У���ϧʼ�նԲ���ֱ�ߡ�",
        "������ʿ�ڳ������붣�������ĶԴ򣬱�����Ȼ���У�ȴ�۵���ͷ�󺹡�",
    }));

    setup();

    carry_object("/d/obj/weapon/spear/tieqiang")->wield();
    carry_object("/d/obj/cloth/bingfu")->wear();
}
