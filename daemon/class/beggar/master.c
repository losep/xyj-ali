// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("½�ò�", ({ "beggarhead", "beggar" }) );

	set("nickname", "��ˮ����");
	set("gender", "����");
	set("age", 52);
	set("long",
		"½�ò���һ���������������ؤ��һ���޾����Ҫ����������ӣ�����\n"
		"���������˶�ʶ�������ϴ�����ʮ�������Ƥ���ң��ⲻ���ǡ����ϻ�\n"
		"����ͷ�������������Į�ϵġ���ˮ���ԡ����ű�����ֻ����½�ò�\n"
		"���ٹ��ܣ���˵������ʱ�����ߡ��˵������������Ĵ����������Ҳ\n"
		"����ȷ����ǰ���½�òƵ����ǲ�����ġ�\n" );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);

	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);
	set("env/wimpy", 50);
	
	set("chat_chance", 30);
	set("chat_msg", ({
		(: random_move :)
	}) );
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 80);
	set_skill("staff", 90);
	set_skill("blade", 70);
	set_skill("throwing", 60);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 100);
	set_skill("perception", 80);
	set_skill("stealing", 40);

	set_skill("spicyclaw", 100);
	set_skill("serpentforce", 100);

	map_skill("unarmed", "spicyclaw");
	map_skill("force", "serpentforce");

	create_family("���ϻ�", 4, "��ͷ");

	setup();
}


void attempt_apprentice(object me)
{
	command("look " + me->query("id"));
	if( me->can_afford(100) ) {
		command("say ���ǻ��ϻ�ֻ�ջ��ӣ�" + RANK_D->query_respect(me)
			+ "�����ǻ�ȥ���ɡ�\n");
		return;
	} else {
		command("nod");
		command("recruit " + me->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "beggar");
}


