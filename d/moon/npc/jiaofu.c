// ALi by NewX

// jiaofu.c �η�

inherit NPC;

void create()
{
   set_name("�η�", ({ "jiaofu" }));
   set("long", "������ר�Ÿ���̧���εĽη�\n"
     "��������������֣��а���������̧�ǻ�������һ�����ȵ���\n");
   set("gender", "����");
   set("age", 25);
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
