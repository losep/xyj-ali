// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// girl1.c

inherit ROOM;

void create()
{
  set ("short", "���ƹ�");
  set ("long", @LONG

���ƹ��ǹ�����Ůס�ĵط�����Ȼ���ﲻ�����ӳ��롣�����װ��
�����˼��ѵ�һ�����䱦������һ������ɵ���¯���۵�ð��һ
�ɵ���ɫ�ı��̣�������������������
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"inside1",
"southeast" : __DIR__"girl2",
]));
set("objects", ([
                __DIR__"npc/qiupo": 1]) );

        set("no_clean_up", 0);
        setup();
}

