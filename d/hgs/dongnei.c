inherit ROOM;

void create()
{
    set("short", "ˮ������");
    set("long", @LONG
������ǻ���ɽˮ���������ã����ܹ���ư������
��ȫ������һ�Ż�Ƥ���ӣ����ǹ�ˮ��������Ϣ�ġ�
LONG );

    set("exits", ([
        "west"   : __DIR__"shifang",
    ]));

    set("objects", ([
        "/d/dntg/huaguo/mowang" : 1,
    ]));

    setup();
}

int valid_leave(object me, string dir)
{
    object mowang;
    if (dir == "west"
    &&  objectp(mowang = present("hunshi mowang", environment(me)))
    &&  living(mowang))
        return notify_fail("����ħ����������Ц���������ߣ�û��ô���װɣ���\n");
    return ::valid_leave(me,dir);
}

