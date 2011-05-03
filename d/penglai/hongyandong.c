inherit ROOM;

void create()
{
    set("short", "���ն�");
    set("long", @LONG

һ��ռ�ز�����Ҷ���ʯ�ʯ��ʯ�Σ����õø������ס�
ʯ���Ϸ���һ����֦�������Ƶ���ߣ��ݽǷ���һ¯�ٻ�
�㣬ɢ���ŵ������㡣��¯�߰���һ����ľ���١��ٻ���
����������ʱ�����ڴ�����Ѱٲ����ӡ���á�֯Ů����
���壬��ң���ڡ�
LONG);
    set("exits", ([ /* sizeof() == 3 */
        "northup" : __DIR__"penglai",
        "southdown" : __DIR__"bomingyan",
        "east": __DIR__"baihuajiao",
    ]));
    set("objects", ([ 
        __DIR__"npc/baihua-xianzi" : 1,
    ]));
  
  setup();
}

int valid_leave(object me, string dir)
{
    object xianzi;
    if (dir == "northup"
    ||  !(xianzi = present("baihua xianzi", environment(me)))
    ||  !living(xianzi))
        return ::valid_leave(me, dir);
    if (me->query("family/family_name") != "�¹�")
        return notify_fail("�ٻ�����һ�Ѿ�ס�㣺�������¹����˲��������\n");
    if (me->query("family/master_name") == "�϶�")
        return notify_fail("�ٻ�������������ǰ�������˵��������ʦ���������������޵ģ���\n");
    if (dir == "east" && random(2)) {
        me->start_busy(random(2));
        return notify_fail("�ٻ�������ס����֣����̵����������������ͱڣ�ǧ��С�ģ���\n");
    }
    return ::valid_leave(me,dir);
}
