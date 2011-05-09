// snowcat 12 14 1997

inherit NPC;

int do_tell ();

void create()
{
    set_name("��Ҷ����", ({ "jiaye zunzhe", "jiaye", "zunzhe" }));
    set("title", "��ɽ");
    set("gender", "����");
    set("age", 1000);
    set("attitude", "peaceful");
    set("str",40);
    set("per",40);
    set("max_kee", 2000);
    set("max_gin", 2000);
    set("max_sen", 2000);
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 80);
    set("max_mana", 2000);
    set("mana", 2000);
    set("mana_factor", 80);
    set("combat_exp", 1200000);
    set_skill("literate", 90);
    set_skill("spells", 90);
    set_skill("buddhism", 90);
    set_skill("unarmed", 90);
    set_skill("jienan-zhi", 90);
    set_skill("dodge", 90);
    set_skill("lotusstep", 90);
    set_skill("parry", 90);
    set_skill("force", 90);
    set_skill("lotusforce", 90);
    set_skill("staff", 90);
    set_skill("lunhui-zhang", 90);
    map_skill("spells", "buddhism");
    map_skill("unarmed", "jienan-zhi");
    map_skill("dodge", "lotusstep");
    map_skill("force", "lotusforce");
    map_skill("parry", "lunhui-zhang");
    map_skill("staff", "lunhui-zhang");
    set("inquiry", ([
        "name" : "��ҶҲ��",
        "here" : "��ɽҲ��",
        "��ɽ" : "�ҷ�����֮��ɽҲ��",
        "������" : "�ҷ�����֮������Ҳ��",
        "����" : (: do_tell :),
        "����" : (: do_tell :),
        "��ȡ�澭" : (: do_tell :),
        "ȡ��" : (: do_tell :),
        "�澭" : (: do_tell :),
        "��" : (: do_tell :),
    ]));
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "bighammer" :),
    }) );

    setup();
    carry_object("/d/obj/cloth/jia_sha")->wear();
}

void init()
{
    call_out("telling", 10, this_player());
}

int do_tell()
{
    call_out("telling", 1, this_player());
    return 1;
}

int telling(object who)
{
    object me = this_object();

    tell_object(who, me->query("name")+"�����㣺"
        + OBSTACLES_D->check_obstacles_long(who, 2)
        + "\n");
    if (OBSTACLES_D->check_obstacles(who)) {
        who->set_temp("obstacle/lingshan_enter", 1);
        if (environment(me)==environment(who)
        &&  who->query("obstacle/reward") == 0)
            message_vision("$N��$nһ�Ϲ����ҷ����룡\n",me,who);
    }

    return 1;
}
