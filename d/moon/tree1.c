
inherit ROOM;

void create()
{
    set("short", "桂树叶间");
    set("long", @LONG
四周花香弥漫，枝叶繁茂，却已看不见地。
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
    
    if ((ob->query("family/family_name") == "月宫"
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
        tell_room(this_object(), "一只小白兔，蹦蹦跳跳的跑了过来。\n");
    }
    ob->welcome(who);
    ob->start_call_out((: call_other, ob, "disappearing" :), 120);
}

int do_climb(string arg)
{
    object me = this_player();

    if (!arg || (arg != "up" && arg != "down"))
        return notify_fail("你要往哪个方向爬？\n");
    if (arg == "down") {
        message_vision("$N顺着树干出溜了下去。\n", me);
        me->move(__DIR__"ontop2.c");
        message_vision("$N从桂树上出溜了下来。\n", me);
        return 1;
    }

    if (me->query("kee") < (int)(me->query("max_kee") / 3)) {
        me->receive_damage("kee", (int)me->query("max_kee")*20/100);
        return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
    }
    
    if ((int)me->query_skill("dodge", 1) < 60 && (int)me->query_skill("moondance", 1) < 80) {
        message_vision("$N小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
        tell_object(me, "你感觉似乎可以从中领悟一些基本轻功方面的窍门，可惜因为太过紧张，你无法抓住那转瞬即逝的领悟。\n");
        me->receive_damage("sen", (int)me->query("max_sen")*10/100);
    } else if ((int)me->query_skill("dodge", 1) < 100 && (int)me->query_skill("moondance", 1) < 80) {
        message_vision("$N小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
        me->improve_skill("dodge", 40 - me->query("str"));
        tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
    } else {
        message_vision("$N纵身往上一跳，接着爬入树丛中不见了。\n", me);
        me->move(__DIR__"tree2.c");
    }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
    return 1;
}

int do_kan(string arg)
{
    if (!arg || !(arg != "tree" && arg != "桂树"))
        return notify_fail("你要砍什么？\n");
    return notify_fail("你现在就在树上啊！砍树？不怕自己掉下去？");
}
