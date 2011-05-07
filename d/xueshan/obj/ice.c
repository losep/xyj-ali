// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ice.c...weiqi, 970925

#include <ansi.h>

inherit ITEM;

int do_make(string);

void create()
{
   seteuid(getuid());
   set_name(HIW "����" NOR, ({ "bing kuai", "bingkuai", "bing", "ice" }) );
   set("long", "����һƬ�����ģ�����ģ����쬵ı��顣\n");
   set("unit", "Ƭ" );
   set("value", 8);
   set("material", "ice");
}


void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
   object env;

        if(!this_object()) return;

   env=environment(this_object());

   if( env->is_character() )
   {//a player or a NPC.
     if( (int)env->query_skill("iceblood-force", 1) < 20 )
     {
        message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ��黯�ˡ�\n", env);
        destruct(this_object());
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "xueshan" )
     {
        tell_object(env,"�������ڻ�����һ̲ˮ�����õ������ǡ�\n");
        destruct(this_object());
        return;
     }
   }

}

void init()
{                                             
        remove_call_out("do_melt");
        call_out("do_melt", 1);
   add_action("do_make", "make");
   add_action("do_make", "zuo");
   add_action("do_chi", "chi");
   add_action("do_chi", "eat");
}

int do_make(string arg)
{
   object ob, me;

   me = this_player();

   if( !arg || (arg != "blade" && arg != "dao" && arg != "sword" && arg != "jian" ) )
     return notify_fail("��Ҫ��ʲô��\n");
   if( arg == "sword" || arg =="jian" )
     return notify_fail("��Ƭ������ģ������˽���\n");

   if( (int)me->query("force") < 200 || (int)me->query_skill("iceblood-force", 1) < 20 )
   {
     message_vision("$N�������������ȥ���������ܿ�ͻ����ˡ�\n", me);
     destruct(this_object());
     return 1;
   }   

   ob=new("/d/obj/weapon/blade/iceblade");
   ob->move(me);
   me->add("force", -100);
   message_vision("$N�������������ȥ����Ȼ������һ������ı�����\n", me);
   destruct(this_object());

   return 1;
}

int do_chi(string arg)
{   
   if( !this_object()->id(arg) ) return 0;
   if( this_player()->is_busy() )
     return notify_fail("����һ��������û����ɡ�\n");

   if(!arg) return notify_fail("��Ҫ��ʲô��\n");

   message_vision( "$N�������ʹ��һҧ��ֻ�����գ�һ���������ˡ�\n" , this_player());
   if( (int)this_player()->query("kee") > 20 )
     this_player()->add("kee", -20);
   else this_player()->unconcious();

   return 1;
}

