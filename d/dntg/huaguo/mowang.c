inherit NPC;

void create()
{
    set_name("����ħ��", ({ "hunshi mowang", "mowang"}));
    set("gender", "����");
    set("long", @LONG
ֻ����ħ����
����ͷ���ڽ����ӳ�չ�������������ۣ�ӭ��Ʈ����
�����´��ź����ף�����Ƥ������̤�Ż���ѥ�������Ͻ���
��������ʮΧ��������ɣ���ִһ�ڵ������ж�������
������Ϊ����ħ��������ģ����
LONG );
    set("age", 30);
    set("str", 30);
    set("per", 30);
    set("int", 30);
    set("attitude", "killer");
    set("combat_exp", 150000);
    set_skill("force",  150); 
    set_skill("spells", 150); 
    set_skill("unarmed",150);
    set_skill("blade",  150);
    set_skill("dodge",  150);
    set_skill("parry",  150);
    set_skill("yaofa", random(50)+150);
    set_skill("iceblood-force", 150);
    set_skill("kugu-blade",  random(50)+50);
    map_skill("force", "iceblood-force");
    map_skill("spells", "yaofa");
    map_skill("blade", "kugu-blade");
    set("max_gin", 1000);
    set("eff_gin", 1000);
    set("gin", 1000);
    set("max_kee", 1000);
    set("eff_kee", 1000);
    set("kee", 1000);
    set("max_sen", 1000);
    set("eff_sen", 1000);
    set("sen", 1000);
    set("force", 1300);
    set("max_force", 1300);
    set("mana", 1400);
    set("max_mana", random(800)+1400);
    set("force_factor", 50);

    setup();

    carry_object("/d/obj/armor/tongjia.c")->wear();
    carry_object("/d/obj/cloth/shoupiqun")->wear();
    carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
    add_action("override_move", ({ "go", "west", "east", "south", "north" }));
}

void kill_ob(object ob)
{
    object me = this_object();
    set_temp("my_killer", ob);
    message_vision("$N�ȵ������������ռ�ˣ��������\n", me);
    ::kill_ob(ob);
}

void die()
{
    object ob = query_temp("my_killer");
    object me = this_object();

    if (ob) {
        message_vision("\n$N�ҽ�һ��������Ϊ���Ρ�\n",me);
        call_out("announcer_appearing", 1, ob);
        load_object("/obj/empty");
        move("/obj/empty");
        return;
    }
    destruct(me);
}

void announcer_appearing(object me)
{
    object announcer;
    object panzi;
    int i = 0;
    
    message_vision("\n�ں��ӿ�������$n��ն�����˵�����������\n", me, this_object());
    announcer = new(__DIR__"announcer");
    message_vision("\n����ͷ��"+ announcer->name() +"�Ӻ���Ⱥ�����˳�����\n", me);
    if (me->query("dntg/huaguo") != "done" && userp(me)) {
        announcer->announce_success(me);
    }
    message_vision("\n"+ announcer->name() +"�����ں������ְ˽ŵİ�ħ���������ǵ�ʬ�����˳�ȥ��\n", me);
    foreach (object ob in all_inventory(environment(me)))
        if (ob->is_corpse()) destruct(ob);
    destruct(announcer);
    for (i = 1; i <= me->query_temp("people_num"); i++) {
        object hou = me->query_temp("people/" + i);
        if (objectp(hou)) destruct(hou);
    }
    me->delete_temp("people");
    me->delete_temp("people_num");
    destruct(this_object());
}

int override_move(string dir)
{
    string verb = query_verb();
    object killer = query_temp("my_killer");
    
    if (verb != "go") dir = verb;
    if (killer != this_player()) return 0;
    if (!environment()->query("exits/" + dir)) return 0;

    tell_object(killer, name() + "��������Ц���������ߣ�û��ô���װɣ���\n");
    return 1;
}
