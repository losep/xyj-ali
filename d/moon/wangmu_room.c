// ALi by NewX

#include <ansi.h>
inherit ROOM;

void create()
{
    set ("short", "������");
    set ("long", @LONG

�˼䱾����ĸ�Ӵ�����ʰ����𴦲�ͬ�����ֲ���������ġ�������ǵ�
������ľ�壬�����ư��𡹣����꺮���ѡ�����ɽˮ�������ë��
�ܣ��򼯽����򲩹ţ��������٣����ֻ����������ֵ��Σ��������Ƕ
���ġ�һ��һ�����������鴦�����趦�������ñ��⴦���򹩻���ƿ��
���辰��������ʽ����������Բ�ط����������Ҷ����������ڣ�����
���Ž��أ���͸���硣
LONG);

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/xiwangmudummy.c" : 1,
        ]));

    set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"huilang1.c",
                ]));

    setup();
}

void init()
{
    add_action("do_search", "search");
}

int do_search(string arg)
{
    object me = this_player();

    if (!arg || arg != "yunwu")
        return notify_fail("������ʲô��");

    message_vision("$Nſ�ڵ���������һͨ����Ȼ�ڵ��Ϸ�����һ��ͭǮ��\n", me);
    message_vision("���Ե�$N����ϲ�ص����ͭǮ��������˭֪ͭǮ�ո���أ������ϱ��Գ���һ�����ڣ���$N����Ӱ��û�ˡ�\n\n\n", me);
    tell_object(me, HIY "�������һ��������������㲻ͣ����׹���ŵð���������ƫƫͣ������������\n\n\n" NOR);
    me->move("/d/gumu/tianjing");
    tell_object(me, CYN "\n\n�����һ��ˤ�ڵ��ϣ�����ͣ��������ȴҲˤ�˸�����������\n\n" NOR);

    return 1;
}
