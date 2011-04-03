// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// bear-monster.c ���ܹ�
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("���ܹ�", ({ "bear monster", "bear", "monster" }));
    set("title", "��ɽ����");   
    set("long", @LONG

���ֱܹ���ɽҰ���һλ��������Ϊ��������Գ��ղ�㱻������
�Һã����������ȱ�Ϊ������������
���м���������֮������������ɽ����ɽ����
LONG);
    set("gender", "����");
    set("age", 30);
    set("attitude", "heroism");
    set("per", 9);
    set("rank_info/self", "����");
    set("rank_info/rude", "�ܹ�");
    set("max_kee", 1000);
    set("max_gin", 600);
    set("max_sen", 1000);
    set("force", 2000);
    set("max_force", 1000);
    set("force_factor", 75);
    set("max_mana", 1000);
    set("mana", 2000);
    set("mana_factor", 55);
    set("combat_exp", 750000);
    set_skill("literate", 50);
    set_skill("spells", 120);
    set_skill("buddhism", 100);
    set_skill("unarmed", 120);
    set_skill("jienan-zhi", 125);
    set_skill("dodge", 120);
    set_skill("lotusstep", 100);
    set_skill("parry", 125);
    set_skill("force", 105);
    set_skill("lotusforce", 105);
    set_skill("staff", 120);
    set_skill("lunhui-zhang", 130);

    map_skill("spells", "buddhism");
    map_skill("unarmed", "jienan-zhi");
    map_skill("dodge", "lotusstep");
    map_skill("force", "lotusforce");
    map_skill("parry", "lunhui-zhang");
    map_skill("staff", "lunhui-zhang");

    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "bighammer" :),
        (: cast_spell, "jingang" :),
    }) );
    create_family("�Ϻ�����ɽ", 2, "����");

    setup();
    carry_object("/obj/cloth")->wear();
    carry_object("/d/nanhai/obj/jingu3");
//   carry_object("/d/nanhai/obj/jingu3");
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name")=="�Ϻ�����ɽ") {
        command("smile");
        command("say �ܺã��Ҿ������㣬ϣ������Ŭ�������������\n");
        command("recruit " + ob->query("id") );
        return;
    }

    command("shake");
    command("say " + "�������������������Ϊͽ��\n");
    return;
}

