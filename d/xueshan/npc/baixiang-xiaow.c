// baixiang-xiaow.c...weiqi, 97.09.15.

inherit NPC;

void create()
{
    set_name("����С��", ({"baixiang xiaowang", "baixiang", "xiaowang"}));
    set("title", "ʨ��ɽ");
    set("gender", "����" );
    set("age", 43);
    set("per", 112);//no rongmao description.
    set("str", 50);
    set("long", "��λ����С���������Ĵ���ʿ����ǰ��ʨ��ɽ����������\n"
        "����ʨ��ħ����Ī�档ʨ��ɽ���������������ʨ��ħһ��Ͷ������������\n"
        "���˻������ߡ�˭֪�������ѩɽ�Ժ�����ʱ���ƣ����ϵ���������ʨ��ħ��\n"
        "ת��Ͷ������������£��������������������ʨ�Ķ������ǣ�\n"
        "���ܿ�Ļ���˴��������Σ��ڴ�ѩɽ�У���������ˮ��\n"
        "˭�룬����ͻ�䣬��ȸ�����ع���ְѴ���������������ѹ��ȥ��\n"
        "����С����׼ʱ����ת�����ȸ����Ч�ң���һ�������˵�λ��\n"
        "�������Լ�ԭ�������������ƺŹ�����Խ�������������Ϊ������С������\n"
        "����ƽ����������˿�������������˾����ᡣ\n");
    set("class", "yaomo");
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    create_family("��ѩɽ", 2, "����");
    set_skill("unarmed", 150);
    set_skill("pressheart-hand", 80);
    set_skill("dodge", 60);
    set_skill("peripateticism", 70);
    set_skill("parry", 120);
    set_skill("blade", 110);
    set_skill("ice-blade", 120);
    set_skill("force", 90);
    set_skill("iceblood-force", 80);
    set_skill("literate", 70);
    set_skill("spells", 90);
    set_skill("dengxian-dafa", 80);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "pressheart-hand");
    map_skill("blade", "ice-blade");
    map_skill("dodge", "peripateticism");

    set("max_kee", 1200);
    set("max_sen", 600);
    set("force", 1600);
    set("max_force", 800);
    set("mana", 800);
    set("max_mana", 400);
    set("force_factor", 60);
    set("mana_factor", 20);

    set("eff_dx", -200000);
    set("nkgain", 400);

    set("cast_juanbi", -1);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
    }));

    setup();
    carry_object("/d/obj/armor/yinjia")->wear();
    carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("str") < 20) {
        command("kick " + ob->query("id"));
        command("say ���ߣ����ߣ���һ��������������˾�������\n");
        return;
    }

    if ((string)ob->query("family/family_name")=="��ѩɽ") {
        if ((int)ob->query("family/generation") < 2) {
            command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
        } else if ((int)ob->query("family/generation") == 2) {
            command("say �����" + RANK_D->query_rude(ob) + "������ǲ��үү���ˣ�\n");
        } else if ((int)ob->query("family/generation") == 3) {
            if ((string)ob->query("family/master_id") == "dapeng mingwang") {
                command("shake");
                command("say ����ô�����������µ�ͽ���ء�\n");
            } else {
                command(":D");
                command("say �����" + RANK_D->query_rude(ob) + "�ǲ��Ǳ�ʦ���ϳ����ˣ���үү�ҽ�������ã����������...\n");
                command("recruit " + ob->query("id") );
            }
        } else {
            if((int)ob->query("combat_exp") >= 50000){
                command(":D ");
                command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ���������ĺô���\n");
                command("recruit " + ob->query("id") );
            } else {
                command("say �㻹�������ģ���ѻ���������Űɡ�\n");
            }
        }
    } else {
        command("hmm");
        command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������ģ���ѻ�����������ɡ�\n");
    }

    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "yaomo");
}

void init()
{
    object ob = this_player();

    ::init();
    if ((string)ob->query("gender")=="����" && (int)ob->query("str") < 20 && random(3) > 1) {
        remove_call_out("greeting1");
        call_out("greeting1", 1, ob);
    }
    else if ((string)ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" && random(3) > 1) {
        remove_call_out("greeting2");
        call_out("greeting2", 1, ob);
    }
}

void greeting1(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    switch (random(1)) {
        case 0:
            command("kick " + ob->query("id"));
            command("say ���������");
            command("laugh");
            break;
    }
}

void greeting2(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    switch (random(1)) {
        case 0:
            command("fear " + ob->query("id"));
            command("say ��������");
            command("kick " + ob->query("id"));
            command("laugh");
            break;
    }
}
