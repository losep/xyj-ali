// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/4world/tudi.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

һ��СС�����������﹩�����ع�������������(status)����
̨�ϰ���Щ��Ʒ���򣬻���Щ���ƽ�������顣����ܾ�������
��ʲô�춯����̨����֧���򷢳������Ĺ��ߡ�
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "status" : "��������ܹ��ƶ�(push)��\n",
]));


  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west2",
]));

  setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{       
        object me,m;
        me=this_player();
   m=new("/d/4world/npc/niwawa");
        if ( !arg &&(arg != "���ع���")&&(arg !=
"��������")&&(arg!="status") )
                return notify_fail("��Ҫ��ʲô��\n");
   if (objectp(present("mud baby", environment(me))))
     return notify_fail("����������Ц������˵���������أ���ʲô�ƣ�\n");

     message_vision("$Nʹ�������������ع������������ŵ�����\n",me);
     m->move(environment(me));
     write("�����¡�������گ�������ĳ�������������\n");
                return 1;
}

