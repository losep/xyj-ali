// ALi by NewX

inherit ROOM;

void create ()
{
    set ("short", "������");
    set ("long", @LONG

���ﾹȻ����ԯ�ɵ���������������ԯ������Ҫ�ľ��Ǵ��Ϲ������
���е���ÿ�춼��������Ϲ�����Ϊ�������������������Ѱ�٣�
���Դ����ʱ�����Ƕ�ֻ���������ķ�ʽ��������������ȥ��һ���޼�
��ѩ��������Ľ�������������е��������߳����˽д���˷���ʵ
����εΪ׳�ۡ�
LONG);

  set("objects", ([ /* sizeof() == 3 */
        __DIR__"npc/zmgirl.c" : 3,
]));

    set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"shidong3.c",
]));

    setup();
}

/*
void init()
{
        add_action("do_serve", "serve");
   add_action("do_stand", "stand");
   add_action("do_sit", "sit");
}

int valid_leave()
{
        if((present("snowglass", this_player())))
            return notify_fail("�˱����϶��İ�֮����߲��װɡ�\n");
    return ::valid_leave();
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

        if ( !arg || ((arg != "seat")&&(arg != "deng")&&(arg != "table") ))
                return notify_fail("��Ҫ����ʲô���棿\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("���Ѿ������ˡ�\n");
      
      if ( arg != "seat"&&arg != "deng")
              return notify_fail("�������ϣ�̫���Ź��˰ɡ�\n");
        
        this_player()->set_temp("marks/sit", 1);
        message_vision("$N�������ɵ�������Сľ�ʡ�\n",me);
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
int do_serve(string arg)
{
        object m,mm;
   if ((int)this_player()->query_temp("marks/sit") == 0)
     return notify_fail("��������������β�������С�ã�\n");
        if((int)this_player()->query("food") >=
     (int)this_player()->max_food_capacity()*90/100)
        return notify_fail("����羰��ô�ã�������ųԣ���\n");
            
        if(present("xue li", this_player()) || 
     present("guihuageng", this_player()) ||
     present("xue li", environment(this_player()))
   )
        return notify_fail("���ǻ��гԵ���\n");

        m=new(__DIR__"obj/xueli.c");
   mm=new(__DIR__"obj/guihuageng.c");
   
   message_vision("$N������������䣬ľ���������а����˹�Ʒ���ģ�\n", this_player());

        m->move(environment(this_player()));
        mm->move(environment(this_player()));

return 1;
}
*/

