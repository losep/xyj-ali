// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao2.c

inherit ROOM;

void create ()
{
    set ("short", "�ٵ�");
    set ("long", @LONG

����һ�������Ĺٵ����ٵ��������У������������ٵ�һ��ͨ����
�ϣ�һ��ͨ�򶫱�����������һ����Ĺ��
LONG);

    set("exits", ([
            "southwest" : __DIR__"guandao1",
            "northeast" : __DIR__"guandao3",
            "southeast" : __DIR__"shihuang",
        ]));
    set("outdoors", __DIR__);
    
    setup();
}






