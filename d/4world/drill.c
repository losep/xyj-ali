
inherit ROOM;

void create()
{
    set("short", "���䳡");
#if 1
    set("long", @LONG

���������䳡������û���ˡ�
LONG);
#else
    set("long", @LONG

���������䳡���Ĺ��佫���������£�����ƫ�Խ�У������������
�����С����Ҿ�ʿ����ȫװ�ߴ����ָ�ִꪶ������м�һ���б�
ʿ�������ݵĴ��������С�
LONG);
#endif

    set("exits", ([
        "north"   : __DIR__"drillent",
        "south"   : __DIR__"arsenal",
    ]));

    set("outdoors", __DIR__);

    setup();
}
