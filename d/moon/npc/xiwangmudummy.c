// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//xiwangmufake.c
inherit NPC;
inherit F_MASTER;

string miekou();

void create()
{
        set_name("����ĸ", ({"xi wangmu", "xi", "wangmu","master"}));
        set("long", "����������������������������ء�\n");
        set("title", "�¹���ʦ");
        set("gender", "Ů��");
        set("age", 100);
        set("class","xian");
        set("attitude", "friendly");
        set("rank_info/respect", "��̫̫");
        set("cor", 30);
        set("per", 30);
        set("looking", "�޾���ɣ���̬ľګ��");
        set("max_kee", 4500);
        set("max_gin", 800);
        set("max_sen", 4500);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 125);
        set("max_mana", 2000);
        set("mana", 4000);
        set("mana_factor", 100);
        set("combat_exp", 2000000);
        set_skill("literate", 150);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("spells", 180);
        set_skill("moonshentong", 180);
        set_skill("baihua-zhang", 180);
        set_skill("moonforce", 180);
        set_skill("snowsword", 200);
        set_skill("moondance", 150);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
        set("inquiry", ([
            "槼�": (: miekou :),
            "��ԯ��Ĺ": (: miekou :),
        ]));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: cast_spell, "arrow" :),
        }) );

        create_family("�¹�", 1, "��");
        setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{
    if (!((string)ob->query("gender") == "Ů��")) {
        command("shake");
        command("say �����¹�ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
        return;
    }

    if ((string)ob->query("family/family_name") == "�¹�") {
        if (((int)ob->query("combat_exp") < 100000)) {
            command("say " + RANK_D->query_respect(ob) +
                "�ĵ��в��������Щ��ѧ�ط�������������\n");
            return;
        }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
            "���Ŭ�����������¹�������\n");
        command("recruit " + ob->query("id") );
        return;
    }
    
    command("shake");
    command("say " + RANK_D->query_respect(ob) +
        "������ȥѧЩ��������ɡ�\n");
    return;
}

int accept_fight(object me)
{
    return 0;
}

string miekou()
{
    object who, here, there;
    who = this_player();
    here = environment();
    there = load_object("/d/gumu/dajiroom");
    message_vision(this_object()->name() + "��ʱ��ɫһ�䣬�����г�һ��������ס��$N\n", who);
    who->move(there);
    tell_room(here, "����ɢȥ��" + who->name() + "�����ˡ�\n��" + this_object()->name() + "ȴ¶�����ص�Ц�ݡ�\n");
    tell_object(who, "����ɢȥ���㷢���Լ�����һ��İ���ĵط���\n");
    tell_room(there, "��Ȼ��һ����������" + who->name() + "���������\n", who);
    return "������Ӱ�����Ҳ������ʵ��𣿺Ǻǡ�����";
}
