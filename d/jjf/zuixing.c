// created 6-8-97 pickle
// Room: /d/jjf/zuixing.c

inherit ROOM;

void create()
{
    set("short", "����¥");
    set("long", @LONG

���ﾹ��̫�ӽ��ɺ�����Ԫ�������һ���ݻ��Ĳ�¥������¥����û
�뵽���ɾ�ȻҲ������Ų�Ƶ��������֪������������������¥��
����ô���¡�����������ȳ�������¥��Ҫ���壬����Ҳû�а��գ�
��������ʱʳ��Ǯ�Ƶĺ�����Ҳû�����ˡ�
LONG);

    set("no_fight", 1);
    set("light_up", 1);
    set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/qinbing-jian" : 1,
        __DIR__"npc/qinbing-qi" : 1,
]));
    set("exits", ([ /* sizeof() == 2 */
        "northwest" : __DIR__"center",
        "up" : __DIR__"zuixing2",
]));

    setup();
}

int valid_leave(object me, string dir)
{
    if (me->query("env/invisibility")) return ::valid_leave(me, dir);
    if (dir == "up" && objectp(present("qin bing", environment(me)))) {
        if (!me->id("qin bing"))
            return notify_fail("�ױ��ȵ��������˵Ȳ����Ҵ���\n");
    }
    return ::valid_leave(me, dir);
}

void init()
{
    add_action("do_kan", "kan3");
    add_action("do_kan", "��");
    add_action("do_kan", "chop");
}

int do_kan(string arg)
{
    object me = this_player(), ob;
    
    if (!arg || (arg != "����" && arg != "zhuzi" && arg!="pillar"))
        return notify_fail("��Ҫ���������֣�\n");
    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe")
        return notify_fail("û˳�ֵļһ���ô��ö���\n");
    if (objectp(present("qin bing", environment(me))))
        return notify_fail("������Ҫ���¥���ȵð��ױ������ˣ�\n");
    message_vision("$N�����˾���һ�������¥�����ӣ�\n", me);
    message_vision("ֻ����¡һ�����죬֧�ŷ��ӵ����Ӵ����۶ϣ���������¥����������\n", me);
    message_vision("һ���޴�ķ��������������������$N��������ϣ���$N�ҵ����۷��ף��������˹�ȥ��\n", me);
    me->unconcious();
    message_vision("ֻ����������һ���춯�����ѵ�ľͷ�����Ϸ�ȥ��������װ����һ����¥���·�ղŵĳ���ֻ�ǻ�Ӱ��\n", me);
    return 1;
}
