// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xingzhe.c �η�����
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("�η�����", ({ "xingzhe" }));
    set("gender", "����");
    set("age", 40);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("max_kee", 350);
    set("max_gin", 300);
    set("max_sen", 350);
    set("force", 300);
    set("max_force", 300);
    set("force_factor", 20);
    set("max_mana", 250);
    set("mana", 250);
    set("mana_factor", 10);
    set("combat_exp", 100000);

    set("eff_dx", 40000);
    set("nkgain", 250);

    set_skill("literate", 50);
    set_skill("spells", 50);
    set_skill("buddhism", 40);
    set_skill("unarmed", 60);
    set_skill("jienan-zhi", 50);
    set_skill("dodge", 40);
    set_skill("lotusstep", 40);
    set_skill("parry", 60);
    set_skill("force", 50);
    set_skill("lotusforce", 50);
    set_skill("staff", 60);
    set_skill("lunhui-zhang", 50);
    map_skill("spells", "buddhism");
    map_skill("unarmed", "jienan-zhi");
    map_skill("dodge", "lotusstep");
    map_skill("force", "lotusforce");
    map_skill("parry", "lunhui-zhang");
    map_skill("staff", "lunhui-zhang");
//   set("chat_chance_combat", 80);
//   set("chat_msg_combat", ({
//     (: cast_spell, "thunder" :),
//   }) );

    create_family("�Ϻ�����ɽ", 3, "����");

    setup();
    carry_object("/obj/money/gold");
    carry_object("/d/nanhai/obj/sengpao")->wear();
    carry_object("/d/nanhai/obj/tiezhang")->wield();
}

void attempt_apprentice(object ob)
{
    command("smile");
    command("say �ܺã�ƶɮ�������㣬ϣ������Ŭ�������������\n");

    command("recruit " + ob->query("id") );
    return;
}

