// ning.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "ning zhongze", "ning", "zhongze", "shiniang" }));
	set("long", 
"������Ůʿ������������Ⱥ��ʦ�ü����ӣ���Ȼ�Ѳ���\n"
"���꣬���������ɡ����书ֻ������Ⱥ��ѷ���ѡ�\n");

	set("gender", "Ů��");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 35);
	set("con", 30);
	set("per", 30);
	
	set("kee", 2200);
	set("max_kee", 2200);
	set("gin", 1600);
	set("max_gin", 1600);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 30);

	set("combat_exp", 1000000);
	set("score", 150000);

	set_skill("force", 180);
	set_skill("dodge", 150);
	set_skill("parry", 120);
	set_skill("sword", 200);
	set_skill("cuff", 100);
	set_skill("blade", 180);
	set_skill("zixia-shengong", 180);
	set_skill("huashan-jianfa", 150);
	set_skill("huashan-shenfa", 140);
	set_skill("hunyuan-zhang", 150);
	set_skill("poyu-quan", 80);
	set_skill("fanliangyi-dao", 150);
	set_skill("literate", 90);
	set_skill("strike", 160);

	map_skill("dodge", "huashan-shenfa");
	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "poyu-quan");
	map_skill("blade", "fanliangyi-dao");

//	prepare_skill("strike", "hunyuan-zhang");
//	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 13, "����");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.wushuang" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"����" : "���̾����¶�����������Ǹ���̫̫����Ư����˵��\n",
		"ľ��" : "��˵����Wooder�ɣ����Ѿ������ˣ�û�¿������������ơ�\n",
	]));

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "Ů��") {
		command("say ���¿�ʲô��Ц������ô�ܹ�������Ϊͽ�أ����������વġ�");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_dex() < 20) {
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�һ�ɽ���书��");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");
