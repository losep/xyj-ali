#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

string ask_for_dntg();
string ask_for_detail();

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
    set("race", "��ħ");
    set("can_speak", 1);
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
    set("unit", "��");
    set("material", "gold");
    set("weapon_prop/damage", 800);
    set("replace_file", "/d/obj/weapon/stick/bintiegun");
    set("wield_msg", "$Nһ���֣����ȼ������󣡴󣡴����к�Ȼ����һ��$n��\n");
    set("unwield_msg", "$Nһ������������ȣ�С��С��С��$n��$N����ת�˼�ת����Ȼ�����ˡ�\n");

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
    command("say ���ǽ��ܴ�ү�ҵ�ָ�㡣");
    command("hehe");
    ob->delete_temp("pending/ask_for_detail");
    return RANK_D->query_respect(ob) + "Ҫ��Ը�⣬�ͷ�һ����(swear)��˵��Ҫ�����칬��";
}

int accept_fight(object ob)
{
    return 0;
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

int do_swear(string arg)
{
    object ob = this_player();
    if (environment() == ob) return 0;
    if (OBSTACLES_D->check_obstacles(ob, "dntg")) return 0;
    if (!arg) return notify_fail("��Ҫ����ʲô���ԣ�\n");
    message_vision("\n$Nָ�췢�ģ���Ҫ " + arg + " ��\n", ob);
    if (arg != "�����칬") {
        tell_object(ob, "����ʲôҲû�з�����\n");
        return 1;
    }
    message_vision("ٿ��һ����$n�Զ��ɽ���$P�Ļ��\n", ob, this_object());
    move(ob);
    return 1;
}
