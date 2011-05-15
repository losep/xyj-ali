
#include <ansi.h>
#include <combat.h>

inherit NPC;

void set_skills(object);
void endfight();
void reward(object, object, object, int);
void transform();

void create()
{
    set_name("����", ({"yu tu", "tu", "rabbit", "jade rabbit"}));
    set("title", "�¹�");
    set("long", "һֻ���ÿɰ���С���ã����۾��������죬��ֻ���䳤������\n");
    set("gender", "Ů��");
    set("age", 10);
    set("class", "xian");
    set("rank/respect", "����");
    set("per", 999);
    set("str", 30+random(10));
    set("cor", 40);
    set("cps", 30);
    set("int", 20);
    set("max_sen", 1000);
    set("sen", 1000);
    set("max_kee", 2000);
    set("kee", 2000);
    set("max_mana", 500);

    set("combat_exp", 300);
    set_skill("unarmed", 10);
    set_skill("flower-hand", 10);
    map_skill("unarmed", "flower-hand");
    set_skill("dodge", 20);

    create_family("�¹�", 2, "����");
    setup();
    set("renxing", 0);

    carry_object("/d/moon/obj/luoyi");
    carry_object("/d/moon/obj/daoyaochu")->wield();
    set("chat_msg", ({
            (: random_move :),
            (: transform :),
    }));
    set("chat_chance", 3);
    set("chat_chance_combat", 4);
    set("chat_msg_combat", ({
            (CYN "����Խ��Խ���ˣ����������������棬���棡�ٴ��ٴ򣡡�\n" NOR),
            (: endfight :),
    }));
}

void transform()
{
    object me = this_object();
    object luoyi = present("luoyi", me);
    if (query("renxing")) {
        message_vision(MAG "$N����һ�Σ��Գ���ԭ�ͣ�ԭ����һ�����ÿɰ���С���á�\n" NOR, me);
        set("long", "һֻ���ÿɰ���С���ã����۾��������죬��ֻ���䳤������\n");
        set("limbs", ({
                "ͷ��", "����", "�ؿ�", "����", "β��", "����",
                "��צ", "��צ", "����", "С��", "ǰ��", "����",
                "ǰצ", "��צ" }));
        set("age", 10);
        set("rank/respect", "����");
        setup();
        set("renxing", 0);
        if (luoyi) luoyi->unequip();
    } else {
        message_vision(MAG "$N����һ�Σ����������Σ������һ��ͤͤ��������Ů��\n" NOR, me);
        set("long",
"��ԭ��ֻ���϶�ĳ��������϶���ڵ��ϵ���ҩ�������Ρ���\n"
"����ҩ֮�±���ĸ��ȥ��ҩ���ö���֮����ͨҩ����\n");
        delete("limbs");
        set("age", 16);
        set("rank/respect", "����");
        setup();
        set("renxing", 1);
        if (luoyi) luoyi->wear();
    }
}

void attempt_apprentice(object ob)
{
    command("shake");
    command("say ���գ����գ���ͽ�����棡\n");
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "xian");
}

void welcome(object ob)
{
    command("xixi " + ob->query("id"));
    message_vision(CYN "$N�����Դ�˵��������˭�����������¹�����\n" NOR, this_object());
    tell_object(ob, GRN "����Իش�(answer): 1.�� 2.��ʦ 3.������\n" NOR);
    ob->set_temp("wait_answer/yutu", 1);
}

int do_answer(string arg)
{
    object ob = this_player();
    object me = this_object();
    string str;
    if (!ob || !ob->query_temp("wait_answer/yutu")) return 0;
    if (arg == "1") {
        ob->set_temp("wait_answer/yutu", 0);
        message_vision(CYN "$N����������棡\n\n" NOR, ob);
        command("wink " + ob->query("id"));
        message_vision("$N�Ի������$n��������������¹���ʲô����ģ���������ġ�\n", me, ob);
        command("say �ðɣ��������ɡ�");
        call_out("disappearing", 3);
        return 1;
    }
    else if (arg == "2") {
        ob->set_temp("wait_answer/yutu", 0);
        message_vision(CYN "$N�����������ʦ��\n\n" NOR, ob);
        command("look " + ob->query("id"));
        if (ob->query("gender") != "Ů��") {
            command("shake");
            command("say �¹��ﶼ��Ů���ӣ�" + RANK_D->query_respect(ob) + "һ������������ʲôʦ����\n");
            command("sigh");
            command("say ��Ը˵������");
            call_out("disappearing", 3);
            return 1;
        } else if (ob->query_skill("dodge", 1) > 120 || ob->query_skill("moondance", 1) > 120) {
            command("jump");
            command("say " + RANK_D->query_respect(ob) + "������������������������˲ż��룬�����¹�һ�����Դ����ԯ��Ĺ�ġ�");
            call_out("disappearing", 3);
            return 1;
        } else {
            command("jump");
            command("say �Ժ������»���ˡ�");
            command("say �ţ��ҿ�����ȥ����ͦ�Ѿ��ģ��������һ�Ѱɡ�\n");
            message_vision("$N����ͻȻ���������֦Ҷ�䡣\n", ob);
            ob->move("/d/moon/ontop");
            message_vision("$NͻȻ�ӹ���֦Ҷ��ɳ�����ƮƮ�����ڵ��ϡ�\n", ob);
            call_out("disappearing", 3);
            return 1;
        }
    }
    else if (arg == "3") {
        ob->set_temp("wait_answer/yutu", 0);
        message_vision(CYN "$N��������������ݣ�\n\n" NOR, ob);
        command("wink " + ob->query("id"));
        message_vision("$N�Ի������$n������������������ݣ�û��˵���¹���˭�������ݰ���\n", me, ob);
        command("say �ò��ᡣ�������Ǹ��˵����ݰɣ�");
        message_vision("$N����ͻȻ����ʲô�Ƶģ�����¶���־�����飬��æ���첻˵���ˡ�\n", me);
        call_out("disappearing", 1);
        return 1;
    } else
        return 0;
}

void disappearing()
{
    if (!is_fighting()) {
        message_vision("$N�ı��������뿪�ˡ�\n", this_object());
        destruct(this_object());
    }
    remove_call_out("disappearing");
    call_out("disappearing", 120);
}

void endfight()
{
    command("surrender");
    if (random(2)) {
        command("say �����Һ�ʹ�����������ˡ�");
        command("angry");
    } else {
        command("say �����ˣ������ˣ���̫�������ˡ�");
        command("sigh");
    }
    random_move();
}

void init()
{
    object me = this_player();
    remove_killer(this_player());
    remove_enemy(this_player());

    ::init();
    add_action("do_answer", "answer");
}

int accept_fight(object me)
{
    command("jump");
    command("say ���������������ˡ�");
    kill_ob(me);
    return 1;
}

int kill_ob(object victim)
{
    set_skills(victim);
    return ::kill_ob(victim);
}

void set_skills(object me)
{
    mapping skill = me->query_skills();
    int max_value = 10;
    string *skillnames;

    if (!skill) return;
    skillnames = keys(skill);
    for (int i=0; i<sizeof(skillnames); i++) 
        if (skill[skillnames[i]] > max_value)
            max_value = skill[skillnames[i]];

    if (query("max_force") < me->query("max_force")) 
        set("max_force", me->query("max_force")*(10+random(3))/10);
    if (query("max_mana") < me->query("max_mana")) 
        set("max_mana", me->query("max_mana")*(10+random(3))/10);
    if (query("comat_exp") < me->query("combat_exp")) 
        set("combat_exp", me->query("combat_exp")*(10+random(3))/10);
    set("force", query("max_force"));
    set("mana", query("max_mana"));
    if (query_skill("unarmed") < max_value) {
        max_value = max_value*(10+random(3))/10;
        set_skill("force", max_value);
        set_skill("moonforce", max_value);
        map_skill("force", "moonforce");
        set_skill("spells", max_value);
        set_skill("moonshentong", max_value);
        map_skill("spells", "moonshentong");
        set_skill("unarmed", max_value);
        set_skill("flower-hand", max_value);
        map_skill("unarmed", "flower-hand");
        set_skill("dodge", max_value*2+random(2));
        set_skill("hammer", max_value*2+random(2));
        set_skill("parry", max_value*2);
        set("force_factor", (int)query_skill("force") / 2);
    }
}

varargs int receive_damage(string type, int damage, object who)
{
    object weapon = who->query_temp("weapon");
    int lvl, amount;
    string skill, attack_skill;

    if (objectp(weapon)) {
        if (weapon->query("use_apply_skill"))
            attack_skill = weapon->query("apply/skill_type");
        else
            attack_skill = weapon->query("skill_type");
    }
    else attack_skill = "unarmed";

    skill = who->query_skill_mapped(attack_skill);
    if (skill && type=="kee") {
        lvl = who->query_skill(skill, 1);
        amount = lvl + who->query_skill(attack_skill, 1);
        amount += query_skill("dodge");
        if (SKILL_D(skill)->practice_skill(who)
        &&  lvl*lvl*lvl/10 < (int)who->query("combat_exp"))
            who->improve_skill(skill, amount*(10+random(10))/15, 0);
    }
    delete_temp("no_move");
    return ::receive_damage(type, damage, who);
}

void reset_action()
{
    object me = this_object();
    mapping action;
    mapping new_act = ([]);

    ::reset_action();
    if (!action=query("actions")) return;
    new_act=copy(action);
    if (new_act["post_action"]) 
        new_act["post_action"]= (: reward :);
    else new_act += (["post_action" : (: reward :) ]);
    set("actions", new_act);
}

void reward(object me,object victim, object weapon, int damage)
{
    int lvl = 0;
    string skill = victim->query_skill_mapped("dodge");
    int ammount;

    if (!skill || damage!= RESULT_DODGE) return;
    lvl = victim->query_skill(skill, 1);
    ammount = lvl;
    if (weapon) ammount = query_skill("hammer", 1);
    if (SKILL_D(skill)->practice_skill(victim)
    &&  lvl*lvl*lvl/10 < (int)victim->query("combat_exp"))
        victim->improve_skill(skill, ammount*(10+random(10))/15, 0);
}

