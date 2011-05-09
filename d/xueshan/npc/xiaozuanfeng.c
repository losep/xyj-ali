//xiaozuanfeng.c

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("С���", ({"xiao yao", "xiaoyao", "yao"}));
    set("gender", "����" );
    set("age", 16);
    set("long", "С���ԭ��ʨ��ɽ��ѲɽС����\n"
        "������ʨ��ħ����ѩɽ��ĵ���ʦ�ˡ�\n"
        "�������ø��Ժȣ��������ˮ¥̨�ȵ��£���Ҳ��ң��\n");
    set("class", "yaomo");
    set("combat_exp", 5000);
    set("attitude", "peaceful");
    set("title", "С��");
    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 10);

    set("per", 11);
    set("max_kee", 150);

    set("vendor_goods", ([
        "jiudou": "/d/xueshan/obj/jiudou",
        "peijian": "/d/obj/weapon/sword/peijian",
        "yinzhen": "/d/obj/weapon/throwing/yinzhen",
        "kongqueling": "/d/obj/weapon/throwing/kongque-ling",
    ]));

    setup();
    carry_object("/d/obj/armor/shoupi")->wear();
}

void init()
{
    object ob=this_player();
    object me=this_object();

    ::init();
    add_action("do_vendor_list", "list");
}

