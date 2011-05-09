// kongque-gongzhu.c...weiqi, 97.09.15.

inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
    set_name("��ȸ����", ({"kongque gongzhu", "kongque", "gongzhu"}));
    set("title", "��������");
    set("gender", "Ů��" );
    set("age", 23);
    set("per", 21);

    set("long", "��ȸ�����˿�ȸ������Ů������ȸ��������������Ѻ����ɽ��\n"
        "���ɴ�������һ�ִ���˵��ֶŮ�����������ʵ���и�Ů֮�顣\n");
    set("class", "yaomo");
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    create_family("��ѩɽ", 3, "����");
    set_skill("unarmed", 70);
    set_skill("pressheart-hand", 70);
    set_skill("dodge", 90);
    set_skill("peripateticism", 120);
    set_skill("parry", 70);
    set_skill("throwing", 100);
    set_skill("sword", 90);
    set_skill("avian-sword", 120);
    set_skill("force", 90);
    set_skill("iceblood-force", 90);
    set_skill("literate", 90);
    set_skill("spells", 80);
    set_skill("dengxian-dafa", 90);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "pressheart-hand");
    map_skill("sword", "avian-sword");
    map_skill("dodge", "peripateticism");

    set("max_kee", 1000);
    set("max_sen", 600);
    set("force", 1600);
    set("max_force", 800);
    set("mana", 1000);
    set("max_mana", 500);
    set("force_factor", 60);
    set("mana_factor", 25);

    set("eff_dx", -200000);
    set("nkgain", 400);

    setup();
    carry_object("/d/obj/cloth/nihong-yuyi")->wear();
    carry_object("/d/obj/cloth/shoes")->wear();
    carry_object("/d/obj/weapon/sword/fenghuang-qin")->wield();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name") == "��ѩɽ") {
        if ((int)ob->query("family/generation") < 3) {
            command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
        } else if ((int)ob->query("family/generation") == 3) {
            command("say �����" + RANK_D->query_respect(ob) + "�ͱ�����ǲСŮ���ˣ�\n");
        } else {
            if ((int)ob->query("combat_exp") >= 50000) {
                command(":) ");
                command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ������СŮ�ӣ�СŮ�Ӷ�Ȼ���Ĵ��ڣ�\n");
                command("recruit " + ob->query("id") );
            } else {
                command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������ģ���ѻ���������Űɡ�\n");
            }
        }
    } else {
        command("hmm ");
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
    object ob, me;

    me = this_player();

    ::init();

    set("chat_chance", 10);
    set("inquiry", ([
        "name" : "�������㡣\n",
        "here" : "�㻹û����...������������\n", 
        "������" : (: get_ice :),
        "��������" : (: get_ice :),
        "����" : (: get_ice :),
    ]) );

    set("chat_msg", ({
        "��ȸ����̾�˿�����\n",   
        "��ȸ���������������Ҳ��֪������Ĳ�ʲôʱ���ܺá�\n",
        "��ȸ����������ü������˵���ֲ���ů��������ô����Ϊ�������������أ�\n",
        "��ȸ������̾�˿�����������ô�û����ɣ��϶������ʲô...��ô�໨�ݻ�����ȥҲû��ѽ��\n",
        "��ȸ���������������������Ū�������������´��²����ˡ�\n",        
    }));

    if ((string)me->query("gender") == "����" && (int)me->query("per") > 25 && random(3) > 1) {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
    }

}

void greeting(object me)
{
    if (!me || environment(me) != environment()) return;

    switch (random(1)) {
        case 0:
            //command("look " + me->query("id"));
            //command("blush ");
            break;
    }
}

string get_ice(object me)
{
    object env;

    me = this_player();
    env = environment(this_object());

    if (me->query_temp("ice_given") && (string)env->query("short") == "Сľ��" && (string)me->query("family/family_name") == "��ѩɽ") {
        me->delete_temp("ice_given");
        command("whisper " + me->query("id") + " ��Ȼ����������������ȥ��\n");
        message_vision("ֻ����ȸ�������������ӵ��°���һ����\n", me);
        env->open_down();
        return "����ʱ��һ��ǽ���ɡ�\n";
    } else {
        return "�������������Ҷ��壬�Ҷ�����Ǵ���������\n";
    }
}

int accept_object(object me, object ob)
{
    if ((string)ob->query("id") != "lan bingkuai"
    &&  (string)ob->query("id") != "shuangse bing") {
        command("say ��λ" + RANK_D->query_respect(me) + "�ͱ��СŮ�ӵ����ˡ�");
        command("sigh ");
        //command("drop " + ob->query("id"));
        //this does not work due to time problem...
        //have to use call_out().
        call_out("do_drop", 1, ob);
        return 1;
    } else {
        command("ah ");
        command("jump ");
        command("say ��λ" + RANK_D->query_respect(me) + "���������ˣ�");
        command("whisper " + me->query("id") + " ���Ҹ�����һ�������ܣ�\n    �Ҷ������ڸ����Ͳ��ڱ���������ú�����������Ҫ���ֺ�����");
        me->set_temp("ice_given", 1);
        return 1;
    }
}

void do_drop(object ob)
{
    command("drop "+ob->query("id"));
}
