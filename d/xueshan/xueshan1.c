// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//xueshan1.c

inherit ROOM;

void create ()
{
  set ("short", "ããѩ��");
  set ("long", @LONG

�����Х����ѩãã������������ȥ�������Ӳ�����ѩ�壬����ǰ�߱�Ҫ
��������������ˡ����Ϸ�������Ⱥɽ�����ֻ�Ǳ�ѩ�Ѳ������ڣ�Ҫ��
����ѩɽ�ǳɹ������ˡ�
LONG);

  set("outdoors", "xueshan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xueshan2",
  "south" : "/d/kunlun/kunlun",
]));

  setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}



