// wuya-guai.c...weiqi, 97.09.15.

inherit NPC;

string give_map(object me);
string help_fly(object me);
int do_yes(string arg);

void create()
{
    set_name("��ѻ����", ({"wuya xianshen", "wuya", "xianshen"}));
    set("gender", "����");
    set("age", 43);
    set("per", 112);//no rongmao description.

    set("long", "��λ��ѻ��������ңԶ�Ĵ�ѩɽ�����Ǵ����������������ĸ���֮һ��\n"
        "��Զ���������߽��˲ŷ��������ų�����һ����ѻ�졣\n");
    set("class", "avian");
    set("combat_exp", 100000);
    set("attitude", "peaceful");
    create_family("��ѩɽ", 3, "����");
    set_skill("unarmed", 50);
    set_skill("raptor-talon", 50);
    set_skill("pressheart-hand", 20);
    set_skill("dodge", 50);
    set_skill("peripateticism", 50);
    set_skill("parry", 50);
    set_skill("blade", 50);
    set_skill("ice-blade", 50);
    set_skill("force", 50);
    set_skill("iceblood-force", 50);
    set_skill("literate", 30);
    set_skill("spells", 50);
    set_skill("dengxian-dafa", 50);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "raptor-talon");
    map_skill("blade", "ice-blade");
    map_skill("dodge", "peripateticism");

    set("max_kee", 500);
    set("max_sen", 400);
    set("force", 400);
    set("max_force", 400);
    set("mana", 500);
    set("max_mana", 400);
    set("force_factor", 35);
    set("mana_factor", 20);

    set("eff_dx", -25000);
    set("nkgain", 150);

    set("inquiry", ([
        "name" : "��ʲô�ʣ������۾��ǿ��ģ������Դ�����ġ�\n",
        "here" : "�����أ������Ȳ������Ǵ�ѩɽ��\n",
        "��ôȥ" : "�ɹ�ȥ��죬��Ҳ�ܵ���\n",
        "��ô��" : "�����Ǵ�����ɽ�����ߡ�\n",
        "��ô��" : (: help_fly :),
        "��ѩɽ" : (: give_map :),
    ]) );

    set("no_map", 0);

    setup();
    carry_object("/d/obj/cloth/xueshan-pao")->wear();
    carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name")=="��ѩɽ") {
        if ((int)ob->query("family/generation") < 3) {
            command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
        } else if ((int)ob->query("family/generation") == 3) {
            command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ү���ˣ�\n");
        } else {
            command(":D");
            command("say �����" + RANK_D->query_rude(ob) + "��͸�������Ϊʦ�����Ǹ���ʦ��ʲô������...\n");
            command("recruit " + ob->query("id"));
        }
    } else {
        command(":D ");
        command("say �ã������Ǵ�ѩɽ��ѧ�գ������˸���ʦ����ֻҪ�ܻ�������" + RANK_D->query_respect(ob) + "����˵��ǰ;��������\n");
        command("recruit " + ob->query("id"));
    }

    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "avian");
}

string help_fly(object me)
{
    me=this_player();
    if (me->query("combat_exp")<30000) {
/*
        message_vision("��ѻ�����������Ͼͽ����...�����۾���\n", me);
        message_vision("ֻ����ѻ����������߶�˼��䣬һ������$N��ƨ�ɣ�$N���Ƽ������˳�ȥ...\n", me);
        me->move("/d/xueshan/binggu");
        tell_room(environment(me),"ֻ����ž��һ����һ���˴ӿ��зɹ�����������ˤ�ڵ��ϡ�\n", ({me}));
        return "�ٺ٣�\n";
*/
        return "�Ͻ�ѧ�ɣ�\n";
    } else {
        return "������ͷ�Բ����ѣ���ˤ���ˣ�\n";
    }
}

string give_map(object me)
{
    me=this_player();
    me->set_temp("need_map", 1);
    me->start_call_out((: call_other, me, "set_temp", "need_map", 0 :), 10);
    return "��ѩɽ���ǿ��Ǹ��õط�������ȥ��(yes)��\n";
}

void init()
{
    add_action("do_yes", "yes");
}

int do_yes(string arg)
{
    object me;

    me=this_player();
    
    if (me->query_temp("need_map")) {
        message_vision("$N�������ȥ��\n\n", me);
        if (query("no_map") == 0) {
            message_vision("��ѻ����˵�����ã����Ҹ���һ�ŵ�ͼ�ɣ�\n", me);
            me->set_temp("need_map", 0);

            carry_object("/d/xueshan/obj/xueshan-map");
            command("give xueshan map to " + me->query("id"));
            set("no_map", 1);
            call_out("regenerate", 480);
        } else {
            message_vision("��ѻ����˵�����ұ��������һ�ŵ�ͼ�ģ����Ǹղ������ˡ�\n", me);
        }
        return 1;
    }
    return 0;
}

int regenerate()
{
    set("no_map", 0);
    return 1;
}

