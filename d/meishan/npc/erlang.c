// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("�������", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "���ǳ���ѻ�Ӣ��ʥ���Ի��ޱߺŶ��ɡ�
�����˹�����Զ�����÷ɽ��ʥ�С�\n");
   set("looking", "�����忡ò���ã���������Ŀ�й⡣");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "����");
        set("title", "�ѻ�������");
        set("str", 40);
        set("int", 40);
        set("per", 30);
   set("con", 30);
        set("max_kee",2000);
        set("max_sen", 2000);
        set("combat_exp", 1500000);
        set("force", 4000);
        set("max_force", 2000);
        set("mana", 4000);
        set("max_mana", 2000);
        set("force_factor", 150);
        set("mana_factor", 120);

        set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 200);
   set_skill("force", 180);
   set_skill("spells", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("spear", 180);
   set_skill("moyun-shou", 200);
   set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
   map_skill("unarmed", "moyun-shou");
   map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();

}

void die()
{

        if( environment() ) {
        message("sound", "\n\n������ŭ������ĪҪ���񣬴����������״ȥ��\n\n", environment());
        message("sound", "\n��������ϰ��ƣ����������ŷ�ȥ������\n\n", environment());
        }

        destruct(this_object());
}

