// ALi by NewX

// snshou.c ������

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("������", ({ "suona shou", "shou" }));
   set("long", "�����ǻ����������ֵĴ����֡�\n"
     "����������һֻ���ţ���������������ش��š�\n");
   set("gender", "����");
   set("age", 30);
   set("attitude", "peaceful");
   set("str", 50);
   set("int", 10);
   set("max_kee", 500);
   set("combat_exp", 10000);
   set_skill("force", 30);
   set_skill("dodge", 30);
   set_skill("unarmed", 30);
   set_skill("parry", 30);

   setup();
}
