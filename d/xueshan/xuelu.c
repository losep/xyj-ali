// ALi by NewX
inherit ROOM;

void create()
{
    set("short", "ѩ·");
    set("long", @LONG

·�ֽ�����������ˡ�����Ļ�ѩ�ܺ񣬶�����Ϊ�ߵ��˺ܶ࣬��ѩ
������ʵ�ˣ������ȵ�����ﻬ�ģ��Բ�С�ľͻ�ˤ������ʹ�ǳ���
�����������ѩɽ���ӣ�һ��С��Ҳ��ˤ������·�ϣ��������Կ���
ˤ���ͽֵ�ѩɽ���ӣ���������žߴžߴ��ˤ������࣬���Լ�����
�ú��ۡ�
LONG);

    set("exits", ([ //sizeof() == 4
        "north" : __DIR__"xuejie-1",
        "south" : __DIR__"wuchang-n",
    ]));

    set("objects", ([
        __DIR__"obj/ice" : 1,
    ]));

    set("outdoors", "xueshan");

    setup();
}

int valid_leave(object me, string dir)
{
    if (random(me->query_kar()) < 15 && (int)me->query_skill("dodge") < 100) {
        message_vision("$N��һ��������Ȼ����һ����ˤ�˸�����࣡���ۣ�\n", me);
        if (me->query("kee") < 50)
            me->unconcious();
        else
            me->receive_damage("kee", 50);
        return notify_fail("���۵�ֱ���졣\n");
    }
    return ::valid_leave(me, dir);
}
