// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /city/erlou.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG

���ƹ�����һ��˯��������ɸɾ�����
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);
        set("exits", ([
                "south" : "/d/sea/girl2",
        ]));

        setup();
}

