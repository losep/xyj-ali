// patrol.c

inherit NPC;

mixed ask_for_weapon();
int patrol_move();

void create()
{
    set_name("Ѳ��ҹ��", ({"ye cha","yecha"}));
    set("gender", "����");
    set("age", 30);
    set("long", "һ��Ѳ����ҹ�棬�������������\n");

    set("attitude", "peaceful");
    set("class", "dragon");
    set("combat_exp", 30000);
    set("kee", 500);
    set("max_kee", 500);
    set("sen", 600);
    set("max_sen", 600);
    set("force", 700);
    set("max_force", 700);
    set("mana", 800);
    set("max_mana", 800);
    set("force_factor", 20);
    set("mana_factor", 20);
    set("str", 30);

    set_skill("spells", 60);
    set_skill("seashentong", 40);
    set_skill("force", 60);
    set_skill("dragonforce", 60);
    set_skill("fork", 60);
    set_skill("fengbo-cha", 60);
    set_skill("dodge", 100);

    map_skill("spells", "seashentong");
    map_skill("force", "dragonforce");
    map_skill("fork", "fengbo-cha");
    map_skill("parry", "fengbo-cha");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: patrol_move :),
    }));

    set("combat_chat_chance", 3);
    set("combat_chat_msg", ({
        (: perform_action, "fork", "fengbo" :),
    }));

    set("inquiry", ([
        "����": (: ask_for_weapon :),
        "weapon": (: ask_for_weapon :),
        "bingqi": (: ask_for_weapon :),
    ]));

    setup();

    carry_object("/d/obj/armor/tenjia")->wear();
    carry_object("/d/obj/armor/niupi")->wear();
    carry_object("/d/obj/weapon/fork/fork")->wield();
}

void init()
{
    object who = this_player();

    if (who == query("target") && !query("lost")) {
        remove_call_out("greeting");
        call_out("greeting", 1, who);
    }
}

void greeting(object who)
{
    object me = this_object();

    if (who && environment(who) == environment()) {
        message_vision("$N��$n���һ����߾�����ߺ��ˣ�������������Ҵ���\n", me, who);
        me->kill_ob(who);
    }
}

int accept_fight(object ob)
{
    if (ob != query("target")) {
        command("say ȥȥȥ��һ��ȥ��������Ѳ���أ���ʲô�ң�");
        return 0;
    }
    
    command("say ѽ�����翴���μ����ɣ���Ȼ���Լ��������ˡ�");
    this_object()->kill_ob(ob);
    return 1;
}

void unconcious()
{
    object me = this_object();
    object ob = query("target");
    object killer = query_temp("last_damage_from");
    object pai;
    
    if (killer != ob) {
        message_vision("$N�����˿������ˣ����߻�����һ�仰�����󵨿�ͽ����Ȼ��������������Ұ����\n", me);
        destruct(me);
        tell_object(killer, "\n���ˣ����Ȼ��ʶ�������ܻ���ʲô�˵ĺ��£�\n");
    }
    
    set("lost", 1);
    command("say " + RANK_D->query_respect(ob) + "������" + RANK_D->query_respect(ob) + "������");
    message_vision("$N��æ�ݵ��ڵأ���ͷ���ѡ�\n", me);
    command("say ҹ�����۲�ʶ̩ɽ���������");
    if (!query("asked")) {
        command("say ��֪" + RANK_D->query_respect(ob) + "����������Ϊ���£�");
        command("say ҹ��ԸΪ��Ч�͡�");
    } else {
        command("say ҹ��ԸΪ" + RANK_D->query_respect(ob) + "��Ч�ͣ�������������Ϊ������������");
        command("say �������������ƣ����úá�");
        pai = new("/d/sea/obj/pai");
        pai->move(ob);
        message_vision("$N����һ��ˮ�����ơ�\n", me);
        pai = new("/d/sea/obj/pai");
        pai->move(me);
        set("chat_msg", 0);
        call_out("lead_the_way", 5, 0);
    }
    
    set("gin", 1);
    set("kee", 1);
    set("sen", 1);
    set("eff_gin", 1);
    set("eff_kee", 1);
    set("eff_sen", 1);
    remove_all_enemy();
}

void die()
{
    unconcious();
}

mixed ask_for_weapon()
{
    object me = this_object();
    object ob = this_player();
    object pai;
    
    if (ob != query("target")) return "�ҵı�����������ʲô��ϵ��";

    set("asked", 1);
    if (!query("lost")) return "�������ã��ҽ�������㳢�������еı�����";
    else {
        command("say ԭ��" + RANK_D->query_respect(ob) + "����������Ϊ��Ѱһ����������");
        command("say ������������Ϊ������������");
        command("say �������������ƣ����úá�");
        pai = new("/d/sea/obj/pai");
        pai->move(ob);
        message_vision("$N����һ��ˮ�����ơ�\n", me);
        pai = new("/d/sea/obj/pai");
        pai->move(me);
        set("chat_msg", 0);
        call_out("lead_the_way", 5, 0);
        return 1;
    }
}

int patrol_move()
{
    object env = environment();
    string *dirs = ({ "east", "west", "south", "north", "southeast", "northeast", "southwest", "northwest" });
    string dir = dirs[random(sizeof(dirs))];

    if (env->query("exits/" + dir)) { command("go " + dir); return 1; }
    return 0;
}

void navigator_move()
{
    object env = environment();

    if (env->query("exits/east")) { command("go east"); return; }
    if (env->query("exits/eastup")) { command("go eastup"); return; }
    if (env->query("exits/northeast")) { command("go northeast"); return; }
    if (env->query("exits/southeast")) { command("go southeast"); return; }
    message_vision("$Nԭ��ת�˼���Ȧ��ȴû���ط�����������·�ˡ�\n", this_object());
}

void start_testing(object ob)
{
    object puller;

    puller = new(__DIR__"wire-puller");
    puller->set("owner", ob);
    ob->move(environment());
    ob->start_testing();

    message_vision("$N�������¡�\n", this_object());
    destruct(this_object());
}

void lead_the_way(int step)
{
    object me = this_object();
    object ob = query("target");
    object helper = ob->query_temp("dntg_helper");
    object ao;
    
    if (!ob || environment(ob) != environment()) {
        destruct(this_object());
        return;
    }
    
    if (!helper) {
        message_vision("$N��Ȼ����һ�Σ���ʧ�ˡ�\n", me);
        destruct(me);
        return;
    }
    
    remove_call_out("lead_the_way");
    
    navigator_move();
    if (ao = present("ao guang", environment())) {
        command("say ���������������");
        message_vision("$N��$n�Ķ���˵��Щʲô��\n", me, ao);
        message_vision("$N�������¡�\n", me);
        start_testing(ob);
        return;
    }
    if (step > 20) {
        message_vision("$N��$n�߹հ˹գ�ʼ�ղ����ط�����Ȼ��ʶ���Լ�����ˣ�ˡ�\n", ob, me);
        message_vision("$N�ȵ���߾�����������ҿ�������ˣ"+ RANK_D->query_rude_self(ob) +"�ɡ�\n", ob, me);
        message_vision("$N���Լ���С������ʶ�ƣ��ŵ�������ɫ����Ҳ����ˣ�����ˡ�\n", me);
        command("say " +RANK_D->query_respect(ob)+ "Ϣŭ��ҹ����Ҳ����ˣ�����ˡ�");
        call_out("goto_aoguang", 2, ob);
        return;
    }

    call_out("lead_the_way", 2, step + 1);
}

void goto_aoguang(object ob)
{
    object me = this_object();
    object helper = ob->query_temp("dntg_helper");

    if (!ob || environment(ob) != environment() || !helper) {
        destruct(me);
        return;
    }
    
    tell_object(ob, "����ǰһ�Σ�������һ������֮�С�\n");
    ob->move(helper->get_palace_room());
    tell_room(environment(me), "��Χ��ˮ��һ��Ť����" + ob->name() + "��" + name() + "�����ˡ�\n");
    me->move(helper->get_palace_room());
    tell_room(environment(me), "��Χ��ˮ��һ��Ť����" + name() + "����" + ob->name() + "���������\n", ({ ob, me }));
    start_testing(ob);
}
