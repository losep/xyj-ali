// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
   set_name("��ʬ", ({ "zombie" }) );
   set("long",
     "����һ�߱����÷�����ƵĽ�ʬ�������԰׵����Ͽ������κ�ϲŭ���֡�\n");
   set("max_kee", 500);
   set("max_sen", 500);
   set("max_mana", 200);
   set("mana", 200);
        set("max_force", 200); 
        set("force", 200);
   set("age", 50);
   set("str", 25);
   set("cor", 30);
   set("chat_chance", 15);
   set("chat_msg_combat", ({
     "��ʬ���з����ɺɵĽ�����\n",
     "��ʬ�����Ͽ�ʼ���Σ�һ��鴤�������Ƶش�С�\n",
     "��ʬ��ָ���ţ�ҧ���гݣ�¶��������Ц�ݡ�\n",
     (: do_bite :),
   }) );
   set_skill("unarmed", 30);
   set_skill("dodge", 30);

   set_temp("apply/damage", 15);

   setup();
}

int is_zombie() { return 1; }

void animate(object who, int time)
{
   set("possessed", who);
   set_leader(who);
}

void die()
{
   object corpse;
        if( environment() ) {
                message("sound", "��ʬ�����ص�����ȥ����Ϊһ̲Ѫˮ��\n", environment());
        }

   destruct(this_object());
}

int heal_up()
{
   object master;

   if( objectp(master = query("possessed")) 
   &&   (int)master->query("mana") > 100 
   &&   (int)master->query("kee") > 100) {
     message("tell",
        HIR + name() + "�����㣺��...��...Ҫ...��...��...��...��...\n" NOR,
        master );
     master->add("mana", -50);
     master->receive_damage("sen", 50);
     ::heal_up();
     return 1;     // Always acquire power from master.
   } else {
     call_out("die", 1);
     return ::heal_up();
   } 
}

void do_bite()
{
   object *enemy;

   say( name() + "�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n" );
   enemy = query_enemy();
   for(int i=0; i<sizeof(enemy); i++) {
     if( !enemy[i] ) continue;
     enemy[i]->receive_damage("sen", 30);
     COMBAT_D->report_status(enemy[i], "sen");
   }
}
void init()
{
        add_action("do_attack", "attack");
}

int do_attack(string arg)
{
   object obj, master;
   objectp(master = query("possessed"));
   if( wizardp(this_player()) )
     master = this_player();
   if( (string)this_player()->query("name")!=(string)master->query("name") ) 
   return notify_fail("��ʬ������������������Ը���㣡\n");

   if(!arg || !objectp(obj=present(arg,environment(this_player()))))
           return notify_fail("�����ý�ʬ����˭��\n");

        if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");
   message_vision("$N������$n˵��Щʲô��\n", master, this_object());
   message_vision("$N��$n������ȥ����!\n", this_object(), obj);
   this_object()->set("combat_exp", (int)this_player()->query("combat_exp")*2);
   this_object()->set_skill("unarmed", (int)this_player()->query_skill("unarmed")+(int)this_player()->query("kar"));
        this_object()->set_skill("parry", (int)this_player()->query_skill("parry")+(int)this_player()->query("kar"));
        this_object()->set_skill("dodge", (int)this_player()->query_skill("dodge")+(int)this_player()->query("kar"));
   message_vision("\n$N���һ������ȭ����$n��ȥ��\n\n", this_object(), obj);
   // fixed by snowcat: don't use kill_ob (too easy to cause bugs!)
   command("kill "+obj->query("id"));
   return 1;
}
