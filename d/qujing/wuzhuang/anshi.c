// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//anshi.c
#include <room.h>
inherit ROOM;

void create ()
{
   set ("short", "ͤ�װ���");
   set ("long", @LONG

����ĵ��ͤ���µ�һ�䰵�ҡ��ڹ����˵�ʲôҲ�����塣������
����������(mo)�� 
LONG);

   set("exits", 
   ([ //sizeof() == 4
     //"southwest" : __DIR__"juyuan",
     //"north" : __DIR__"southpool",
     "up" : __DIR__"mudanting",
     //"west" : __DIR__"westway6",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"obj/huangtong-key" : 1,
   ]));

   create_door("up", "���װ���", "down", DOOR_CLOSED);
   //set("outdoors", "wuzhuang");

   set("no_clean_up", 1);

   setup();
}


void init()
{
   add_action("do_mo", "mo");

   if( query("started") != 1 )
   {
     set("started", 1);
     call_out("generate_key", 54000);//15 hours
   }
}

void generate_key()
{
   remove_call_out("generate_key");
   set("available", 1);
}

int do_mo(string arg)
{
   object me, key;

   me = this_player();

   if( query("available") == 1 )
   {
     set("available", 0);
     key = new(__DIR__"obj/huangtong-key");
     key -> move(this_object());
     message_vision("ֻ��������һ����һ�ѻ�ͭԿ�׵��ڵ��ϡ�\n", me);

     remove_call_out("generate_key");
     call_out("generate_key", 54000);//15 hours

     return 1;
   }
   else return notify_fail("��ʲôҲû���š�\n");
}

int clean_up()
{
   return 0;
}


