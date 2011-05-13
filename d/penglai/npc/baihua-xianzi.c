// cracked by vikee 2/09/2002   vikee@263.net

//baihua xianzi
inherit NPC;

void create()
{
    set_name("�ٻ�����", ({"baihua xianzi", "baihua", "xianzi"}));
    set("long", @LONG
һ�����ʸ߾����������˵�����Ů�ӡ�
����������ٻ���ɱ��Ȩ�İٻ����ӣ���˵�����ڵ�Ⱥ������������
���ĺ�����򽫱������ε�����������
������İٻ������������һ��Һ��
LONG);

    set("title", "Ⱥ��֮��");
    set("gender", "Ů��");
    set("age", 20);
    set("class", "xian");
    set("attitude", "friendly");
    set("rank_info/respect", "����");
    set("per", 30);
    set("int", 30);
    set("max_gin", 600);
    set("max_sen", 3000);
    set("max_kee", 3000);
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 100);
    set("max_mana", 2000);
    set("mana", 2000);
    set("mana_factor", 200);
    set("combat_exp", 800000);

    set("inquiry", ([
        "name" : "��������������Ⱥ��֮����ִ�ưٻ���ɱ��Ȩ��",
        "�϶�" : "������������������֡�",
        "�ٻ���" : "�����İٻ����������һ��Һ����ϧ���ﻨ��̫�٣������ھ��м���(add)�����ʻ������ܸ�����ζ��",
        "��ĵ��" : "�Ǹ����ˣ���Ȼ�������ĺ��������������������",
    ]));
    set("eff_dx", 200000);
    set("nkgain", 350);
    
    set_skill("literate", 100);
    set_skill("unarmed", 80);
    set_skill("dodge", 70);
    set_skill("force", 80);
    set_skill("parry", 80);
    set_skill("spells", 80);
    set_skill("moonshentong", 80);
    set_skill("flower-hand", 200);
    set_skill("moonforce", 80);
    set_skill("moondance", 70);
    set_skill("sword", 80);
    set_skill("snowsword", 80);
    map_skill("spells", "moonshentong");
    map_skill("unarmed", "flower-hand");
    map_skill("force", "moonforce");
    map_skill("dodge", "moondance");
    
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: cast_spell, "arrow" :),
            (: cast_spell, "mihun" :),
            (: cast_spell, "shiyue" :),
    }));
    create_family("�¹�", 2, "����");
    setup();

    carry_object("/d/moon/obj/luoyi")->wear();
    //carry_object("/d/obj/book/makeupbook");
    if (clonep()) carry_object("/d/obj/flower/rose")->wear();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("gender") != "Ů��") {
        command("sneer");
        command("say �Ҳ������ˣ�");
        command("say �������黹��ã��Ͻ����ɣ�\n");
        return;
    }
    
    if (ob->query("family/master_id") == "chang e") {
        command("sneer");
        command("say "+ RANK_D->query_respect(ob)
            + "��Ȼ���϶�ָ�㣬�ֺα������ң�\n");
        return;
    }

    command("pat "+ob->query("id"));
    command("say �ã�ϣ��" + RANK_D->query_respect(ob)
        + "���Ŭ��������������������ĳЩ��һ����ɫ������\n");
    command("recruit " + ob->query("id") );
    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "xian");
}
