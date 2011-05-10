inherit NPC;

void create()
{
    set_name("������", ({"beng jiangjun","beng","monkey"}));
    set("title","����ɽ��");
    set("gender", "����" );
    set("age", 35);
    set("class", "monkey");
    set("long", "һֻ���˾���ͨ��Գ��\n");
    set("combat_exp", 60000);

    set("attitude", "peaceful");
    set("str",40);
    set_skill("unarmed", 80);
    set_skill("dodge", 110);
    set_skill("parry", 80);
    set_skill("force", 50);
    set("per", 10);
    set("max_kee", 600);
    set("max_gin", 100);
    set("max_sen", 300);
    set("max_force", 400);
    set("force",400);
    set("max_mana",200);
    set("mana",200);
    set("force_factor", 20);

    set("chat_chance", 3);
    set("chat_msg", ({
        "����������һ�ڣ�Ⱥ���ʱ������������\n",
        "������˵���������ǣ��Ȱ�ս������ã��������´�ﲻҪ���ģ����д��������\n",
        "���������������˵���ţ���ս�����ã��ȵ�����Ū���˱������һ���ɽ����ͭǽ�����ˡ�\n",
    }));

    set("inquiry", ([
        "name" : "�Ҿ��ǻ���ɽˮ�����󽫱�������\n",
        "here" : "����ǻ���ɽ��\n",
        "����" : "�٣��ҼҴ������ǻ���ɽˮ����������\n",
        "weapon" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n",
        "bingqi" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n",
        "����" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n",
    ]));

    setup();
}

int accept_object(object who, object ob)
{
    object me = this_object();

    if ((string)ob->query("id") != "bing qi") {
        command("say ��������ʲô�ã�");
        command("shake");
        return 0;
    } else if (who->query("dntg/donghai") == "begin"
            ||  who->query("dntg/donghai") == "allow"
            ||  who->query("dntg/donghai") == "done") {
        command("say �����Ѿ������ˣ����ʹ��������ˡ�\n");
        return 0;
    } else if (random(10) != 1) {
        message_vision("\n$N�˷ܵĽе���̫���ˣ�Ҫ���ٶ�һ����͸����ˡ�\n",me);
        call_out("destruct_ob", 1, ob);
        return 1;
    } else {
        command("jump");
        command("say ���������ǵı����ǹ����ˣ����Լ�Ҳ��һ�����ֵļһ�ɣ�\n");
        who->set("dntg/donghai", "begin");
        call_out("destruct_ob", 1, ob);
        return 1;
    }
}

void destruct_ob(object ob)
{
    if (ob) destruct(ob);
}
