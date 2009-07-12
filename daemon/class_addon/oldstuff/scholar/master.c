// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
   set_name("������", ({ "master scholar", "master", "scholar" }) );

   set("gender", "����");
   set("age", 32);
   set("long",
     "���������ھ����������������ң����ı������潨�ף�������Ϊ����ϲ��\n"
     "�Ĵ��ε������Ժš����ۡ����Ĵ���ɽ��ˮ���ύ�������ˡ�����ǰ�̳�\n"
     "�丸���׶���Ϊ�����ɵ��������ţ�����ϲ��Ʈ���ĸ�����Ȼ���ģ�����\n"
     "������ͷʹ���ѡ�\n" );

   set("attitude", "peaceful");
   create_family("������", 7, "������");

   set("str", 26);
   set("cor", 30);
   set("int", 24);
   set("cps", 30);

   set("force", 3000);
   set("max_force", 1600);
   set("force_factor", 20);

   set("combat_exp", 1000000);
   set("score", 200000);
/*
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: consider :),
     (: exert_function, "powerup" :),
     (: exert_function, "recover" :)
   }) );
*/
   set_skill("unarmed", 60);
   set_skill("sword", 90);
   set_skill("force", 80);
   set_skill("parry", 90);
   set_skill("dodge", 100);
   set_skill("literate", 150);
   set_skill("perception", 80);

   setup();
}

/*
void init()
{
   add_action("do_swear", "swear");
}

void attempt_apprentice(object me)
{
   if( me->query_temp("pending/celestial_swear") ) {
     command("say ��˵���棬������������Ź棬���ǹ�������Ҳû�á�");
     return;
   } else {
     command("say ����а���Ź����ϣ�" + RANK_D->query_respect(me)
        + "���������ģ��ҷ�����(swear)����");
     me->set_temp("pending/celestial_swear", 1);
   }
}

int do_swear(string arg)
{
   if( !this_player()->query_temp("pending/celestial_swear") )
     return 0;
   if( !arg ) return notify_fail("��Ҫ��ʲô�ģ�\n");
   this_player()->set_temp("pending/celestial_swear", 0);
   message_vision("$N���ĵ���" + arg + "\n", this_player());
   if( strsrch(arg, "��") >=0 && strsrch(arg, "�Ź�") >=0 ) {
     command("smile");
     command("say ������ˡ�\n");
     command("recruit " + this_player()->query("id"));
   } else {
     command("say �㷢����ʲô���ģ�����Ϊ��û������");
   }
   return 1;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     add("apprentice_availavble", -1);
}
*/
void consider()
{
   int i, flag = 0;
   object *enemy;

   enemy = query_enemy() - ({ 0 });
   for(i=0; i<sizeof(enemy); i++) {
     if( !living(enemy[i]) ) continue;
     if( enemy[i]->query_temp("weapon") ) {
        flag++;
        if(   !query_temp("weapon") ) {
          command("say " + RANK_D->query_respect(enemy[i]) + "��Ȼʹ���У����¿��ֽ���δ�ⲻ����");
          command("wield sword");
          command("say ���аɣ�");
          break;
        }
     }
   }
   if( !flag && query_temp("weapon") ) {
     if( sizeof(enemy) > 1 )
        command("say ��... ��Ȼ" + chinese_number(sizeof(enemy)) + "λ���ǿ��֣����������㣡");
     else
        command("say ��Ȼ" + RANK_D->query_respect(enemy[0]) + "��ʹ���У�������Ȼ���㣡\n");
     command("unwield sword");
   }
}
