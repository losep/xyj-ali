// hou.c

inherit NPC;

void random_move();

void create()
{
    set_name("����", ({ "hou zi","monkey","hou" }));
    set("race", "Ұ��");
    set("age", 8);
    set("long", "һֻ��Ƥ��С���ӡ�\n");

    set("str", 30);
    set("cor", 26);
    set("combat_exp", 50);

    set_skill("dodge", 20);
    set_skill("unarmed", 10);
    set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }));
    set("verbs", ({ "bite", "claw" }));
    setup();
}

void init()
{
    object king = query("king");
    
    set("chat_chance", 10);
    if (present("jing", environment()) || present("mowang", environment())) {
        set("chat_msg", ({
            (: random_move :),
            "\nС�����ŵõ������ܡ�\n",
            "\n�����Ǵ�е����������ˣ������ˣ������ְ�����\n",
            "\n������һ�ߴ��һ�鵽�����ܣ��������ˣ������ˣ��ǳ滢���������ˣ���ô�찡����\n",
            "\n�����Ǵ�е�����" + (objectp(king) ? "��������������������" : "�����ˣ������ˣ������ְ���") + "��\n"
        }));
    } else {
        set("chat_msg", ({
            (: random_move :),
            "С���Ӹ��˵�ֱ�����\n",
            "�����Ǵ�е�����Ҫ���������ﰲ�Ҿͺ��ˡ���\n",
            "�����ǽ�ͷ�Ӷ����������������ǳ滢���������ҡ���\n",
            "�������˷ܵĴ�е�����������������" + (objectp(king) ? king->name()+"�����ǵĴ���" : "˭�������ǵĴ�����") + "����\n"
        }));
    }
}

void random_move()
{
    object king = query("king");
    object another;
    
    if (objectp(king) && environment(king) == environment()) {
        if ((present("jing", environment()) && random(5) > 4)
        ||  present("mowang", environment())) {
            message_vision("\n�����Ǵ�е����������ˣ������ˣ������ְ�����\n", this_object());
            return;
        }
        another = new(__FILE__);
        another->set("king", king);
        another->move(environment(king));
        king->set_temp("people/" + king->add_temp("people_num", 1), another);
    }
    ::random_move();
}
