// ALi by NewX

inherit NPC;
void create()
{
   set_name("С��ʿ", ({"xiao daoshi", "daoshi"}));
   //set("title", "");
   set("gender", "����" );
   set("age", 16);
   set("long", "һ�������С��ʿ��\n");
   set("class", "xian");
   set("combat_exp", 100);
   set("attitude", "peaceful");

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
}
