
inherit ROOM;

void create()
{
    set("short", "Ӫ��");
    set("long", @LONG

�������Ӻ󣬳������ļҽ����⣬����һЩ�ϲ���ҲԸ��׷������
���㽫��Щ���ֵܰ����ڸ�ۡ�����һ��Ӫ���ڡ���Ҷ��ǹ�����
�������ĵ���Ѫ���ӣ�ʵ�����в�ס�����Ծ���ϲ��������������
һ����������������һ���󺺣��������۾���Ϣ���������ƺ�����
˧��
LONG);

    set("exits", ([ /* sizeof() == 1 */
        "southwest" : __DIR__"center",
    ]));
    set("objects", ([ /* sizeof() == 3 */
        __DIR__"npc/fujiang" : 2,
        __DIR__"npc/chengyaojin" : 1,
    ]));
    
    setup();
}

