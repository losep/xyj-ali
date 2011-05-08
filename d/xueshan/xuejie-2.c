//restroom.c

inherit ROOM;

void create ()
{
    set ("short", "ѩ��");
    set ("long", @LONG

����һ�����ǻ�ѩ�Ľ��ݣ������Ѿ������˾�ͷ����ǰֻ��һ��
��ѩ��ʯ��(shibi)��
LONG);

    set("exits", ([ //sizeof() == 4
        "south" : __DIR__"xuejie-1",
    ]));

    set("outdoors", "xueshan");

    setup();

}

void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    object me = this_player();

    if (!arg || arg != "shibi") return notify_fail("��Ҫ��������\n");
    if (me->is_busy()) return notify_fail("��������æ���ء�\n");

    message_vision("$N�ֿ���ʯ�죬��ʯ������ȥ��\n", me);
    me->start_busy(2);
    call_out("climb_to", 2, me);
    return 1;
}

void climb_to(object me)
{
    if (me->query("kee") < 50) {
        message_vision("˭֪��$Nһ�ŵſգ���ʯ���ϴ�ͷ���������������Թ����۵�һ������ѩ���ϡ�\n", me);
        message_vision("�Һ���ѩ�أ�����϶�û���ˡ�\n", me);
        me->unconcious();
    } else if ((int)me->query_skill("dodge", 1) < 20) {
        message_vision("˭֪��$Nһ�ŵſգ���ʯ���ϴ�ͷ�����������������˸�ƨ�����ƽɳ����ʽ��\n", me);
        message_vision("��Ȼ��ѩ�أ�Ҳ��$Pˤ�ò��ᡣ\n", me);
        me->receive_damage("kee", 20);
    } else {
        me->receive_damage("kee", 50);
        tell_room(environment(me), "ת��֮�䣬"+me->name()+"����Ӱ�㿴�����ˡ�\n", me);
        me->move(__DIR__"no4-enter");
        tell_room(environment(me), "ֻ��"+me->name()+"����Ծ��������\n", me);
    }
}
