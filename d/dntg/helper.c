#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

#define DNTG_START_ROOM "/d/hgs/inner"
#define HUAG_GETFLAG_ROOM "/d/hgs/shifang"
#define HUAG_WAVE_ROOM "/d/hgs/fall"
#define HUAG_VOTE_ROOM "/d/hgs/throne"
#define DONH_ASNL_ROOM "/d/4world/arsenal"
#define DONH_DRILL_ROOM "/d/4world/drill"
#define DONH_DRILLENT_ROOM "/d/4world/drillent"
#define DONH_GATE_ROOM "/d/sea/under1"
#define DONH_PLAYG_ROOM "/d/hgs/playground"
#define DONH_PALACE_ROOM "/d/sea/inside3"
#define HELL_BED_ROOM "/d/hgs/ironbridge"
#define HELL_ENT_ROOM "/d/death/new-zhaopo"

#define NPC_BAIWC "/d/death/npc/baiwuchang"
#define NPC_HEIWC "/d/death/npc/heiwuchang"

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
    map_skill("force", "nine-turn");
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

void report_progress(int co)
{
    call_out("do_report_progress", co);
}

void do_report_progress()
{
    string prog = "";
    object ob = query_temp("chosen");
    object foo;
    
    if (!ob) return;
    if (ob->query("dntg/huaguo") != "done") {
        prog = "���ȣ���Ҫ��Ϊ����ɽˮ������Ⱥ��֮��";
        foo = new(__DIR__"huaguo/flag");
        foo->set("owner", ob);
        foo->place_room(HUAG_GETFLAG_ROOM);
    }
    else if (ob->query("dntg/donghai") == 0) {
        prog = "���Ѿ��ǻ���ɽ��Ⱥ��֮���ˣ�������Ҫ�����ǲ������µ�Ⱥ�������ɽ�����ͭǽ����";
        foo = new(__DIR__"donghai/rack");
        foo->set("owner", ob);
        foo->move(DONH_ASNL_ROOM);
    }
    else if (ob->query("dntg/donghai") != "done") {
        prog = "�ߣ��ߣ��ߣ�ȥ������ȥ�ý𹿰���";
        foo = new(__DIR__"donghai/patrol");
        foo->set("target", ob);
        foo->move(DONH_GATE_ROOM);
    }
    else if (ob->query("dntg/hell") == 0) {
        tell_object(ob, name() + CYN "����������������������������ֵظ�������ϲ���ֵظ��ˣ�\n" NOR);
        prog = "�ߣ��ߣ��ߣ���ȥ��������˯����";
        foo = new(__DIR__"hell/bed");
        foo->set("owner", ob);
        foo->set("hell_ent_room", HELL_ENT_ROOM);
        foo->set("npc_baiwc", NPC_BAIWC);
        foo->set("npc_heiwc", NPC_HEIWC);
        foo->move(HELL_BED_ROOM);
    }
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

void speak_one(int i)
{
    object ob = query_temp("chosen");
    mixed* msgs = query_temp("speak_msgs");

    remove_call_out("speak_one");
    if (!ob || !msgs || i >= sizeof(msgs)) return;
    if (stringp(msgs[i])) tell_object(ob, name() + msgs[i] + "\n");
    else if (functionp(msgs[i])) evaluate(msgs[i], ob);
    call_out("speak_one", 1, i + 1);
}

void speak(mixed* msgs)
{
    set_temp("speak_msgs", msgs);
    call_out("speak_one", 1, 0);
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
    
    report_progress(3);
    return 1;
}

void disappear()
{
    object chosen = query_temp("chosen");
    if (chosen)
        tell_object(chosen, name() + CYN "�ȵ���" + chosen->name(1) + CYN "����̫����ʧ���ˣ���Ͳ��Ǹ��������µ��ˣ�\n" NOR);
    message_vision("\n$NͻȻ����һ����������ʣ������ˡ�\n", this_object());
    destruct(this_object());
}

void unconcious()
{
    set_temp("chosen", 0);
    disappear();
}

void die()
{
    unconcious();
}

int check_room(string room)
{
    object chosen = query_temp("chosen");
    if (!chosen) return 0;
    return file_name(environment(chosen)) == room;
}

int check_huaguo_waveroom()
{
    return check_room(HUAG_WAVE_ROOM);
}

int check_huaguo_voteroom()
{
    return check_room(HUAG_VOTE_ROOM);
}

object get_object(string fname)
{
    if (!find_object(fname))
        load_object(fname);
    return find_object(fname);
}

object get_drillent_room()
{
    return get_object(DONH_DRILLENT_ROOM);
}

object get_drill_room()
{
    return get_object(DONH_DRILL_ROOM);
}

object get_arsenal_room()
{
    return get_object(DONH_ASNL_ROOM);
}

object get_playg_room()
{
    return get_object(DONH_PLAYG_ROOM);
}

object get_palace_room()
{
    return get_object(DONH_PALACE_ROOM);
}
