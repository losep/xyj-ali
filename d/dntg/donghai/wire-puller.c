// wire-puller.c

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("Ļ�������", ({"wire-puller"}));
    set("env/invisibility", 1);
    set_weight(100);
    set("no_get", 1);
    seteuid(getuid());
    setup();
}

string short()
{
    object owner = query("owner");
    if (!owner) return "Ļ�������";
    else return sprintf("Ļ�������(owner: %s)", geteuid(owner));
}

void start_testing()
{
    object owner = query("owner");
    object ao = present("ao guang", environment());

    if (!owner) {
        call_out("destruct_me", 1);
        return;
    }
    if (!ao || !ao->is_character()) {
        call_out("destruct_me", 1);
        return;
    }
    if (!ao->query("dntg_questing")) {
        ao->set("inquiry/weapon", (: call_other, this_object(), "ask_for_testing" :));
        ao->set("inquiry/bingqi", (: call_other, this_object(), "ask_for_testing" :));
        ao->set("inquiry/����", (: call_other, this_object(), "ask_for_testing" :));
        ao->set_temp("wire-puller", this_object());
    }
    set("ao", ao);
    call_out("destruct_me", 1200);
}

int ask_for_testing()
{
    object ao = query("ao");
    object who = this_player();
    object fighter;
    string weapon_name, weapon_id, weapon_unit, trying, respect;

    if (!ao || who != query("owner")) return 0;

    if (who->query("dntg/donghai") == "begin")
        { weapon_name="�󿳵�"; weapon_id="da kan dao"; weapon_unit="��"; trying="try_dao"; }
    else if (who->query("dntg/donghai") == "da kan dao")
        { weapon_name="�Źɲ�"; weapon_id="jiu gu cha"; weapon_unit="֧"; trying="try_cha"; }
    else if (who->query("dntg/donghai") == "jiu gu cha")
        { weapon_name="÷����"; weapon_id="mei hua chui"; weapon_unit="��"; trying="try_chui"; }
    else if (who->query("dntg/donghai") == "mei hua chui")
        { weapon_name="�����"; weapon_id="hua gan ji"; weapon_unit="��"; trying="try_ji"; }
    else if (who->query("dntg/donghai") == "hua gan ji") {
        ao->command_function("consider");
        message_vision("�Ӻ�����һ�����ţ���$N����С��˵�˼��仰��\n", ao);
        call_out("sendto_maze", 3);
        return 1;
    } else if (who->query("dntg/donghai")=="done")
        return 0;
    else {
        ao->command_function("nod");
        message_vision("$N�������˵����Ҫ���������������е��ǣ�ȥ����ŪЩ�ɡ���\n", ao);
        message_vision("$N���˶٣���˵�����������ı�������������Щ��������Ҳʹ���ˡ���\n", ao);
        ao->command_function("wave");
        return 1;
    }

    fighter = present("ye cha", environment());
    if (present(weapon_id, this_player()) && fighter)
        message_vision("$N������������"+weapon_unit+weapon_name+"��$n�����ɣ�\n", ao, fighter);
    else if (present(weapon_id, environment()) && fighter)
        message_vision("$N������������"+weapon_unit+weapon_name+"��$n�����ɣ�\n", ao, fighter);
    else if (present(weapon_id, this_player()) || present(weapon_id, environment())) {
        fighter = new(__DIR__"fighter");
        fighter->move(environment());
        message_vision("$N˵���������Ҹ���������������\n", ao);
        message_vision("$Nһ���֣�һ��$n���˹�����\n", ao, fighter);
    } else if (fighter)
        message_vision("$N�����ף���֪��"+weapon_unit+weapon_name+"��˭��ȥ�ˣ�\n", ao);
    else {
        respect = RANK_D->query_respect(who);
        message_vision("$N��æ����˵����"+respect+"�Ժ�������룿\n", ao,who);
        message_vision("������������"+weapon_unit+weapon_name+"���պ�����ʹ��"+respect+"����������������"+respect+"�ðɣ�\n", who);
        who->set_temp("dntg/donghai", trying);
        call_out("fight_quest", 2, trying);
    }
    return 1;
}

void fight_quest(string trying)
{
    object ao = query("ao");
    object who = query("owner");
    object fighter, weapon;
    string weapon_name, weapon_unit;

    if (trying == "try_dao")
        { weapon_name="�󿳵�"; weapon = new(__DIR__"dakandao"); weapon_unit="��"; }
    else if (trying == "try_cha")
        { weapon_name="�Źɲ�"; weapon = new(__DIR__"jiugucha"); weapon_unit="֧"; }
    else if (trying == "try_chui")
        { weapon_name="÷����"; weapon = new(__DIR__"meihuachui"); weapon_unit="��"; }
    else if (trying == "try_ji")
        { weapon_name="�����"; weapon = new(__DIR__"huaganji"); weapon_unit="��"; }
    else
        return;

    fighter = new(__DIR__"fighter");
    fighter->move(environment());
    weapon->move(environment());
    message_vision("$Nһ���֣�һ��$ņ��һ"+weapon_unit+weapon_name+"��\n", ao, fighter);
    message_vision("$N˵������Ҫ��Ҫ���ҵ���������������\n", ao);
}

void sendto_maze()
{
    object ao = query("ao");
    object who = query("owner");
    if (!ao || !who) {
        call_out("destruct_me", 1);
        return;
    }

    message_vision("$N˵����"+RANK_D->query_respect(who)+"�书�������ɵ�����ĺ�������һ�Զ�����������\n",ao,who);
    call_out("send_maze", 3);
}

void send_maze()
{
    object ao = query("ao");
    object who = query("owner");

    if (!ao || !who) {
        call_out("destruct_me", 1);
        return;
    }

    message_vision("˵�ţ�$N��$n�͵���һ���ط���\n", ao, who);
    who->move(__DIR__"maze/hdmg");
    ao->move(__DIR__"maze/hdmg");
    message_vision("$Nһ���ֵ���"+RANK_D->query_respect(who)+"��ǰ�߼��ɿ�����������ˡ�Ϸ򲻷����ˡ�\n", ao, who);
    message_vision("˵�գ�$Nת��ع��ˡ�\n", ao);
    ao->move(environment());
    call_out("make_shentie", 1);
}

void make_shentie()
{
    object shentie, room;

    room = find_object(__DIR__"maze/mazeend");
    if (!room) load_object(__DIR__"maze/mazeend");
    if (room = find_object(__DIR__"maze/mazeend")) {
        if (!(shentie = present("shen tie", room))) {
            shentie = new(__DIR__"shentie");
            shentie->move(room);
        }
    }
    call_out("destruct_me", 1);
}

void remove()
{
    object ao = query("ao");
    if (ao && ao->query_temp("wire-puller") == this_object()) {
        ao->delete("inquiry/weapon");
        ao->delete("inquiry/bingqi");
        ao->delete("inquiry/����");
    }
}

void destruct_me()
{
    destruct(this_object());
}
