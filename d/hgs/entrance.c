// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/entrance
inherit ROOM;

// int do_push(string);

void create ()
{
  set ("short", "��ʯ");
  set ("long", @LONG

�����ǻ���ɽ����һ��ƽ�ء�һ���ٲ���ɽ������ֱ�£�
к��һ����̶�������ǣ���һ�ɰ׺���ǧѰѩ�˷ɡ���
�ٲ�������һ���ʯͷ���ഫΪ���������������֪��˭��
�������һ��ʫ��

������������δ������ң�ãã�������˼���
���������Դ��̹��ƺ��ɣ����ٴ������Ǳ档

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/ourhome/npc/longear" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"houshan1",
  "southdown" : __DIR__"up2",
]));

  setup();
}

void init()
{
   add_action("do_push", "push");
}

int valid_leave(object me, string dir)
{
   object mbox;

   if( mbox = me->query_temp("mbox_ob") ) {
     tell_object(me, "�㽫���佻�ظ��ʲ\n");
     destruct(mbox);
   }
   return 1;
}

void check_trigger()
{
   object room;

   if( (int)query("left_trigger")==3
   &&   (int)query("right_trigger")==5
   &&   !query("exits/down") ) {
     message("vision", "��ʯ��Ȼ����������������¶��һ�����µĽ��ݡ�\n",
        this_object() );
if( !(room = find_object(__DIR__"inner_shuiliandong")) )
room = load_object(__DIR__"inner_shuiliandong");

     if( room = find_object(__DIR__"inner_shuiliandong") ) {
set("exits/down", __DIR__"inner_shuiliandong");
        room->set("exits/up", __FILE__);
        message("vision", "��ʯ��Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",
          room );
     }
     delete("left_trigger");
     delete("right_trigger");
     call_out("close_passage", 10);
   }
}

void close_passage()
{
   object room;

   if( !query("exits/down") ) return;
   message("vision", "��ʯ��Ȼ���������������������µ�ͨ����ס�ˡ�\n",
     this_object() );
   if( room = find_object(__DIR__"inner_shuiliandong") ) {
     room->delete("exits/up");
     message("vision", "��ʯ��Ȼ�������������������ϵ�ͨ���ֻ����ر���ס�ˡ�\n",
        room );
   }
   delete("exits/down");
delete("left_trigger");
delete("right_trigger");
}


int do_push(string arg)
{
   string dir;
   object me=this_player();

   if( !arg || arg=="" ) return 0;

   if( arg=="stone" ) {
     write("�������ƶ���ʯ���ƺ��������һ���....\n");
delete("left_trigger");
delete("right_trigger");
     return 1;
   }
   if( sscanf(arg, "stone %s", dir)==1 ) {
     if( dir=="right" ) {
if(query("exits/down")) return notify_fail("��ʯ�Ѿ����ƿ��ˡ�\n");
        message_vision("$N����ʯ������...����Ȼ������һ����ʯ���ƻ�ԭλ��\n", me);
        add("right_trigger", 1);
        check_trigger();
        return 1;
     } else if( dir=="left" ) {
if(query("exits/down")) return notify_fail("��ʯ�Ѿ����ƿ��ˡ�\n");
        message_vision("$N����ʯ������...����Ȼ������һ����ʯ���ƻ�ԭλ��\n", me);
        add("left_trigger", 1);
        check_trigger();
        return 1;
     } else {
        write("��Ҫ����ʯ���ı��ƣ�\n");
        return 1;
     }
   }
}


void reset()
{
   ::reset();
   delete("left_trigger");
   delete("right_trigger");
}

