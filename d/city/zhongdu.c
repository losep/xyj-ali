// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

���ǳ����ǵ��������أ��������Ĵ�С�¼���������͵��������С
��������ɱ�˷Ż��ǿ���������������ܵ�Ӧ�еĴ���������ǽ����
����һЩ��ʾ(gaoshi)��д�Ž����󰸵Ľ���������Ǵ��á�
LONG);
set("item_desc",(["gaoshi":"
       ***********************
       **     �ٸ�ͨ��      **
       ***********************\n"
]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"baihu-w2",
                "north" : __DIR__"datang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yayi" : 6,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
        if (objectp(present("yayi", environment(me)))) {
                if(!present("zhuang zi", me)) 
return notify_fail("���ۺȵ�����������Ҵ����������£�\n");
                }
        return ::valid_leave(me, dir);
        }
        return 1;
}

