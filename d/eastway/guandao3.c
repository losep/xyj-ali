// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao3.c

inherit ROOM;

void create ()
{
    set ("short", "�ٵ�");
    set ("long", @LONG

����һ�������Ĺٵ����ٵ��������У������������ٵ�������ͨ��
��ʿ����ԶԶ��ȥ�ƺ���һ����������������������ģ����������
LONG);

    set("exits", ([
            "southwest"  : __DIR__"guandao2",
            "east"       : __DIR__"huaqing",
            "west"       : __DIR__"jinshi",
        ]));
    set("outdoors", __DIR__);
    
    setup();
}






