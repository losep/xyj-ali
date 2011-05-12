inherit NPC;

void create()
{
    set_name("������ͷ", ({"jinjun jiaotou", "jiaotou"}));
    set("title", "������");
    set("gender", "����");
    set("age", 45);

    set("max_gin", 500);
    set("eff_gin", 500);
    set("gin", 500);
    set("max_kee", 500);
    set("eff_kee", 500);
    set("kee", 500);
    set("max_sen", 500);
    set("eff_sen", 500);
    set("sen", 500);

    set("combat_exp", 35000);

    set_skill("unarmed", 70);
    set_skill("spear", 70);
    set("force", 500);
    set("force_factor", 40);
    set_skill("dodge", 70);
    set_skill("parry", 70);
    setup();

    carry_object("/d/obj/cloth/bingfu")->wear();
    carry_object("/d/obj/weapon/spear/tieqiang")->wield();

}
void init()
{
    add_action("do_answer", "answer");
    add_action("guard_dir", ({ "go", "south" }));
}

int guard_dir(string dir)
{
    object who = this_player();
    string verb = query_verb();
    object helper = query("helper");

    if (verb != "go") dir = verb;
    if (!helper) return 0;
    if (!living(this_object())) return 0;
    if (environment() != helper->get_drillent_room()) return 0;
    if (dir != "south") return 0;
    if (who->query("aolai_drill_allow")) return 0;

    tell_object(who, "������ͷ�ȵ����ҹ�������������ѵ�����������ʲô(answer)��\n"
                    + "(�������䡡���������֡��������ҡ������Ӿ�)\n");
    who->set_temp("aolai_drill_wait_answer", 1);
    return 1;
}

int do_answer(string arg)
{
    string *ans = ({"����","������","����","�Ӿ�"});
    object who = this_player();

    if (!who->query_temp("aolai_drill_wait_answer")) return 0;
    if (!arg) return notify_fail("��˵ʲô��\n");
    if (arg == "0" || arg == "1" || arg == "2" || arg == "3")
        arg = ans[atoi(arg)];
    message_vision("$N�����" + arg + "��\n", who);
    if (arg == "������") {
        command("consider");
        command("say �����ֿ��ԣ�����׼��������������ѵ����\n");
        who->set_temp("aolai_drill_allow", 1);
    }
    else
        command("say ���˵ʲô���������ң�\n");
    return 1;
}

void unconcious()
{
    object ob;
    object me = this_object();
    object where = environment (me);

    message_vision("\n$N���������ð�����ҵ������ף���������ô��ʰ�㣡��˵�յ���ײײ��ǿ�������䳡��\n",me);
    message_vision("\n��һ��$N���˹�����\n",me);
    ob = new(__FILE__);
    ob->move(where);
    destruct(me);
}

void die()
{
    unconcious();
}

