
inherit ROOM;

void create()
{
    set("short", "�ߴ���ʤ��");
    set("long", @LONG
���ܻ���������֦Ҷ��ï������Ѿ��м������ˡ���û�뵽�������
��Ȼ����ô�ߣ��ѵ���������ǵ���֮�ݣ���ɫ���䣬�㲻�����ɣ�
��һֱ������ȥ���ǲ�����ֱ�������㺮�¹���
LONG);

    set("exits", ([ /* sizeof() == 2 */
        //"up" : __DIR__"ontop",
        //"down" : __DIR__"tree1",
    ]));

    set("objects", ([
        "/d/obj/flower/guihua.c" : 2,
    ]));

    setup();
}

void init()
{
    add_action("do_climb", "climb");
    add_action("do_kan", "kan");
}

int do_climb(string arg)
{
    object me = this_player();

    if (!arg || (arg != "up" && arg != "down"))
        return notify_fail("��Ҫ���ĸ���������\n");
    if (arg == "down") {
        message_vision("$N˳�����ɳ�������ȥ��\n", me);
        me->move(__DIR__"tree1.c");
        message_vision("$N�ӹ����ϳ�����������\n", me);
        return 1;
    }

    if (me->query("kee") < (int)(me->query("max_kee") / 3)) {
        me->receive_damage("kee", (int)me->query("max_kee")*20/100);
        return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
    }
    
    if ((int)me->query_skill("dodge", 1) < 100 && (int)me->query_skill("moondance", 1) < 100) {
        message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
        tell_object(me, "��о��ƺ����Դ�������һЩ�����Ṧ��������ţ���ϧ��Ϊ̫�����ţ����޷�ץס��ת˲���ŵ�����\n");
        me->receive_damage("sen", (int)me->query("max_sen")*10/100);
    } else if ((int)me->query_skill("dodge", 1) < 120 && (int)me->query_skill("moondance", 1) < 120) {
        message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
        me->improve_skill("dodge", 40 - me->query("str"));
        tell_object(me, "�������һЩ�����Ṧ��������š�\n");
    } else {
        message_vision("$N��������һ�����������������в����ˡ�\n", me);
        me->move(__DIR__"ontop.c");
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
