//sgzl

inherit NPC;

void create()
{
    set_name("С����", ({"xiao jin yu", "xiao yu", "fish", "yu"}));
    set("long", "һ��С���㣬���ں����������ڵ����š�\n");

    set("title", "��·ʹ��");
    set("age", 2);
    set("race", "Ұ��");

    set_skill("dodge", 60);
    set("combat_exp", 10);
    set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }));
    set("verbs", ({ "bite" }));

    setup();
}

void init()
{
    object me = this_object();

    ::init();
    remove_call_out("yinlu");
    call_out("yinlu", 10);
}

void yinlu()
{
    command("west");
    call_out("yinlu1", 10);
}

void yinlu1()
{
    command("east");
    call_out("yinlu2", 10);
}

void yinlu2()
{
    command("north");
    call_out("yinlu3", 10);
}

void yinlu3()
{
    command("east");
    call_out("yinlu4", 10);
}

void yinlu4()
{
    command("south");
    call_out("yinlu5", 10);
}

void yinlu5()
{
    command("west");
    call_out("yinlu6", 10);
}

void yinlu6()
{
    command("south");
    message_vision("$Nһ��β�Ͳ�֪�ε�����ȥ�ˡ�\n", this_object());
    move(__DIR__"mazee");
}


