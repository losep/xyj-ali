// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
    set_name("��ֵ����", ({ "yuezhi gongcao", "yue", "month", "gongcao" }));
    set("gender", "����");
    set("long", "
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������Ϊ־ͬ���Ͻ�Ϊ
�����ֵܡ���ֵ���������϶�������ʦ��ׯ�ۣ�һ
������������½�������������ȭ���м������
ּ��\n"
    );
    set("age", 38);
    set("str", 20);
    set("int", 30);
    set("max_kee", 1050);
    set("kee", 1050);
    set("max_sen", 900);
    set("sen", 900);
    set("combat_exp", 550000);
    set("force", 1500);
    set("max_force", 900);
    set("mana", 1450);
    set("max_mana", 850);
    set("force_factor", 60);
    set("mana_factor", 50);

    set("eff_dx", 200000);
    set("nkgain", 340);

    set_skill("unarmed", 110);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("sword", 110);
    set_skill("xiaofeng-sword", 115);
    set_skill("force", 100);
    set_skill("moshenbu", 110);
    set_skill("wuxing-quan", 90);
    set_skill("spells", 100);
    map_skill("unarmed", "wuxing-quan");
    map_skill("dodge", "moshenbu");
    map_skill("parry", "xiaofeng-sword");
    map_skill("sword", "xiaofeng-sword");
    set("inquiry", ([
        "name" : "���¾�����ֵ���ܣ�������������ǰ�󽫡�",
        "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
    ]));
    setup();
    carry_object("/d/obj/weapon/sword/qingfeng")->wield();
    carry_object("/d/obj/armor/yinjia")->wear();
}
