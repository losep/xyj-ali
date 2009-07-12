// azi.c ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("����", ({ "azi" }));
	set("nickname", "������Сʦ��");
	set("long", 
		"�����Ƕ�������Ӱ��ϡ�\n"
		"������������������������͸��һ��а����\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_kee", 300);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);

	set_skill("force", 40);
  	set_skill("huagong-dafa", 25);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
	set_skill("unarmed", 30);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
//	set_skill("tianshan-zhang", 80);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");

	create_family("������", 2, "����");

	setup();
	carry_object("/d/suburb/xkx/xingxiu/obj/xxqingxin-san");
	carry_object("/d/suburb/xkx/xingxiu/obj/xxqingxin-san");
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
