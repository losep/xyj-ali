// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
inherit F_VENDOR;

int base_price=100000;

int ask_money();
void create()
{
        set_name("�Ϻ���", ({"xifuhui boss","boss" }));
   set("title", "ϲ�����ϰ���");
   
        set("age", 32);
        set("gender", "Ů��");
        set("attitude", "friendly");

        set("combat_exp", 50000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
   set("per", 20);

set("inquiry", ([
"name": "���±���������ϰ塣",
"here": "������ϲ���ᣬ�����ǰ�ϲ��ĵط�����ϧ�����������£����Ĳ��ţ����û�˽���ˡ�",
"ϲ��" : "ȥ��һ��ȥ���������û�˽���ˣ��Ļ���ʲôϲ�磿",
"��ϯ" : "���㲻��ϲ�磬ֻҪ��Ը�⻨Ǯ��һ������Ϊ��ٰ�һ����ᡣ",
"���" : "���㲻��ϲ�磬ֻҪ��Ը�⻨Ǯ��һ������Ϊ��ٰ�һ����ᡣ",
"party" : "���㲻��ϲ�磬ֻҪ��Ը�⻨Ǯ��һ������Ϊ��ٰ�һ����ᡣ",
"money": (: ask_money :),
]) );
        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}

void init()
{
    ::init();
   add_action("do_serve", "serve");
   add_action("do_finish", "finish");
   add_action("do_start", "start");
     add_action("do_fight", "fight");
     add_action("do_kill", "kill");
     add_action("do_steal", "steal");
     add_action("do_cast", "cast");
     add_action("do_exert", "exert");
     add_action("do_perform", "perform");
     add_action("do_bian", "bian");
   add_action("do_fight", "fight");

}

int accept_object(object who, object ob)
{
   object m;
   int value;

   value=ob->value();

   if( !value )
     return notify_fail(name()+"��ֵĿ�����˵���������ʲô��\n");

   call_out("destroy", 1, ob);
   if( value >= base_price ) {
	who->set_temp("host_of_party", 1);
	call_out("count_money", 2, who);
	call_out("start_party", 5, who);
   }
   return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
void count_money(object who)
{
   message_vision("\n$N��$n����Ǯ��ϸ�������һ�顣\n\n", this_object(), who);
   message_vision("$Nʹ���˵����ϯ��\n", this_object() );
}

void start_party(object who)
{
   object me=this_object();
   command("chat* "+name()+
          "����λ��ү̫̫��үС�㣬����" + who->query("name") +  
"��ϲ����󿪾�ϯ����ӭ��λǰ��������");
   command("say ��Ҫ��ʼ(start)���ұ㿪ϯ����Ҫ�ϲ�(serve)���Ҿ��ϲˣ������Ա��ˣ������ˣ��۾ͽ���(finish)��");
   me->set_temp("ready_to_party", 1);
}
int do_start()
{   
   object who = this_player();
        object me = this_object();
   int i;
   object *list;
   object girla,girlb,girlc,girld,cup;
   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"����˵�����ֲ������ˣ�\n");
   if( !me->query_temp("ready_to_party") )
     return notify_fail(name()+"����˵����ʼʲôѽ��������û�˰���ᣡ\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"�����Ķ���˵���ⲻ���Ѿ���ʼ���\n");

   message_vision("$N������$n˵���ϰ壬��ϯ��\n\n", who, me);
   message_vision("$N�������ţ�������ϯ����ඡ���\n\n", me);
   me->set_temp("party_start_already", 1);
   me->delete_temp("ready_to_party");

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       object ob= list[i];
      if( cup=new("/d/obj/food/dishes/cup"))
       cup->move(ob);
   }
   seteuid(getuid());
   if(girla=new("/d/city/npc/girla"))   
    girla->move(environment(me));

        seteuid(getuid());
        if(girlb=new("/d/city/npc/girlb"))
        girlb->move(environment(me));

        seteuid(getuid());
        if(girlc=new("/d/city/npc/girlc"))
        girlc->move(environment(me));

        seteuid(getuid());
        if(girld=new("/d/city/npc/girld"))
        girld->move(environment(me));

   tell_room(environment(who), "�����߳�����Ư����С���\n");
   tell_room(environment(who), "��õ���һ�������յ��\n");
   call_out("finish_party", 500, who);
   return 1;
}
int do_serve()
{
   object me=this_object();
   object who=this_player();
   object food;
   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"�����µ������˻�û˵�������¸�ʲô����\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"����˵���㻹û������ʼ(start)����ô�ϲ��أ�\n");
   if ( (present("food 2", environment(me))) )
     return notify_fail(name()+"����˵�������ԣ�������Ȼ������ϲˡ�\n");

   message_vision("$N���������ţ��ϲˣ��ϲˣ�\n", who);

   tell_room(environment(me), "�������ܳ������С��ƣ��ֽ������Ľ����ϵ�ʣ�˷�������ȥ��\n");
   tell_room(environment(me), "С����ִ����ó�����������һ���µľ�ϯ��\n");
        if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   return 1;
}
int do_finish()
{
   object me=this_object();
   object who=this_player();

   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"������һ�ۣ�����˵����\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"������һ�ۣ������Ѿ���������\n");
   message_vision("$N��$n˵�����Ա����㣬��л�ϰ��д���\n", who, me);
   remove_call_out("finish_party");
   call_out("finish_party", 3, who);
   return 1;
}
void finish_party(object who)
{
   object me=this_object();
        int i;
        object *list;

   message_vision("$N����˵������ϯ�ʹ˽�������л��ҹ��٣�\n", me);

   me->delete_temp("party_start_already");
   who->delete_temp("host_of_party");
   list=all_inventory(environment(me));
   i=sizeof(list);
   while (i--)
   {
     if(list[i]->query("id") != "ban niang")
        continue;
     else
        destruct (list[i]);
   }
}