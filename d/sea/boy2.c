// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// boy2.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

һ�����������ȣ�������ǰ������������̫�ӵ����ң���������
�����������������Ů���ź���������ȥ������һ���������̫
������ĵط���
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"boy1",
"east" : __DIR__"boy3",
"north" : __DIR__"boy4",
]));
set("objects", ([
                __DIR__"npc/gongnu": 2]) );

        set("no_clean_up", 0);
        setup();
}

