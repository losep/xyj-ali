// tianlang.c ������

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "tianlang zi", "tianlang" }));
	set("nickname", "��������ʦ��");
	set("long", 
		"�����Ƕ�����������������ӡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_kee", 400);
	set("max_gin", 400);
	set("force", 1000);
	set("max_force", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("unarmed", 50);
	set_skill("xingxiu-duzhang", 30);
	set_skill("parry", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	create_family("������", 2, "����");

	setup();
  	carry_object("/d/obj/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
