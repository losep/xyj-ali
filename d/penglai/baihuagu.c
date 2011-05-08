
#include <ansi.h>

inherit ROOM;

void setup()
{
    int pos = query("pos");
    int north = (pos/10+4)%5*10+pos%10;
    int south = (pos/10+1)%5*10+pos%10;
    int east = pos/10*10+(pos%10+1)%5;
    int west = pos/10*10+(pos%10+4)%5;

    set("short", "�ٻ���");
    set("long", @LONG

һƬƽ̹�ȵأ���������ɽ���ƣ�ɽ����������ƣ�
����һƬ���ɸ��ء������ļ���������ɫ�ʻ�������
���ޣ���Ŀ�����Ŀ������ӭ�ˣ���һƬ����Ǭ����
�������硣
LONG);

    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"baihuagu" + north,
        "south" : __DIR__"baihuagu" + south,
        "east" : __DIR__"baihuagu" + east,
        "west" : __DIR__"baihuagu" + west,
    ]));
    set("outdoors", 1);
    ::setup();
}

void init()
{
    if (present("hua xianzi", this_object())) return;
    if (random(10)) return;
    remove_call_out("greeting");
    call_out("greeting", 1, this_player(), this_object());
}

void greeting(object me, object env)
{
    if (!me || environment(me) != env) return;
    tell_object(me, MAG"�ٻ����г���һϮٻӰ���㲻��ͣס�Ų����뿴����ϸ��\n"NOR);
    call_out("greeting1", 2, me, env);
}

void greeting1(object me, object env)
{
    object xian;

    if (!me || environment(me) != env) return;
    tell_object(me, MAG"�����ǰһ����һλ���Ȳ�������Ů������������������������\n\n"NOR);

    xian = new(__DIR__"npc/huaxian");
    xian->move(env);
    xian->set("target", me);
}
