//created by vikee
//2000.10

inherit ROOM;

void create()
{
    set("short", "��ɳ��");
    set("long", @LONG

�ɴ���ǳ����ã����عڽ�Ʃ�Ի͡��������ġ���緽��¡�
����ײ���������������أ������ʱ����ʥ���������.
LONG);

    set("exits", ([ /* sizeof() == 1 */
        "south"  :  __DIR__"tongmingdian",
        "north"  :  __DIR__"tonglugong",
    ]));
    set("objects",([
        //__DIR__"npc/xszj"  :  1,
    ]));
    set("no_quit",1);
    setup();
}

void init()
{
    object wang,zj,who = this_player(),env = this_object();

    if(!userp(who) || who->query("huoyan/bgl")!="done"||
      who->query("dntg/huoyan")=="done") return;
    if(!zj=present("xusheng zhenjun",env) ){
      zj = new(__DIR__"npc/xsjz");
      zj->move(env);
   }
    zj->command_function("chat " + who->name() + "��" + RANK_D->query_rude(who) +
      "����ɳ���ˣ��Ĵ������������ݣ�\n");
    message_vision("�Ĵ�������ӵ��������$N��Χ�ڵ��С�\n",who);
    if(!present("moli hong",env)){
      wang = new(__DIR__"npc/tianwang2");
      wang ->move(env);
   }
    if(!present("moli qing",env)){
      wang = new(__DIR__"npc/tianwang3");
      wang ->move(env);
   }
    if(!present("moli shou",env)){
      wang = new(__DIR__"npc/tianwang4");
      wang ->move(env);
   }
    if(!present("moli hai",env)){
      wang = new(__DIR__"npc/tianwang1");
      wang ->move(env);
   }
}

int valid_leave(object ob, string dir)
{
    object guan;
    if( !guan = present("xusheng zhenjun",this_object()));
      guan = present("moli hong",this_object());
    if( !guan ) guan = present("moli qing",this_object());
    if( !guan ) guan = present("moli shou",this_object());
    if( !guan ) guan = present("moli hai",this_object());
    if(guan) {
      message_vision("$n��$Nһ�������ߣ�û��ô���ף�\n",ob,guan);
      return notify_fail("���������߲����ˡ�\n");
   }
    return ::valid_leave(ob,dir);
}

