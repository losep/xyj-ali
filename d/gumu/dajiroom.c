// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "�����");
    set("long", @LONG

�������槼����޹������䲼�õ÷ǳ����£�ɫ���Ƿۺ�ɫ�ģ�����
����һů�������������������Ũ���쳣������һ�������·�ͻ���
�˻������
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"tianjing",
        "down" : __DIR__"jailroom",
    ]));

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/foxqueen.c" : 1,
    ]));

    setup();
}

int valid_leave(object me, string dir)
{
    object daji;
    if (!wizardp(me) && dir == "down"
    &&  objectp(daji = present("daji", this_object()))
    &&  living(daji))
        return notify_fail("槼������Ƴ����һ�ۣ��㼱æֹ����\n");
    return ::valid_leave(me, dir);;
}