// ALi by NewX
 
// Room: /d/city/qilin.c

inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG

̫���������ڼ�λǰ�ܷ�����������ı���½�Ϊ������������������
�����͡�����Ϊ��Щ������������һ����¥����Ի������󡹡���
¥���ܹҽǣ���������������֮ʱ��������������ǰ���ۿ�����ϧ��
�����������һ�๦���Ѿ�������ɢ������Ҳ������������ż��
���м������˹���ƾ��һ����������������ĸ�̾��
LONG
    );
    set("no_fight", 1);
    set("item_desc", ([ /* sizeof() == 1 */
        "up" : "¥���������壬�ż��������ƺ�һ����Ҳû�С�",
    ]));
    set("no_clean_up", 0);
    set("light_up", 1);
    set("exits", ([ /* sizeof() == 2 */
        "up" : __DIR__"qilin2",
        "east" : __DIR__"xuanwu-n1",
    ]));
    set("objects", ([
        "/d/obj/misc/chairs" : 4,
        "/d/obj/misc/tables" : 1,
    ]));

    setup();
    replace_program(ROOM);
}
