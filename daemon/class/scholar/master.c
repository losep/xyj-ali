// shiao.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "master scholar", "master" }) );

        set("gender", "����");
        set("age", 35);
        set("long",
		"��������춾����������������ң����ı������潨�ף�������Ϊ����ϲ��\n"
		"�Ĵ��ε������Ժš����ۡ����Ĵ���ɽ��ˮ���ύ�������ˡ�����ǰ�̳�\n"
		"�丸���׶���Ϊ�����ɵ��������ţ�����ϲ��Ʈ���ĸ�����Ȼ���ģ�����\n"
		"������ͷʹ���ѡ�\n" );

	set("attitude", "peaceful");
	create_family("������", 7, "������");

	set("str", 26);
	set("cor", 30);
	set("int", 28);
	set("cps", 30);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "move.hasten" :),
        }) );
	
	set_skill("dodge", 100);
	set_skill("force", 80);
	set_skill("instruments", 70);
	set_skill("literate", 150);
	set_skill("move", 100);
	set_skill("music", 100);
	set_skill("parry", 90);
	set_skill("perception", 80);
	set_skill("sword", 100);
	set_skill("unarmed", 60);
	set_skill("mysterrier",120);
	set_skill("mystforce", 100);
	set_skill("mystsword", 100);
	map_skill("move", "mysterrier");
	map_skill("dodge", "mysterrier");
	map_skill("force", "mystforce");
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");

	setup();
        carry_object(__DIR__"windspring")->wield();
        carry_object("/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query("marks/����"))  {
		 command("smile");
        	command("say �ܺã�" + RANK_D->query_respect(ob) +
"���Ŭ�������ձض��гɡ�\n");
        	command("recruit " + ob->query("id") );
		ob->set("marks/����", 0); 
		ob->set("marks/����", 0);	
		}
	    else {
		command ("say �㻹������һ�˶��ߵ����ְɡ�\n");
		ob->set("marks/����", 1);
		} 
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "scholar");
}

