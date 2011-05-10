
inherit ROOM;

void create()
{
    set("short", "������");
#if 1
    set("long", @LONG

�����ǰ������ı����⣬һ��ùζ�˱Ƕ���������ʮ����û���˽�
�����˰ɡ�ż�����������ҵ�һ��������Ҳ���Ѿ��⼣�߰ߡ�
LONG);
#else
    set("long", @LONG

�����ǰ������ı����⣬������ֱ���(bingqi)������ǹ��
����ꪡ������ᡢë�������ޡ��١��Ρ�ﵡ������󡢲桢
ì�������㱸����������Ķѷ��ţ������������ʿ����
�ﱣ���š�
LONG );
    set("item_desc",([
        "bingqi":"���ָ����ı��������������߲����㣬����(kun)һ�²ź��á�\n"
    ]));
#endif

    set("exits", ([
        "north"   : __DIR__"drill",
    ]));

    set("no_magic", 1);

    setup();
}


void init()
{
    add_action("do_kun", "kun");
    add_action("do_ji", "ji");
}


int do_kun(string arg)
{
    object me = this_player();
    object pianj, bingq;

    if (!arg || arg != "bingqi")
        return notify_fail("��Ҫ��ʲô��\n");

    if (objectp(pianj = present("pian jiang", environment(me))) && living(pianj))
        return notify_fail("ƫ����ȵ����Ҷ��ҹ���������Ķ��������˲��ɣ�\n",me);

    if (me->is_busy())
        return notify_fail ("������æ���ء�\n");

    if (me->query("kee") < 50)
        me->unconcious();
    else {
        me->receive_damage("kee", 50);
        message_vision("$N����ææ��ʰ��һ�ѱ�����������������������������һЩ��\n", me);
        bingq = new ("/d/dntg/huaguo/bingqi");
        bingq->move(me);
        me->start_busy(5, 5);
    }
    return 1;
}

int do_ji(string arg)
{
    object me = this_player();
    object hb;
    
    if (!arg || arg != "feng ling fu")
        return  notify_fail("�����ʲô��\n");
    if (!objectp(hb = present(arg, me)) || hb->query("unit") != "��")
        return notify_fail("������û���ⶫ����\n");

    if (me->query("mana") + random(500) < 1000) {
        message_vision("$N�ó�����������һ��������������\n", me);
        message_vision("��ʲôҲû�з�������\n", me);
    } else {
        message_vision("$N�ó�����������һ��������������\n", me);
        call_out("away", 2, me);
        call_out("go_back", 60, me);
    }
    destruct(hb);
    return 1;
}

void away(object who)
{
    object where = this_object();
    object who1 = present("pian jiang 1", where);
    object who2 = present("pian jiang 2", where);

    if (!who1) return;

    destruct(who1);
    destruct(who2);
    tell_object(where, "ֻ��һ�ɿ��ι����������Ƕ��������ۣ�����ƫ���޺������˳�ȥ��\n");
}

void go_back(object who)
{
    object who1, who2;
    object where = this_object();

    // mon 3/24/99
    // prevent getting too many pian jiang by go_back.
    // at most 4.
    if (present("pian jiang 4", where)) return;

    who1 = new(__DIR__"npc/pianjiang");
    who2 = new(__DIR__"npc/pianjiang");
    who1->move(where);
    who2->move(where);
    tell_object(where, "ƫ���������۾��߻ر����⡣\n");
}
