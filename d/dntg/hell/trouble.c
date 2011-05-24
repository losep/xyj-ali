
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("����", ({"trouble"}));
    set("env/invisibility", 1);
    set_weight(100);
    set("no_get", 1);
    seteuid(getuid());
    setup();
    call_out("destruct_me", 1200);
}

void destruct_me()
{
    destruct(this_object());
}

string short()
{
    object owner = query("owner");
    if (!owner) return "����";
    else return sprintf("����(owner: %s)", geteuid(owner));
}

mapping wangs = ([ "qingguang":"�ع���", "songdi":"�ε���", "chujiang":"������",
    "chuguan":"������", "pingdeng":"ƽ����", "dushi":"������", "taishan":"̩ɽ��",
    "lunzhuan":"��ת��", "biancheng":"�����", "yanluo":"������" ]);

string get_next(object wang);

void init()
{
    object who = this_player();
    object wang;

    if (!query("wang") && query("waiting")) {
        foreach (string w in keys(wangs)) {
            if (who->query("id") == w + " wang") {
                set("wang", who);
                delete("waiting");
                break;
            }
        }
    }
    if (query("owner") == who) {
        if (wang = query("wang"))
            wang->fully_recover();
    }
    add_action("do_complain", "complain");
    add_action("do_surrender", "surrender");
    add_action("do_kill", "kill");
}

int do_complain(string arg)
{
    object me = query("owner"), wang = query("wang");
    string complainee;
    
    if (!me || me != this_player()) return 0;
    if (!wang || environment(wang) != environment()) return 0;
    if (!arg || !wang->id(arg))
        return notify_fail("��Ҫ��˭���ߣ�\n");

    message_vision("$N����$n�е�����" + RANK_D->query_self_rude(me) +
        "���ѳ�������֮�⣬��������֮�У��Ѳ�����˾��Ͻ����ô�������ң���\n", me, wang);
    me->command_function("bug");

    complainee = me->query_temp("dntg_hell/next");
    if (!complainee) {
        message_vision("\n$N������üͷ����$n˵����������������;��" +
            "�Ҳ�����˽����ڤ֮�Ҳ�����ˡ�����������£���\n\n", wang, me);
        return 1;
    }
    if (wangs[complainee] != wang->name()) {
        message_vision("\n$N������üͷ����$n˵���������·��Ҿ��֣�" +
            "ԩ��ͷ��ծ�������ĸ�ǲ�˹��㣬��ȥ���ĸ��ɡ���\n\n", wang, me);
        me->set_temp("dntg_hell/next", get_next(wang));
        return 1;
    }
    me->delete_temp("dntg_hell/ready");
    message_vision("\n$N���߳�ŭ����������������������˭�����㵽�����"+
        "������������ȥ�����й٣���\n", wang);
    wang->set_temp("target", me);
    wang->kill_ob(me);
    return 1;
}

string get_next(object wang)
{
    string who = keys(wangs)[random(sizeof(wangs))];
    while (wangs[who] == wang->query("name"))
        who = keys(wangs)[random(sizeof(wangs))];
    return who;
}

int do_surrender()
{
    object who = query("owner"), wang = query("wang");
    string next;

    if (this_player() != wang) return 0;
    if (wang->query_temp("target") != who) return 0;

    who->set_temp("dntg_hell/" + wang->name(), 1);
    message_vision(HIW "\n$N˵�����������ˣ������ˣ���Ͷ��....����\n\n" NOR, wang);
    wang->command_function("say "+who->name()+RANK_D->query_respect(who)+
        "��ͨ���С���ʰ��·硣");
    next = get_next(wang);
    who->set_temp("dntg_hell/next", next);
    message_vision("$N���˷����ϵ����飬��$n˵������������" + wangs[next]
        + "�������ˣ�ҪС������" + RANK_D->query_respect(who) + "��" + RANK_D->query_respect(who)
        + "����ȥ�������۰ɡ�\n\n", wang, who);

    if (who->query_temp("dntg_hell/" + wangs[next]))
        who->set_temp("dntg_hell/ready", wang);

    return 1;
}

int do_kill(string arg)
{
    object who = query("owner"), wang = query("wang");
    string next;

    if (this_player() != who) return 0;
    if (present(arg, environment()) != wang) return 0;
    if (who->query_temp("dntg_hell/ready") != wang) return 0;
    if (who->query("dntg/hell") == "done") return 0;
    if (!(next = who->query_temp("dntg_hell/next"))) return 0;

    message_vision("$N�İ���У�����ô����" + wangs[next]
        + "���������������ˣŪ���ң�����������\n\n", who);
    message_vision("$N�ŵû����ɢ������˵�������˰��ˣ����㣬�����㡣��\n", wang);
    message_vision("$N�Ӱ����ó���������������ʣ���պŨī����$n�����ֻ�ȥ��\n\n", wang, who);

    who->set("dntg/hell", "done");
    wang->command_function("chat "+ who->query("name") +"��"+ RANK_D->query_rude(who) +
        "��ǿ���ף������л���������ɭ��ǿ�����ţ���������������ۣ��������㣡");
    wang->delete_temp("target");
    who->delete_temp("dntg_hell");

    __FILE__->uninstall();
    return 1;
}

void install(object owner, string* rooms)
{
    object o;
    
    if (clonep()) return;
    
    for (int i = 0; i < sizeof(rooms); i++) {
        o = new(__FILE__);
        o->set("owner", owner);
        o->set("waiting", 1);
        o->move(rooms[i]);
    }
}

void uninstall()
{
    if (clonep()) return;
    
    foreach (object o in children(__FILE__))
        if (o != this_object()) destruct(o);
    
    destruct(this_object());
}
