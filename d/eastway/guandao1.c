// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/eastway/guandao1.c

inherit ROOM;

void create()
{
    set("short", "�ٵ�");
    set("long", @LONG

����һ�������Ĺٵ����ٵ��������У��������ϡ�����ȥ�ȶ�����
����ݷ��������Ů�����и��Դ��˼��е�̫̫С��Ϊ�ࡣ�ϱ߿�
������Ժ����Լһ����Ӱ�����º�
LONG
    );
    set("exits", ([ /* sizeof() == 3 */
        "southwest" : __DIR__"east1",
        "northeast" : __DIR__"guandao2",
        "southeast" : __DIR__"ciensiw",
    ]));
    set("objects", ([
        __DIR__"npc/luren"     : 2,
    ]));
    set("no_clean_up", 0);
    set("outdoors", __DIR__"");
    
    setup();
    replace_program(ROOM);
}
