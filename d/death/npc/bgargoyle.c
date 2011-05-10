// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
string *death_msg = ({
        HIB "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
        HIB "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
        HIB "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
        HIB "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
        HIB "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
                "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
        set_name("���޳�", ({ "black gargoyle", "gargoyle" }) );
        set("long",

"���޳����ų�������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({

"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",

"���޳��ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��\n"
        }) );
   set("per", 100);
   set("str", 25);
   set("int", 20);
        set("age", 217);
   set("class", "ghost");
        set("combat_exp", 120000);
        set("max_kee", 800);
        set("max_sen", 800);
   set("max_gin", 400);
   set("force", 500);
   set("max_force", 500);
   set("force_factor", 20);
   set("max_mana", 500);
   set("mana", 500);
   set("mana_factor", 30);
        set("title", "�ͻ�ʹ��");
        set_temp("apply/damage", 10);
        set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 80);
        set_skill("parry", 70);
     set_skill("keening-stick", 70);
        set_skill("spells", 70);
        set_skill("necromancy", 70);
        set_skill("force", 70);
        set_skill("stick", 70);
        set_skill("tonsillit", 70);
        set_skill("dread-hand", 80);
        map_skill("spells", "necromancy");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
   map_skill("stick", "keening-stick");
   map_skill("parry", "keening-stick");
        map_skill("unarmed", "dread-hand");
   create_family("���޵ظ�", 4, "���");
        setup();
   carry_object("/d/obj/cloth/hei")->wear();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost()) {
     if( visible(ob)&&(string)ob->query("family/family_name")!="���޵ظ�" ){
                   command("say ι��������������ʲô���ѵ��ǻ���������\n");
                   kill_ob(ob);
                    ob->fight_ob(this_object());
                   return;
           }
     return;
   }

        if ((int)ob->query("max_gin") <= 0 ||
            (int)ob->query("max_kee") <= 0 ||
            (int)ob->query("max_sen") <= 0)
                return;

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
     ob->set("gin", (int)ob->query("max_gin"));
        ob->move(REVIVE_ROOM);
        message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}
void attempt_apprentice()
{       object me;
        me = this_player();
        if ( (string)me->query("family/family_name")=="���޵ظ�") {
        if (((int)me->query("combat_exp") < 10000 )) {
        command("say " + RANK_D->query_rude(me) + "���Ļ������ڣ��Ϸ�м���㣡\n");
        return;
        }
        command("grin");
        if(me->is_ghost() ){
        me->reincarnate();
   me->set("gin", (int)me->query("max_gin"));
        }
        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        return;
        }
        command("shake");
        command("say " + RANK_D->query_rude(me) +
"������ȥѧЩ��������ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ghost");
}


