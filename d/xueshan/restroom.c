// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//restroom.c

inherit ROOM;

void create ()
{
   set ("short", "��Ϣ��");
   set ("long", @LONG

������ѩɽ����ƽʱ��Ϣ�ĵط�����������һ�Ŵ�ʯ���������
��һЩˮ�����ġ����ϻ���������䡣���п��ϵ�һ�����Ϲ���
һ������(paizi)����ǽ�������߰����д�����֡�
LONG);

   set("item_desc", (["paizi" : "Ů�����Է��������Ͻ����ڡ�\n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"girlroom",
     "north" : __DIR__"boyroom",
     //"west" : __DIR__"restroom",
     "east" : __DIR__"wuchang-w",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/misc/seat" : 2,
     "/d/obj/misc/table" : 1,
     "/d/obj/food/xueli" : 3,
     "/d/obj/food/zongzi" : 1,
   ]));

   set("valid_startroom", 1);

   set("outdoors", "xueshan");

   setup();

   "/obj/board/xueshan_b"->foo();
}

void init()
{
   add_action("do_stand", "stand");
   add_action("do_sit", "sit");
}

int do_sit(string arg)
{     
   object me;
   me=this_player();

   if ( !arg || ((arg != "seat")&&(arg != "table") ))
     return notify_fail("��Ҫ����ʲô���棿\n");   
   
   if (this_player()->query_temp("marks/sit"))
     return notify_fail("���Ѿ������ˡ�\n");   
      
   if ( arg != "seat")   
     return notify_fail("�������ϣ�̫���Ź��˰ɡ�\n");
           
   this_player()->set_temp("marks/sit", 1);
   message_vision("$N�����������ʯ�����������������˶����ȡ�\n",me);
   return 1;   
}

int do_stand(string arg)
{
   object me;
   me=this_player();

   if (!this_player()->query_temp("marks/sit"))
     return notify_fail("�㱾����վ�š�\n");

   this_player()->set_temp("marks/sit", 0);
   message_vision("$N���˸�������վ��������\n", me);
   return 1;
}




