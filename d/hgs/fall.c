inherit ROOM;

void create()
{
    set("short", "�ٲ�ǰ");
    set("long", @LONG

ֻ���ǹɽ�ˮ����������ƹ���ӿ����˳����ɽ��ֱ��Դ��֮����
����һ���ٲ���Ȫ�������ǣ�

����һ�ɰ׺���ǧѰѩ�˷ɣ����紵���ϣ������ջ�����
�������������֣��������΢���������ٲ������ƹ���ᡡ�
LONG);

    set("exits", ([
        "west"   : __DIR__"shanya",
    ]));
    set("outdoors", __DIR__);

    setup();
}

void init()
{
    object who = this_player();

    add_action("do_jump", "jump");
    add_action("do_wave", "wave");

    if (objectp(who) && interactive(who))
        call_out("appearing", 1, who);
}

void appearing(object who)
{
    object where = this_object();
    object houzi;

    if (!who || environment(who) != where)
        return;

    if (!present("hou zi 4", where)) {
        houzi = new(__DIR__"npc/hou");
        houzi->move(where);
        message_vision("�����дڳ�һֻ$N��\n", houzi);
    }
}

int do_jump(string arg)
{
    object me;

    me = this_player();
    if (!arg || (arg != "pubu" && arg != "fall"))
        return  notify_fail("�����Ķ�����\n");

    else if (random(30) + me->query("kar") < 30) {
        message_vision("$N����һ�ݣ���С��ײ����һ��ʯͷ�ϡ�\n", me);
        me->unconcious();
    } else {
        message_vision("$N���һ��������ȥ���ƣ���˵�շ���Ծ���ٲ���\n", me);
        me->move(__DIR__"fall1");
    }

    return 1;
}

int do_wave(string arg)
{
    object me = this_player();
    object hb;

    if (!arg || (arg != "flag")) return notify_fail("�������ʲô��\n");
    else if (!(hb = present(arg, me)))
       return notify_fail("������û���ⶫ����\n");
    else {
        if (me->query("dntg/huaguo") == "done")
            return notify_fail("��������е�"+hb->query("name")+"�������˵����ڴ˳����Ŀ���ʱ�⡣\n");
        message_vision("$N�����������ӣ����һ���������컯�����컯������ûˮ��ԭ����һ�������š����Ǳ���һ���������ļҵ����ֵ��ǿ�ȥѽ����\n", me);
        call_out("jumping", 2, me);
        me->set("dntg/huaguo", "allow");
        destruct(hb);
    }

    return 1;
}

void jumping(object who)
{
    object where = this_object();
    object who1 = present("hou zi 1", where);
    object who2 = present("hou zi 2", where);
    object who3 = present("hou zi 3", where);
    object who4 = present("hou zi 4", where);
    if (who1) destruct(who1);
    if (who2) destruct(who2);
    if (who3) destruct(who3);
    if (who4) destruct(who4);
    message_vision("�������������ȿֺ�������ٲ���\n", who);
}
