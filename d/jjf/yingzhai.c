// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
    set ("short", "��Ӫկ");
    set ("long", @LONG

�����Ǳ�Ӫ���������ǹٱ�������ȥ���е����佫��ָ�����жӲ�
�����еĶ������������е����š�����������Ϣ������û�п�����
˧��
LONG);
    
    set("exits", ([ /* sizeof() == 1 */
        "south" : "/d/city/baihu-w4",
    ]));
    set("objects", ([ /* sizeof() == 2 */
        "/d/jjf/npc/fujiang" : 2,
    ]));
    
    setup();
}

