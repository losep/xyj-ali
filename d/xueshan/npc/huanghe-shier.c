// ALi by NewX

inherit NPC;

void create()
{
    set_name("�ƺ��̶�", ({"huanghe shier", "shier", "huanghe"}));
    set("gender", "Ů��" );
    set("age", 22);

    set("long", "��ȸ��������������ͷ�졣\n");
    set("class", "avian");
    set("combat_exp", 35000);
    set("daoxing", 35000);

    set("attitude", "heroism");
    create_family("��ѩɽ", 3, "����");
    set_skill("unarmed", 40);
    set_skill("raptor-talon", 50);
    set_skill("pressheart-hand", 50);
    set_skill("dodge", 60);
    set_skill("peripateticism", 60);
    set_skill("parry", 60);
    set_skill("sword", 60);
    set_skill("avian-sword", 60);
    set_skill("throwing", 80);
    set_skill("force", 61);
    set_skill("iceblood-force", 60);
    set_skill("literate", 80);
    set_skill("spells", 70);
    set_skill("dengxian-dafa", 60);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "raptor-talon");
    map_skill("sword", "avian-sword");
    map_skill("parry", "avian-sword");

    set("max_kee", 300);
    set("max_sen", 300);
    set("force", 300);
    set("max_force", 300);
    set("mana", 300);
    set("max_mana", 300);
    set("force_factor", 15);
    set("mana_factor", 15);

    set("inquiry", ([
        "here" : "����Ǵ�ѩɽ����\n",
    ]) );

    setup();

    carry_object("/d/obj/cloth/xueshan-pao")->wear();
    carry_object("/d/obj/armor/tenjia")->wear();
    carry_object("/d/obj/weapon/sword/peijian")->wield();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("gender") != "Ů��") {
        command("shake");
        command("say ������������ֻ��Ů���ӡ�");
        command("say " + RANK_D->query_respect(ob) + "һ�������ˣ����²�̫������̹����ɡ�");
    } else if ((string)ob->query("family/family_name") == "��ѩɽ") {
        if ((int)ob->query("family/generation") < 3)
            command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
        else if ((int)ob->query("family/generation") == 3)
            command("say �����" + RANK_D->query_rude(ob) + "������ǲ�������ˣ�\n");
        else {
            command("ok");
            command("say " + RANK_D->query_respect(ob) + "Ͷ���ҵ����£���Ҫ����������ʦ���Ļ�������ĺÿ���\n");
            command("recruit " + ob->query("id") );
        }
    } else {
        command(":D ");
        command("say �ã�"+ RANK_D->query_respect(ob) +"���㵽�Ҵ�ѩɽ����Ѳɽ�Ŀ�ʼ���������ܳ���ͷ�ڣ�\n");
        command("recruit " + ob->query("id") );
    }

    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob)) {
        ob->set("class", "avian");
        ob->set("title", "��ѩɽ��ȸ������������");
    }
}
