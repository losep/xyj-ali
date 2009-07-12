// zhaixing.c ժ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", 
		"�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
		"����ʮ���꣬�����������۹���͸��һ˿����֮����\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_kee", 700);
	set("max_gin", 700);
	set("force", 1500);
	set("max_force", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("unarmed", 80);
	set_skill("xingxiu-duzhang", 80);
	set_skill("parry", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");

	create_family("������", 2, "����");

	setup();
//	carry_object("/d/obj/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
