// ALi by NewX

// jftou.c �η�ͷ
#include <ansi.h>

inherit NPC;

void create()
{
   set_name("�η�ͷ", ({ "jiaofu tou", "tou" }));
   set("long", "���ǽη�ͷ������̧�����⣬����������Ӷ������\n"
     "������������ǿ�ɣ��е�����ͷ�Ե����ӣ�����Ҳ��С��\n");
   set("gender", "����");
   set("age", 30);
   set("attitude", "peaceful");
   set("str", 80);
   set("int", 10);
   set("max_kee", 600);
   set("combat_exp", 10000);
   set_skill("force", 30);
   set_skill("dodge", 30);
   set_skill("unarmed", 30);
   set_skill("parry", 30);
   setup();
}
