// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// honghaier.c �캢��
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
    set_name("�캢��", ({ "honghaier", "hong" }));
    set("title", "ʥӤ����");
    set("long", @LONG
������ţħ��֮�ӣ����Ժö������Ϻ������ܵ�������ɽ�����˸�
�Ʋ�ͯ�ӡ�������Ȼ����ѱ��ʱ�����ŷ�ҧһ�ڣ��Һù���������
���˽��䣬��������������ࡣ
LONG);
    set("gender", "����");
    set("age", 15);
    set("attitude", "heroism");
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
    set_skill("literate", 80);
    set_skill("spells", 100);
    set_skill("taiyi", 100);
    set_skill("unarmed", 100);
    set_skill("moyun-shou", 100);
    set_skill("dodge", 100);
    set_skill("moshenbu", 100);
    set_skill("parry", 100);
    set_skill("force", 100);
    set_skill("lengquan-force", 100);
    set_skill("spear", 120);
    set_skill("huoyun-qiang", 150);
    map_skill("spells", "taiyi");
    map_skill("unarmed", "moyun-shou");
    map_skill("dodge", "moshenbu");
    map_skill("force", "lengquan-force");
    map_skill("parry", "huoyun-qiang");
    map_skill("spear", "huoyun-qiang");
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: cast_spell, "qiankun" :),
        (: cast_spell, "zhenhuo" :),
    }) );

    create_family("����ɽ", 2, "����");

    setup();
    carry_object("/obj/money/gold");
    carry_object("/obj/money/gold");
    carry_object("/obj/cloth")->wear();
    carry_object("/d/nanhai/obj/jingu2");
    carry_object("/d/nanhai/obj/huojianqiang")->wield();
}

void attempt_apprentice(object ob)
{
    command("smile");
    command("say �ܺã��������������㣬ϣ������Ŭ�����ܸ����������ǡ�\n");
    command("recruit " + ob->query("id") );
    return;
}

