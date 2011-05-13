// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;

void create()
{
    set_name("��ʨ��ħ", ({"qingshi laomo", "qingshi", "laomo"}));
    set("title", "��������");
    set("gender", "����" );
    set("age", 63);
    set("per", 112);//no rongmao description.

    set("long", "��λ��ʨ��ħԭ����ʨ��ɽ��ң���������������н��顣\n"
        "����ʨ��ɽ������ɽ���Ƕ���һλ�õ����˽���\n"
        "��ħ��Ͷ�������������˻������ߡ�һ���������г�\n"
        "һ������ʿ�г�Ҳ����֪�����ѡ�\n");
    set("class", "yaomo");
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    create_family("��ѩɽ", 2, "����");
    set_skill("unarmed", 150);
    set_skill("pressheart-hand", 80);
    set_skill("dodge", 90);
    set_skill("peripateticism", 100);
    set_skill("parry", 70);
    set_skill("blade", 120);
    set_skill("ice-blade", 110);
    set_skill("force", 90);
    set_skill("iceblood-force", 90);
    set_skill("literate", 70);
    set_skill("spells", 90);
    set_skill("dengxian-dafa", 120);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "pressheart-hand");
    map_skill("blade", "ice-blade");
    map_skill("dodge", "peripateticism");

   set("max_kee", 1000);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);
   set("force_factor", 60);
   set("mana_factor", 25);

   set("eff_dx", -200000);
   set("nkgain", 400);

   set("cast_tuntian", -1);
   set("chat_chance_combat", 50);
   set("chat_msg_combat", ({
            (: cast_spell, "tuntian" :),
   }));

   setup();
   carry_object("/d/obj/armor/jinjia")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name") == "��ѩɽ") {
        if ((int)ob->query("family/generation") < 2) {
            command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
        }
        else if ((int)ob->query("family/generation") == 2) {
            command("say �����" + RANK_D->query_rude(ob) + "������ǲ��үү���ˣ�\n");
        }
        else if ((int)ob->query("family/generation") == 3) {
            if ((string)ob->query("family/master_id") == "dapeng mingwang") {
                command("shake");
                command("say ���ã����ã����⻹Ƿ�Ŵ����������أ���ô��������ͽ�ܡ�\n");
            } else {
                command(":D");
                command("say �����" + RANK_D->query_rude(ob) + "�ϻ�ʦ���ɲ��ã���ʦ��Ҳ����ʲô��������...\n");
                command("recruit " + ob->query("id"));
            }
        } else {
            if ((int)ob->query("combat_exp") >= 50000) {
                command(":D ");
                command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ��Ժ�ɱ��ʨ��ɽ�������������Ѳɽ�󽫾���\n");
                command("recruit " + ob->query("id"));
            } else {
                command("say �㻹�������ģ���ѻ���������Űɡ�\n");
            }
        }
    } else {
        command("hmm");
        command("say ��λ" + RANK_D->query_respect(ob) + "��û���Ƽ����ҿɲ������㡣\n");
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
    if ((string)ob->query("family/family_name")=="����ɽ���Ƕ�"
    &&  (int)ob->query("combat_exp")  >= 100000) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    switch (random(1)) {
        case 0:
            command("kick " + ob->query("id"));
            command("say �����������������֣��ɸҸ���үү�Ҷ�һ����");
            command("fight " + ob->query("id"));
            break;
    }
}

