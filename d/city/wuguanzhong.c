// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
  set ("short", "�������");
  set ("long", @LONG

������ݵ����ã�һ�ж���������������û�е���ʲôҲ���������
��Լ�������ų��Σ�����ǽ�Ϲ�һ����(qi)��
LONG);
set("item_desc",(["qi":"
        ����������������
        ����ȭ����ʡ����
        ���������ܵУ���
        ����������������\n"
]));
        set("objects", ([
                __DIR__"npc/fan": 1, 
                "/d/obj/misc/chairs" : 2,
                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"wuguan",
]));
  setup();
}

