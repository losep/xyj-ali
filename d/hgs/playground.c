#include <ansi.h>

inherit ROOM;

string look_flag();

void create()
{
    set("short", "����ɽ�̾���");
    set("long", @LONG

һƬ�����Ĳݵأ��������ǵ������ǵĽ̾�����ֻ������һ�������
ͨ��Գָ����һ���У�һ�����߹����ĺ��ӱ����ݵصı�������һ��
ʮ�ɶ�ߵ���ˣ��������һ�����(flag)���ڷ�����Ʈ�衣
LONG
    );

    set("exits", ([
        "east"   : __DIR__"shanya",
    ]));

    set("item_desc",([
        "flag": (: look_flag :)
    ]));

    set("objects", ([
        __DIR__"npc/beng-jiangjun" : 1,
    ]));

    set("no_clean_up", 1);
    set("outdoors", __DIR__);
    setup();
}

void init()
{
    add_action("do_start", ({"raise","gua","sheng","hang"}));
}

string look_flag()
{
    string str = "һ�����߼����Ĵ���죬ӭ��Ʈչ��\n";
    if (query("host")) 
        str += ("��������"+HIY+" �����ʥ "+query("host")->query("name")+NOR+" �������֡�\n\n");
    else
        str += ("��̫�󣬿������������д��ʲô��\n\n");
    return str;
}

int do_start(string arg)
{
    object me = this_player();
    object host = query("host");
    object lijing;

    if (!arg || arg!="flag") return notify_fail("��Ҫ��ʲô��\n");
    if (host)
        return notify_fail(host->query("name")+"���ڴ�ռɽΪ���ˡ�\n");   
    if (me->query("combat_exp") < 100000)
        return notify_fail("���̫���ˣ��㹦��̫��Ҳ���ȥ��\n");
    if (me->query("dntg/lijing") == "done")
        return notify_fail("���ϴ��Ѿ����������ʥ��ˣ��������������ɡ�\n");

    set("host", me);
    message_vision(HIG"$N���������ʥ���Ĵ��������ˡ�\n"NOR, me);
    message_vision(HIG"$N�������������ӽ�����"
        + RANK_D->query_self_rude(me) + "���������ʥ��������϶�ƽ��ƽ������\n"NOR, me);

    lijing = new("/d/dntg/lijing/lijing");
    lijing->move(this_object());
    lijing->set("target", me);
    lijing->start();

    return 1;
}
