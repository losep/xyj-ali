inherit ROOM;

void init();
void reset_path(object);
int check_out(object);

void setup()
{
    mixed points;

    set("short", "ѩ������");
    set("long", @LONG

�����Х����ѩãã��������ȥ�������Ӳ�����ѩ�塣���֮��
���Ѻ�������������ѩ����ѩ���������㾪�治�ѵ���ǰ���Ȼ
����������ӡ����Ȼ���쵭�ÿ��������ˣ��Ͼ����˵Ľ�ӡ����
���ɵ�һ���ϲ������һ�е�׷����ȥ��
LONG);

    set("outdoors", "xueshan");

    if (arrayp(points = query("points"))) {
        set("exits/north", __DIR__"snowmaze" + (string )points[0]);
        set("exits/south", __DIR__"snowmaze" +(string )points[1]);
        set("exits/west", __DIR__"snowmaze" +(string )points[2]);
        set("exits/east", __DIR__"snowmaze" +(string )points[3]);
    }

    ::setup();
}

void init()
{
    object me = this_player();
    string xmaze = this_object()->query("xmaze");
    mixed exit = this_object()->query("maze_exit");

    if (me->query_temp(xmaze) == 0)
        me->set_temp(xmaze, 1);
    else if (me->query_temp(xmaze) == 1)
        reset_path(me);

    if (check_out(me)) {
        if (stringp(exit)) me->move(exit);
        else if (arrayp(exit)) me->move(exit[random(sizeof(exit))]);
        else error("undef maze_exit : " + (string)exit);
    }
}

void reset_path(object me)
{
    if (me->query_temp("xmaze1")) me->delete_temp("xmaze1");
    if (me->query_temp("xmaze2")) me->delete_temp("xmaze2");
    if (me->query_temp("xmaze3")) me->delete_temp("xmaze3");
    if (me->query_temp("xmaze4")) me->delete_temp("xmaze4");
    if (me->query_temp("xmaze5")) me->delete_temp("xmaze5");
    if (me->query_temp("xmaze6")) me->delete_temp("xmaze6");
    if (me->query_temp("xmaze7")) me->delete_temp("xmaze7");
    if (me->query_temp("xmaze8")) me->delete_temp("xmaze8");
    if (me->query_temp("xmaze9")) me->delete_temp("xmaze9");
    return;
}

int check_out(object me)
{
    if (me->query_temp("xmaze1") != 1) return 0;
    if (me->query_temp("xmaze2") != 1) return 0;
    if (me->query_temp("xmaze3") != 1) return 0;
    if (me->query_temp("xmaze4") != 1) return 0;
    if (me->query_temp("xmaze5") != 1) return 0;
    if (me->query_temp("xmaze6") != 1) return 0;
    if (me->query_temp("xmaze7") != 1) return 0;
    if (me->query_temp("xmaze8") != 1) return 0;
    if (me->query_temp("xmaze9") != 1) return 0;
    if (me->query_temp("xmaze1")) me->delete_temp("xmaze1");
    if (me->query_temp("xmaze2")) me->delete_temp("xmaze2");
    if (me->query_temp("xmaze3")) me->delete_temp("xmaze3");
    if (me->query_temp("xmaze4")) me->delete_temp("xmaze4");
    if (me->query_temp("xmaze5")) me->delete_temp("xmaze5");
    if (me->query_temp("xmaze6")) me->delete_temp("xmaze6");
    if (me->query_temp("xmaze7")) me->delete_temp("xmaze7");
    if (me->query_temp("xmaze8")) me->delete_temp("xmaze8");
    if (me->query_temp("xmaze9")) me->delete_temp("xmaze9");
    return 1;
}
