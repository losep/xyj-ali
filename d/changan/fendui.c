
// Room: /d/changan/fendui.c
inherit ROOM;

void create()
{
    set("short", "�ķض�");
    set("long", @LONG

�����ǳ������ϵ�һƬ�ĵأ���Χ��������ض��˺ü�ʮ����ͷ��
��Щ��ǰ����Щ���룬��ֽ�ĺۼ����Ĵ����������������߶���ż
���м�ֻѰʳ��Ұ���ܹ���
LONG);
    set("mai_corpse_able", 1);
    set("outdoors", __DIR__"");
    set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"broadway1",
    ]));
    setup();
}

void init()
{
    add_action("do_dig", "dig");
}

int do_dig(string arg)
{
    object me;
    me = this_player();
    if ((arg!="ground") && (arg!="��"))
        return notify_fail("������ʲô��\n");
    message_vision("$N�ڵ����ڿ�һ���������˽�ȥ��\n", me);
    me->move("/d/gumu/door");
    return 1;
}
