// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���޳�", ({ "hei wuchang","wuchang", "gargoyle" }));
        set("long","һ�����������Ƥ��ʹ�ߣ���ڵ����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
   set("per", 10);
   set("str", 25);
   set("int", 25);
        set("age", 30);
   set("title", "����˾��");
        set("combat_exp", 150000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
   set("class", "ghost");
   set("force", 1500);
   set("max_force", 800);
   set("force_factor", 50);
   set("max_mana", 600);
   set("mana", 1000);
   set("mana_factor", 40);
   set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
   set_skill("parry", 70);
   set_skill("spells", 70);
   set_skill("necromancy", 60);
   set_skill("jinghun-zhang", 70);
   set_skill("force", 70);
   set_skill("tonsillit", 60);
/*
   set_skill("stick", 100);
   set_skill("kusang-bang", 100);
   map_skill("stick", "kusang-bang");
   map_skill("parry", "kusang-bang");
*/
   map_skill("spells", "necromancy");
   map_skill("dodge", "ghost-steps");
   map_skill("force", "tonsillit");
   map_skill("unarmed", "jinghun-zhang");
create_family("���޵ظ�", 4, "���");

        setup();
   carry_object("/d/obj/cloth/hei")->wear();
}


void attempt_apprentice()
{
   object me;
   me = this_player();
        command("grin");

        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ghost");
}

