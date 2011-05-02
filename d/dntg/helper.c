#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

#define DNTG_START_ROOM "/d/hgs/inner"
#define HUAG_GETFLAG_ROOM "/d/hgs/shifang"
#define HUAG_WAVE_ROOM "/d/hgs/fall"

string ask_for_dntg();
string ask_for_detail();
void one_hit_to_die(object me, object victim, object weapon, int damage);

void create()
{
    set_name(HIY "�𹿰�" NOR, ({ "jingu bang", "jingubang", "bang", "ruyi"}));
    set_weight(10);
    set("title", HIY "����" NOR);
    set("gender", "����");
    set("long", @LONG
����ǵ��������ʥ������õı�������֪Ϊʲô����ʥ���������˻���ɽ��
��Ϊ�˹�������ʵ��̫�����Ծ�Ȼ�����������Ϊһ��ͨ��ı�����
LONG );
    set("age", 500);
    set("unit", "��");
    set("race", "��ħ");
    set("limbs", ({ "����" }));
    set("can_speak", 1);
    set("rank_info/respect", "�𹿰�����");
    set("rank_info/rude", "������");
    set("str", 40);
    set("per", 120);
    set("int", 50);
    set("combat_exp", 10000000);
    set_skill("force",  250); 
    set_skill("spells", 250); 
    set_skill("unarmed",250);
    set_skill("dodge",  250);
    set_skill("parry",  250);
    set_skill("stick",  250);
    set_skill("qianjun-bang",  250);
    map_skill("force", "ningxie-force");
    map_skill("stick", "qianjun-bang");
    map_skill("parry", "qianjun-bang");
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
    set("atman", 1500);
    set("max_atman", random(1200)+1500);
    set("force_factor", 50);

    set("no_get", 1);
    set("no_drop", 1);
    set("replace_file", "/d/obj/weapon/stick/bintiegun");

    setup();
}

void init()
{
    object ob = this_player();
    
    if (environment() == environment(ob)
    &&  !OBSTACLES_D->check_obstacles(ob, "dntg")) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }

    add_action("do_swear", "swear");
    add_action("do_ba", "ba");
    add_action("override_move", ({ "go", "west", "east", "south", "north" }));
}

void greeting(object ob)
{
    object me = this_object();
    if (environment() != environment(ob)) return;
    
    command("say hi, " + RANK_D->query_respect(ob) + "�벻����������³���������\n");
    set("inquiry", ([
        "����" : "Ҫ˵��������Ȼ�����ƴ����칬����\n",
        "�����칬" : (: ask_for_dntg :),
        "dntg" : (: ask_for_dntg :),
        "����ʲô" : (: ask_for_detail :),
    ]));
}

string ask_for_dntg()
{
    object ob = this_player();
    if (OBSTACLES_D->check_obstacles(ob, "dntg"))
        return "�㲻���Լ�Ҳ���������𣬻����ң�";
    command("say Ҫ˵������칬�����ǵ��������ʥ����յ�׳�١�");
    command("say �����ʱ�������٣�����û�����ܸ���");
    ob->set_temp("pending/ask_for_detail", 1);
    return "���ǡ�����";
}

string ask_for_detail()
{
    object ob = this_player();
    if (!ob->query_temp("pending/ask_for_detail")) {
        command("?");
        return "������˵����ôǰ�Բ������ģ�";
    }
    command("say ���ǽ��ܱ����˼ҵ�ָ�㡣");
    command("hehe");
    command("say " + RANK_D->query_respect(ob) + "Ҫ��Ը�⣬�ͷ�һ����(swear)��˵��Ҫ�������칬����");
    ob->delete_temp("pending/ask_for_detail");
    return "�����˼���������ã�˵������ָ�����㡣";
}

void reset_action()
{
    set("actions", ([
        "action":     "$N�Ӷ����幥��$n��$l",
        "damage_type":   "������",
        "post_action":   (: one_hit_to_die :)
    ]));
}

void one_hit_to_die(object me, object victim, object weapon, int damage)
{
    if (damage > 0) {
        message_vision("$N���Ϸ����һ������ĺ�⣡����\n", me);
        victim->die();
    }
}

void unconcious()
{
    message_vision("\n$NͻȻ����һ����������ʣ������ˡ�\n", this_object());
    destruct(this_object());
}

void die()
{
    unconcious();
}

void report_progress(object ob)
{
    string prog = "";
    if (ob->query("dntg/huaguo") != "done")
        prog = "��һ���£���Ҫ���ȳ�Ϊ����ɽˮ������Ⱥ��֮��";
    else if (ob->query("dntg/donghai") != "done")
        prog = "�ڶ����£��������Ѿ��ǻ���ɽˮ������Ⱥ��֮���ˣ���Ҫ�������µ�Ⱥ�������ɽ�����ͭǽ����";
    else {
        if (OBSTACLES_D->check_obstacles(ob, "dntg")) {
            tell_object(ob, name() + CYN "�����˵�����ף�"
                    + RANK_D->query_respect(ob) + "��Ȼ�Ѿ�����˴����칬��׳�٣�\n" NOR);
            tell_object(ob, name() + CYN "������������\n" NOR);
            tell_object(ob, name() + CYN "��������Ҳ��\n" NOR);
            tell_object(ob, name() + "����һ����⣬��������ʡ�\n");
            destruct(this_object());
        }
        return;
    }
    tell_object(ob, name() + CYN "����������е���" + prog + "��\n" NOR);
}

int do_swear(string arg)
{
    object ob = this_player();
    if (environment() == ob) return 0;
    if (OBSTACLES_D->check_obstacles(ob, "dntg")) return 0;
    if (!arg) return notify_fail("��Ҫ����ʲô���ԣ�\n");
    message_vision("$Nָ�췢�ģ���Ҫ " + arg + " ��\n", ob);
    if (arg != "�����칬") {
        tell_object(ob, "����ʲôҲû�з�����\n");
        return 1;
    }
    command("haha");
    command("say �ã��ã��ã�");
    command("say " + RANK_D->query_respect(ob) + "��Ȼ�ɴ�����׳־�������˼Ҿ�����һ���컯��");
    message_vision("ٿ��һ����$n�Զ��ɽ���$P�Ļ��\n", ob, this_object());
    set_temp("chosen", ob);
    ob->set_temp("dntg_helper", this_object());
    move(ob);
    environment(ob)->open_door();
    
    call_out("report_progress", 3, ob);
    return 1;
}

int do_ba(string arg)
{
    object me;
    object env;
    object qi;

    if ((me = query_temp("chosen")) != this_player())
        return 0;
    if (file_name(env = environment(me)) != HUAG_GETFLAG_ROOM)
        return 0;

    if (!arg || arg != "flag")
        return notify_fail("��Ҫ��ʲô��\n");
    if (present("flag", me))
        return notify_fail("�㲻���Ѿ�����������\n");
    else if (env->query("getflag"))
        return notify_fail("�����Ѿ������˰����ˣ�����ֻ����һ����ˡ�\n");
    else if (me->query("dntg/huaguo") == "done")
        return notify_fail("�����մ��죬���������Լ������ڴ˳����Ŀ���ʱ�⡣\n");

    if (me->query("kee") <= 200) {
        me->unconcious();
        return 1;
    }
    me->receive_damage("kee", 200);
    if (random(10) < 5)
        message_vision("$Nʹ�����̵�����Ҳû������γ�����\n", me);
    else {
        qi = new("/d/dntg/huaguo/flag");
        qi->move(me);
        message_vision("$N���һ�������������������\n", me);
        env->set("getflag", 1);
        call_out((: call_other, HUAG_GETFLAG_ROOM, "delete" :), 1200, "getflag");
    }
    return 1;
}

int check_huaguo_waveroom()
{
    object chosen = query_temp("chosen");
    if (!chosen) return 0;
    return file_name(environment(chosen)) == HUAG_WAVE_ROOM;
}

int override_move(string dir)
{
    string verb = query_verb();
    object chosen = query_temp("chosen");
    
    if (verb != "go") dir = verb;
    if (chosen != this_player()) return 0;
    
    switch (file_name(environment(chosen))) {
        case HUAG_GETFLAG_ROOM:
            if (dir == "east" && chosen->query("dntg/huaguo") != "allow") {
                tell_object(chosen, "��ֻС�����ܹ������㺰��������������ѡ������û�±������ҡ���\n");
                tell_object(chosen, "С�����ּ��Ҵҵ����ˡ�\n");
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}
