// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//huludi.c

inherit ROOM;

void create ()
{
   set ("short", "���ϵ�");
   set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ������������ϵء���������һ��������ɵ���ʣ�
����Ͽ���һ����ª����ľ�ţ����Ϲ���һ�ѻ�ͭ����
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "southeast" : __DIR__"baicaidi",
     "southwest" : __DIR__"huludi",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/food/watermellon" : 3,
   ]));

   //create_door("north", "��ľ��", "south", DOOR_CLOSED);
   set("outdoors", "wuzhuang");

   setup();
}

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   object me, key, nroom;

   me = this_player();

   if( !arg || arg != "door" ) 
     return notify_fail("��Ҫ��ʲô��\n");

   if( !(key = present("huangtong key", me)) ) 
     return notify_fail("��û�п�����ŵ�Կ�ס�\n");

   //now we are ready to open...
   if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
     nroom = load_object(__DIR__"renshenguo-yuan");

   set("exits/north", __DIR__"renshenguo-yuan");
   nroom->set("exits/south", __FILE__);
   message("vision", "ֻ�����꣡һ����Կ�׶��ˡ��������Ѿ����ˡ�\n", this_object() );

   me->set_temp("used_huangtong_key", 1);
   destruct(key);
   return 1;
}


