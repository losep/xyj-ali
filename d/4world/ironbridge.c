#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

��Ƿ������ͷ�������ٿ���ȴ�����˼�ס��һ�㣬��������ڡ������ǣ�

������޺���������Ƹ��񣬹�ҡƬƬ��ϼ���鴰���ң����ʰ����������
���������йң��ӻ��������⡣�ּ���һ�����������������÷������
���������ɳ����꣬��Ȼ����˼ҡ�

���ն�ʱ���������м䣬���ҹۿ���ֻ����������һʯ��(shi jie)��
LONG
    );

    set("item_desc", ([
        "shi jie": @SHIJ
��������������������������������
��������������ˮ������������������������
������������������������������������������
����������������������������ɽ����������
����������������������������������������
����������������������������ء���������
��������������������������������
SHIJ
    ]));

    set("exits", ([
        "east"   : __DIR__"shifang",
    ]));
    create_door("east", "ʯ��", "west", DOOR_CLOSED);
    setup();
}

void init ()
{
    add_action("do_jump", "jump");
    add_action ("do_sleep","sleep");
}

int do_jump(string arg)
{
    object me = this_player();
    if (!arg || arg != "bridge")
        return notify_fail("�����Ķ�����\n");

    if (random(30) + me->query("kar") < 30) {
        message_vision("$N��������һԾ���ִӰ����ˤ��������\n", me);
        me->unconcious();
    } else {
        message_vision("$N�����Ϸ����ݳ��ٲ���\n", me);
        me->move(__DIR__"fall");
    }

    return 1;
}

int is_drunk(object me)
{
    int limit = me->query("con")*6+(int)me->query("max_force")/50;
    int duration = me->query_condition("drunk");
    return (duration > limit / 10);
}

int do_sleep (string arg)
{
    object me = this_player();
    int phase = NATURE_D->get_current_day_phase();

    if (me->query("combat_exp") < 50000) return 0;
    if (me->query("dntg/hell") == "done") return 0;
    if (me->query_temp("dntg_hell/next")) return 0;

    if (phase > 0 && phase < 5) {
        tell_object(me, "������˯ʲô����\n");
        return 1;
    }
    if (!is_drunk(me)) {
        tell_object(me,"�㾫��ʮ�㣬����Ҫ˯����\n");
        return 1;
    }

    message_vision("$N�ȵ��������������������ű�����֮�£���ʱ��˯���ˡ�\n", me);
    remove_call_out("go_hell");
    me->start_busy(7);
    call_out("go_hell", 2+random(5), me);
    return 1;
}

void go_hell(object me)
{
    object env;
    object hei, bai;
    object piwen;
    mapping wangs = (["qingguang":"�ع���","songdi":"�ε���","chujiang":"������",
        "chuguan":"������","pingdeng":"ƽ����","dushi":"������","taishan":"̩ɽ��",
        "lunzhuan":"��ת��","biancheng":"�����","yanluo":"������"]);
    string wang = ((string *)keys(wangs))[random(sizeof(wangs))];

    me->interrupt_me(0, 0);
    me->set_temp("dntg_hell/next", wang);

    tell_object(me, HIB"\n˯���к����������˹����������ȵ�����"+me->query("name")+
                "���������Ѿ�����ȷ�ڤ��֮�����������㡣��\n"
                +"˵�ղ��ݷ�˵���ø��������㾱��һ�ף����˾��ߡ�\n\n"NOR);
    env = load_object("/d/death/new-zhaopo");
    if (!bai = present("bai wuchang", env)) {
        bai = new("/d/death/npc/baiwuchang");
        bai->move(env);
    }
    if (!hei = present("hei wuchang", env)) {
        hei = new("/d/death/npc/heiwuchang");
        hei->move(env);
    }
    me->move(env);

    piwen = new("/d/dntg/hell/piwen");
    if (random(2)) piwen->move(hei);
    else piwen->move(bai);
    piwen->set("long","    ��"+me->query("name")+
                "�����Ѿ�������ڰ��޳�������ǹ��ù鰸��\n\n"+
                "                            "+wangs[wang]+"  ��\n\n\n");

    piwen->set("target", me->query("name"));
}
