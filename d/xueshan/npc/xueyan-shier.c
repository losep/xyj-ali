//xueyan-shier.c
//hehe, this npc is interesting:D...weiqi, 97.09.15

inherit NPC;
void create()
{
    set_name("ѩ���̶�", ({"xueyan shier", "shier", "xueyan"}));
    set("gender", "Ů��");
    set("title", "Ѿ��");
    set("age", 16);
    set("long", "��ȸ����������Ѿ�ߣ����ȸ������ϵ���ܣ�ѩɽ���¶�Ҫ�������֡�\n");
    set("class", "avian");
    set("combat_exp", 25000);
    set("attitude", "peaceful");
    create_family("��ѩɽ", 4, "����");
    set_skill("unarmed", 30);
    set_skill("dodge", 30);
    set_skill("parry", 30);
    set_skill("blade", 30);
    set_skill("ice-blade", 30);
    set_skill("peripateticism", 30);
    set_skill("force", 30);   
    set_skill("iceblood-force", 30);
    map_skill("force", "iceblood-force");
    map_skill("blade", "ice-blade");
    map_skill("dodge", "peripateticism");

    set("per", 21);
    set("max_kee", 300);
    set("max_sen", 300);
    set("force", 300);
    set("max_force", 250);
    set("force_factor", 5);
    setup();

    set("eff_dx", -8000);
    set("nkgain", 60);

    carry_object("/d/obj/cloth/skirt")->wear();
    carry_object("/d/obj/cloth/shoes")->wear();
    carry_object("/d/obj/weapon/blade/iceblade")->wield();
}
void init()
{
    object ob=this_player();
    object me=this_object();

    ::init();

    if ((string)ob->query("gender")=="����"
    &&  (int)me->visible(ob)
    &&  (string)environment(me)->query("short")=="Ů�����Է�") {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    switch (random(1)) {
        case 0:
            command("chat* ֻ��ѩ������е���" + ob->query("name") + "�����������å����Ȼ����Ů�����Է����ˣ�\n");
            command("kick " + ob->query("id"));
            break;
    }
}
