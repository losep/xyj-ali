
inherit NPC;

void create()
{
    set_name("��ï��", ({"xu maogong", "xu", "xumaogong", "master"}));
    set("long", @LONG

��ï������������֣���һ���ֵ���Ψһ���Ĺ١����ֵܽ��ƺ�
��ï�������ֵܵĹ�ϵ��һ����Զ����ʱ���˶Դ�����΢�ԡ�����
�������֮����ï��ȴ��Ȼ�ǹٲ�����������һͬ��������һ��
�ֵܴ�����������
LONG);

    set("title", "�����ʦ");
    set("gender", "����");
    set("rank_info/self", "ƶ��");
    set("age", 55);
    set("str", 15);
    set("per", 25);
    set("int", 40);
    set("combat_exp", 40000);
    set_skill("literate", 200);
    set_skill("spells", 150);
    set_skill("baguazhou", 100);
    set_skill("force", 30);
    set_skill("lengquan-force", 30);
    set_skill("dodge", 30);
    set_skill("yanxing-steps", 30);
    set_skill("parry", 30);
    set_skill("unarmed", 30);
    set_skill("changquan", 30);
    set_skill("sword", 40);
    map_skill("spells", "baguazhou");
    map_skill("force", "lengquan-force");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "yanxing-steps");
    set("max_sen", 1000);
    set("max_kee", 300);
    set("force", 200);
    set("max_force", 200);
    set("force_factor", 10);
    set("mana", 700);
    set("max_mana", 700);
    set("mana_factor", 70);

    create_family("������", 2, "��ʦ");
    setup();

    carry_object("/d/obj/cloth/daopao")->wear();
}

int accept_fight(object me)
{
    command("say �Ϸ����أ��������˷��������ˡ�\n");
    return 0;
}

void attempt_apprentice(object me)
{
    command("hehe");
    command("say ƶ�����߲��ܣ�����ѧ��ѧ�óɣ���������컯�ˡ�");
    command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "fighter");
}