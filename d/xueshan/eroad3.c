
//eroad3.c

inherit ROOM;

void create ()
{
   set ("short", "���µ�");
   set ("long", @LONG

���µ׵ĹսǴ������α����ڴ˽��ᣬ���Ͽ�ȥ���Ʋ�����ô
�վ��ˡ�
LONG);

   set("exits", ([ //sizeof() == 1
     "west" : __DIR__"eroad2",
   ]));

   set("outdoors", "xueshan");

   setup();
}

void init()
{
   add_action("do_climb", "climb");
   add_action("do_climb", "pa");
}

int do_climb(string arg)
{
   object me;

   me=this_player();

   if( !arg || arg != "up" ){
     return notify_fail("��Ҫ��������ȥ��\n");
   }
   message_vision("$N���㲢�ã���ס�����������˹�ȥ��\n", me);
   me->move(__DIR__"bingya-up1");
   message_vision("$N���������ش��������˹�����\n", me);   
   return 1;    
}


