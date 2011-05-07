// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// redblueice.c...weiqi, 970926
//this ice contains posion...

#include <ansi.h>

inherit ITEM;

int melted;
int do_make(string);

void create()
{
   seteuid(getuid());
   set_name(RED "˫" NOR + HIB "ɫ" NOR + HIW "��" NOR, ({ "shuangse bing", "bingkuai", "bing", "ice" }) );
   set("long", "����һƬ�����ģ�����ģ����쬵ı��飬��������ʱ͸�죬��ʱ��͸����\n");
   set("unit", "Ƭ" );
   set("value", 8000);
   set("material", "ice");
   melted = 0;
   if( clonep(this_object()) ) call_out("melt", 60, 1);
   set("is_monitored",1);
   setup();
}

void melt(int count)
{
   object env;

   melted = count;

   env=environment(this_object());

   if( env->is_character() )
   {//a player or a NPC.
     if( (int)env->query_skill("iceblood-force", 1) < 50 )
     {
        message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ��黯�ˡ�\n", env);
        env->apply_condition("double_ice_poison", 10);
        //note, �ж��ˡ�        
        destruct(this_object());
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "xueshan" )
     {
        message_vision("�������ڻ�����һ̲ˮ�����õ������ǡ�\n", this_object());
        destruct(this_object());
        return;
     }
   }

   call_out("melt", 60, count + 1);
}

void init()
{                                             
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
     me->apply_condition("double_ice_poison", 10);
     //note, �ж��ˡ�
     destruct(this_object());
     return 1;
   }   

   ob=new("/d/obj/weapon/blade/handudao-redblue");
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

   if( (int)this_player()->query("force") < 200 || (int)this_player()->query_skill("iceblood-force", 1) < 50 )
     this_player()->apply_condition("double_ice_poison", 5);

   return 1;
}

