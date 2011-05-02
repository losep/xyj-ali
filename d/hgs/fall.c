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
    add_action("do_jump", "jump");

    call_out("appearing", 1);
}

void appearing()
{
    object where = this_object();
    object houzi;

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
    if (!arg || (arg != "fall" && arg != "pubu"))
        return notify_fail("�����Ķ�����\n");

    if (random(30) + me->query("kar") < 30) {
        message_vision("$N����һ�ݣ���С��ײ����һ��ʯͷ�ϡ�\n", me);
        me->unconcious();
    } else {
        message_vision("$N���һ��������ȥ���ƣ���˵�շ���Ծ���ٲ���\n", me);
        me->move(__DIR__"ironbridge");
    }

    return 1;
}
