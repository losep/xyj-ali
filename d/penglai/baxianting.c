// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;
#include <room.h>

void create ()
{
    set ("short", "����ͤ");
    set ("long", @LONG

�����뿪��ׯ�ۺ󣬾͵������Ρ���Ϊ�����������ཻ���꣬�����
�����̻���ʱ����ࡣΪ�ˣ�������޽���һ������ͤ��ר��������
�š�
LONG);
    set("exits", ([ /* sizeof() == 3 */
        "west" : __DIR__"road1",
    ]));
    set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/hanzhongli" : 1,
        __DIR__"npc/tieguaili" : 1,
        __DIR__"npc/hanxiangzi" : 1,
        __DIR__"npc/hexiangu" : 1,
        __DIR__"npc/lancaihe" : 1,
        __DIR__"npc/caoguojiu" : 1,
    ]));
    set("outdoors", 1);
    setup();
}
