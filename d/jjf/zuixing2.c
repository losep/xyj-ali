// Room: /d/jjf/zuixing2
inherit ROOM;
 
void create()
{
    set("short", "����¥��¥");
    set("long", @LONG

�ϵ�¥�ݣ�ӭ����һ����ʯ���磬�ϻ��϶��µĹ��¡�ת�����磬
ֻ����������һ�����Ͽ������֣��Ա���Ů���������衣һ�ߣ�����
����Сͯ�����ź��š��е����ϲˣ��е��ڴ��ȡ�
LONG);
    set("objects", ([ /* sizeof() == 4 */
        __DIR__"npc/liyuanji.c": 1,
        __DIR__"npc/lijiancheng.c": 1,
]));
    set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"zuixing",
]));
    set("light_up", 1);

    setup();
}

void init()
{
    add_action("do_kan", "��");
    add_action("do_kan", "chop");
    add_action("do_kan", "kan3"); 
}

int do_kan(string arg)
{
    object me = this_player(), ob;
    
    if (!arg || (arg != "����" && arg != "zhuzi" && arg!="pillar"))
        return notify_fail("��Ҫ���������֣�\n");
    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe")
        return notify_fail("û��˳�ֵļһ���ô��ö���\n");
    if (objectp(present("li jiancheng", environment(me)))
    ||  objectp(present("li yuanji", environment(me))))
        return notify_fail("��������ڴˣ����������˵�������\n");

    message_vision("$N�����˾���һ�������¥�����ӣ�\n", me);
    message_vision("ֻ����¡һ�����죬֧�ŷ��ӵ����Ӵ����۶ϣ���������¥����������\n", me);
    message_vision("һ���޴�ķ��������������������$N��������ϣ���$N�ҵ����۷��ף��������˹�ȥ��\n", me);
    me->unconcious();
    message_vision("ֻ����������һ���춯�����ѵ�ľͷ�����Ϸ�ȥ��������װ����һ����¥���·�ղŵĳ���ֻ�ǻ�Ӱ��\n", me);
    return 1;
}
