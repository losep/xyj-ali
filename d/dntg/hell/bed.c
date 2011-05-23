
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("����֮��", ({"hell bed"}));
    set("env/invisibility", 1);
    set_weight(100);
    set("no_get", 1);
    seteuid(getuid());
    setup();
    call_out("destruct_me", 1200);
}

string short()
{
    object owner = query("owner");
    if (!owner) return "����֮��";
    else return sprintf("����֮��(owner: %s)", geteuid(owner));
}

void init()
{
    add_action("do_sleep", "sleep");
}

int is_drunk(object me)
{
    int limit = me->query("con")*6 + (int)me->query("max_force")/50;
    int duration = me->query_condition("drunk");
    if (duration > limit/10) return 1;
    return 0;
}

int do_sleep(string arg)
{
    object me = this_player();
    int phase = NATURE_D->get_current_day_phase();

    if (me != query("owner")) return 0;
    if (me->query("combat_exp") < 50000) return 0;
    if (me->query("dntg/hell") == "done") return 0;
    if (me->query_temp("dntg_hell/next")) return 0;
    if (phase > 0 && phase < 5) {tell_object(me, "������˯ʲô����\n");return 1;}
    if (!is_drunk(me)) {tell_object(me, "�㾫��ʮ�㣬����Ҫ˯����\n");return 1;}

    message_vision("$N�ȵ��������������������ű�����֮�£���ʱ��˯���ˡ�\n",me);
    remove_call_out("go_hell");
    call_out("go_hell", 2+random(5), me);
    return 1; 
}

void go_hell(object me)
{
    object env;
    object hei, bai;
    object piwen;
    string bwc = "/d/death/npc/baiwuchang";
    string hwc = "/d/death/npc/heiwuchang";
    string hell_room = "/d/death/new-zhaopo";
    mapping wang = ([ "qingguang":"�ع���", "songdi":"�ε���", "chujiang":"������",
        "chuguan":"������", "pingdeng":"ƽ����", "dushi":"������", "taishan":"̩ɽ��",
        "lunzhuan":"��ת��", "biancheng":"�����", "yanluo":"������" ]);
    string sb;

    tell_object(me, HIB "\n˯���к����������˹����������ȵ�����"
                + me->query("name") + "���������Ѿ�����ȷ�ڤ��֮�����������㡣��\n"
                + "˵�ղ��ݷ�˵���ø��������㾱��һ�ף����˾��ߡ�\n\n" NOR);
    me->move(hell_room);
    env = environment(me);
    if (!(bai = present("bai wuchang", env))) {
        bai = new(bwc);
        bai->move(env);
    }
    if (!(hei = present("hei wuchang", env))) {
        hei = new(hwc);
        hei->move(env);
    }

    piwen = new(__DIR__"piwen");
    if (random(2)) piwen->move(hei);
    else piwen->move(bai);

    sb = keys(wang)[random(sizeof(wang))];
    me->set_temp("dntg_hell/next", sb);
    piwen->set("long","    ��"+me->query("name")
                + "�����Ѿ�������ڰ��޳�������ǹ��ù鰸��\n\n"
                + "                            "+wang[sb]+"  ��\n\n\n");
    piwen->set("target", me->query("name"));
    call_out("destruct_me", 1);
}

void destruct_me()
{
    destruct(this_object());
}

