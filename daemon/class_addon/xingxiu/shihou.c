// shihou.c ʨ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("ʨ����", ({ "shihou zi", "shihou" }));
	set("nickname", "�����ɶ�ʦ��");
	set("long", 
		"�����Ƕ�����Ķ�����ʨ���ӡ�\n"
		"����ʮ���꣬ʨ�����ڣ�һ����֪����������ʿ��\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 30000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("unarmed", 70);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	create_family("������", 2, "����");

	setup();
  	//carry_object("/d/obj/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
