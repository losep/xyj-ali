// flag.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("����", ({"flag","qi"}));
    set("unit", "��");
    set_weight(500);
    set("long", @LONG
        ***********************************************
        **      �ô����߿�Ϊ���鸣��ˮ����֮����     **
        ***********************************************
LONG);
    set("env/invisibility", 1);
    set("no_get", 1);
    seteuid(getuid());
    setup();
}

string short()
{
    object owner = query("owner");
    int inv = (int)query("env/invisibility");
    
    if (!owner || !inv) return ::short();
    else return sprintf("%s[owner: %s]", ::short(), geteuid(owner));
}

void place_room(string room)
{
    room->set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ��(bed)��
ʯ�ʣ����ּҵ�������ȫ����һ���������İ���֮�������м����
һ�˴���(flag)��
LONG);
    room->set("item_desc/flag",
            "һ��ӭ����չ����ɫ���죬�ڿտ�֮��ӭ�����(wave)����һ��ɷ�Ǻÿ������ƺ����Ѱ�(ba)����\n");
    this_object()->set("home", room);
    this_object()->move(room);
}

void init()
{
    object who = environment();
    
    if (userp(who)) {
        if (query("owner") != who)
            call_out("destruct_me", 1, who, this_object());
    }
    add_action("do_ba", "ba");
    add_action("do_wave", "wave");
}

void destruct_me(object who, object me)
{
    message_vision("һ����紵����$n����һ�Żҽ���\n", who, me);
    destruct(me);
}

int do_ba(string arg)
{
    object me = this_player();
    object env = environment();

    if (file_name(env) != query("home")) return 0;

    if (!arg || !id(arg)) return notify_fail("��Ҫ��ʲô��\n");

    if (me->query("dntg/huaguo") == "done")
        return notify_fail("������"+name()+"�����������Լ������ڴ˳����Ŀ���ʱ�⡣\n");

    if (me != query("owner"))
        return notify_fail("��ʹ�����̵�����Ҳû��"+name()+"�γ�����\n");

    if (me->query("kee") <= 200) {
        me->unconcious();
        return 1;
    }
    me->receive_damage("kee", 200);
    if (random(10) < 5)
        message_vision("$Nʹ�����̵�����Ҳû��"+name()+"�γ�����\n", me);
    else {
        env->set("long", @LONG

һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ��(bed)��
ʯ�ʣ����ּҵ�������ȫ����һ���������İ���֮����
LONG);
        env->delete("item_desc/flag");
        this_object()->delete("env/invisibility");
        this_object()->delete("no_get");
        this_object()->move(me);
        message_vision("$N���һ������"+name()+"����������\n", me);
    }
    return 1;
}

int do_wave(string arg)
{
    object me = this_player();
    object hb;

    if (me != query("owner") || me != environment()) return 0;
    if (!arg || !id(arg)) return notify_fail("�������ʲô��\n");

    if (!(hb = me->query_temp("dntg_helper"))) {
        destruct_me(me, this_object());
        return 1;
    }
    if (!hb->check_huaguo_waveroom())
        return notify_fail("�����ӣ�Ҫ������"+name()+"����Ӧ����Ƭ�����ء�\n");
    if (me->query("dntg/huaguo") == "done")
        return notify_fail("��������е�"+name()+"�������˵����ڴ˳����Ŀ���ʱ�⡣\n");
    message_vision("$N�����������ӣ����һ���������컯�����컯������ûˮ��ԭ����һ�������š����Ǳ���һ���������ļҵ����ֵ��ǿ�ȥѽ����\n", me);
    call_out("monkeys_jump", 2, environment(me));
    call_out("monkeys_follow", 1, me);
    load_object("/obj/empty");
    move("/obj/empty");
    return 1;
}

void monkeys_jump(object where)
{
    object who1 = present("hou zi 1", where);
    object who2 = present("hou zi 2", where);
    object who3 = present("hou zi 3", where);
    object who4 = present("hou zi 4", where);
    if (who1) destruct(who1);
    if (who2) destruct(who2);
    if (who3) destruct(who3);
    if (who4) destruct(who4);
    message("vision", "�������������ȿֺ�������ٲ���\n", where);
    set("monkeys_jumped", 1);
}

void monkeys_follow(object me)
{
    object hb;
    object houzi;
    object where = environment(me);
    
    if (!(hb = me->query_temp("dntg_helper"))) {
        destruct(this_object());
        return;
    }
    
    if (!query("monkeys_jumped") || !hb->check_huaguo_voteroom()) {
        remove_call_out("monkeys_follow");
        call_out("monkeys_follow", 2, me);
        return;
    }
    
    message_vision("һȺ���Ӹ���$N�ı����������˹�����\n", me);
    while (!present("hou zi 4", where)) {
        houzi = new(__DIR__"hou");
        houzi->set("king", me);
        houzi->move(where);
        me->set_temp("people/" + me->add_temp("people_num", 1), houzi);
    }
    me->start_busy(25);
    call_out("jing_appearing", 25, me);
}

void jing_appearing(object me)
{
    object jing;
    object where = environment(me);
    
    message("vision", HIR "\n�ڰ���ͻȻ�ܳ�һȺ�ǳ滢��������\n\n" NOR, where);
    while (!present("jing 3", where)) {
        jing = new(__DIR__"jing");
        jing->move(where);
        jing->kill_ob(me);
    }
    destruct(this_object());
}
