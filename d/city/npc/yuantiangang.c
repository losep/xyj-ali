// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
        set_name("Ԭ���", ({"yuan tiangang", "yuan"}));
        set("gender", "����" );
        set("age", 33);
        set("long","Ԭ��������̨�ܹܣ���˵���������
��Ϊ����ֱ���壬��������һ���ǹ���������顣\n");
        set("int", 30);
   set("per", 25);
        set("combat_exp", 50000);
        set("attitude", "friendly");
   set("title", "���̨������");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 100);
   set_skill("baguazhou", 100);
        set_skill("literate", 50);
        set_skill("sword", 60);  
        set_skill("changquan", 50);  

        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");

        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
   add_money("silver", 5);
        carry_object("/d/obj/cloth/baguapao")->wear();
        carry_object("/d/obj/weapon/sword/taomujian")->wield();
}
int accept_fight(object me)
{
        write("Ԭ�����Ȼ����ѧ������Ϊ��ǿ�����Ǵ��ɱɱ��\n");
        return 0;
}
int recognize_apprentice(object me)
{
        if((int)me->query("yuan-learn"))
        return 1;
        return notify_fail("Ԭ���˵������̫�����ˣ�����ô�ҵ���\n");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="fan he"){
     if (((string)who->query("family/family_name")=="������")){
        who->set("yuan-learn", 1);
        write("Ԭ���Ц��������������һ���˲ţ��Ժ�����ǰ��ͷ֮����
Ԭ�����Ϊ��˼���ֵ����������к����⣬����ʱ�������֣��������֪��������𸴣�\n");
        call_out("destroy", 1, ob);
        return 1;
     }
     if (((string)who->query("family/family_name")!="������")){
        command("say ��л��л�����������ģ�");
        command("give 1 silver to " + who->query("id"));        
        call_out("destroy", 1, ob);
                        return 1;
     }
   }
   else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

