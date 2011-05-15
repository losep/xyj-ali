
inherit ROOM;

void create()
{
    set("short", "����Ҷ��");
    set("long", @LONG
���ܻ���������֦Ҷ��ï��ȴ�ѿ������ء�
LONG);

    set("exits", ([ /* sizeof() == 2 */
        //"up" : __DIR__"tree2",
        //"down" : __DIR__"ontop2",
    ]));

    set("objects", ([
        "/d/obj/flower/guihua.c" : 2,
    ]));

    setup();
}

void init()
{
    object ob = this_player();
    add_action("do_climb", "climb");
    add_action("do_kan", "kan");
    
    if ((ob->query("family/family_name") == "�¹�"
        &&  ob->query("family/master_id") == "yue nu")
    ||  (ob->query_skill("dodge", 1) <= 120
        && ob->query_skill("moondance", 1) <= 120)) {
        remove_call_out("rabbit_welcome");
        call_out("rabbit_welcome", 3, ob);
    }
}

void rabbit_welcome(object who)
{
    object ob;

    if (!who || environment(who) != this_object()) return;

    if (!(ob = present("yu tu", this_object()))) {
        ob = new(__DIR__"npc/rabbit");
        ob->move(this_object());
        tell_room(this_object(), "һֻС���ã��ı����������˹�����\n");
    }
    ob->welcome(who);
    ob->start_call_out((: call_other, ob, "disappearing" :), 120);
}

int do_climb(string arg)
{
    object me = this_player();

    if (!arg || (arg != "up" && arg != "down"))
        return notify_fail("��Ҫ���ĸ���������\n");
    if (arg == "down") {
        message_vision("$N˳�����ɳ�������ȥ��\n", me);
        me->move(__DIR__"ontop2.c");
        message_vision("$N�ӹ����ϳ�����������\n", me);
        return 1;
    }

    if (me->query("kee") < (int)(me->query("max_kee") / 3)) {
        me->receive_damage("kee", (int)me->query("max_kee")*20/100);
        return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
    }
    
    if ((int)me->query_skill("dodge", 1) < 60 && (int)me->query_skill("moondance", 1) < 80) {
        message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
        tell_object(me, "��о��ƺ����Դ�������һЩ�����Ṧ��������ţ���ϧ��Ϊ̫�����ţ����޷�ץס��ת˲���ŵ�����\n");
        me->receive_damage("sen", (int)me->query("max_sen")*10/100);
    } else if ((int)me->query_skill("dodge", 1) < 100 && (int)me->query_skill("moondance", 1) < 80) {
        message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
        me->improve_skill("dodge", 40 - me->query("str"));
        tell_object(me, "�������һЩ�����Ṧ��������š�\n");
    } else {
        message_vision("$N��������һ�����������������в����ˡ�\n", me);
        me->move(__DIR__"tree2.c");
    }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
    return 1;
}

int do_kan(string arg)
{
    if (!arg || !(arg != "tree" && arg != "����"))
        return notify_fail("��Ҫ��ʲô��\n");
    return notify_fail("�����ھ������ϰ��������������Լ�����ȥ��");
}
