// ALi by NewX

// Room: /d/city/zuixing.c
 
inherit ROOM;
 
void create ()
{
    set ("short", "����¥");
    set ("long", @LONG

̫����ɺ�������Ԫ���Ը�����ּ�������ʮ�ֲ�������Ϊ���Ƕ�
������ƫ�������Ƕ��������֮�ʣ��������������Ե�λ��������
һ�����仪����ΰ�Ĳ�¥����������¥����Ϊ����������ǰ���ۿ���
����������ϧ����ʳ��Ǯ�ƣ���ʱȴҲ��ʢ����ǰ�����ǣ���������
֮�������ķ��ˣ�ֻʣ����տյĲ�¥����˵�ŵ�����λ���˵�
���ơ�
LONG);

    set("no_fight", 1);
    set("light_up", 1);
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"xuanwu-n1",
        "up" : __DIR__"zuixing2",
    ]));
    set("objects", ([
        "/d/obj/misc/chairs" : 4,
        "/d/obj/misc/tables" : 1,
    ]));

    setup();
}

void init()
{
    add_action("do_kan", "kan3");
    add_action("do_kan", "��");
    add_action("do_kan", "chop");
}

int do_kan(string arg)
{
    object me=this_player(), here=this_object(), ob, zhuzi;
    int kar=me->query_kar();
    
    if ((!arg || arg != "����") && (arg != "zhuzi" && arg!="pillar"))
        return notify_fail("��Ҫ���������֣�\n");
    if (!(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe")
        return notify_fail("û˳�ֵļһ���ô��ö���\n");
    //if (objectp(present("qin bing", environment(me))))
    //    return notify_fail("������Ҫ���¥���ȵð��ױ������ˣ�\n");
    if (!me->query_temp("mark/zuixing2_broken"))
        return notify_fail("��û�Ҷ�¥�أ�������һ¥�����⣿\n");
    here->add("pending/breakdown", 1);
    if (here->query("broken"))
        return notify_fail("���Ӷ����ˣ�����ʲô����Ҫ���Ŀ��ȥ�ɣ�\n");
    message_vision("$N�����˾���һ�������¥�����ӣ�ֻ����ƬľƬ��ɢ�ɿ���\n", me);
    if (here->query("pending/breakdown") >= (int)(40 - kar)/5) {
        message_vision("ֻ��һ�����죬֧�ŷ��ӵ����Ӵ����۶ϣ���������¥����������\n", me);
        message_vision("$N��Ȼ��û�ͷ����������Ȼû�����ˣ������������ǸϽ���ȥ�ɣ�\n", me);
        here->set("long", @LONG

����������һ���������ɵĲ�¥������֪Ϊ�α��˲���ˣ�ֻʣһƬ
���档������ľͷ���浽�����ǾƱ�������Ƭ����ر����ϵ�����
�����űߡ�
LONG);
        me->delete_temp("mark/zuixing2_broken");
        here->set("broken", 1);
        here->set("outdoors", 1);
        zhuzi=new(__DIR__"obj/zhuzi");
        zhuzi->move(here);
        here->set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"qinglong-e4",
        ]));
    }
    me->receive_damage("kee", (int)me->query("max_kee")/4);
    return 1;
}
