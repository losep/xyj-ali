// ALi by NewX

// minghe.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("ڤ������", ({"minghe laozu", "minghe", "laozu"}));
    set("long", "ڤ������������������ɱ��֮�棬���������˿���ȥȴ�����׶�֮����\n");
    set("gender", "����");
    set("class", "asura");
    set("title", "������֮��");
    set("age", 70);
    set("attitude", "friendly");
    set("shen_type", 1);
    set("per", 30);
    set("str", 30);
    set("int", 30+random(5));
    set("max_kee", 3000);
    set("max_gin", 2500);
    set("max_sen", 2000);

    set("force", 3500);
    set("max_force", 2000);
    set("force_factor", 120);
    set("max_mana", 2500);
    set("mana", 2000);
    set("mana_factor", 120);

    set("combat_exp", 2000000);
    set("nk_gain", 600);

    set_skill("unarmed", 150);
    set_skill("whip", 180);
    set_skill("hellfire-whip", 200);
    set_skill("dodge", 180);
    set_skill("parry", 150);
    set_skill("literate", 130);
    set_skill("spells", 180);
    set_skill("force", 180);
    set_skill("tonsillit", 130);
    set_skill("ghost-steps", 180);
    set_skill("necromancy", 150);
    set_skill("jinghun-zhang", 150);
    set_skill("stick", 180);
    set_skill("kusang-bang", 180);
    set_skill("sword", 180);
    set_skill("zhuihun-sword", 180);

    map_skill("force", "tonsillit");
    map_skill("unarmed", "jinghun-zhang");
    map_skill("dodge", "ghost-steps");
    map_skill("spells", "necromancy");
    map_skill("parry", "hellfire-whip");
    map_skill("whip", "hellfire-whip");
    map_skill("stick", "kusang-bang");
    map_skill("sword", "zhuihun-sword");

    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
            (: exert_function, "powerup" :),
            (: exert_function, "recover" :),
            (: cast_spell, "gouhun" :),
            (: perform_action, "whip", "three" :),
    }) );

    set_temp("apply/armor", 50);
    set_temp("apply/dodge", 50);

    create_family("���޽�", 1, "����");
    setup();

    carry_object("/d/obj/cloth/baipao")->wear();
    carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

void attempt_apprentice(object ob, object me)
{
    if ((int)ob->query("combat_exp") < 150000) {
        command("say " + RANK_D->query_rude(ob) + "�������è�İ�ʽҲ�ҵ������ﶪ�����ۣ�");
        return;
    }
    if (((int)ob->query("MKS")+ob->query("PKS") * 2) < 200
    ||  (int)ob->query("bellicosity") < 200) {
        command("say ɱ����ô�٣����ҵ����ˡ�");
        return;
    }
    command("grin");
    command("say ������ǰ;��");
    command("recruit " + ob->query("id"));
    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "asura");
}
