// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dog.c

inherit NPC;

void create()
{
        set_name("���ױ�", ({"hulei bao", "hulei", "horse", "ma"}));
        set("race", "Ұ��");
        set("age", 20);

   set("combat_exp", 10000);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite"}));

   set("ride/msg", "��");
        set("ride/dodge", 18);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 20);

        setup();
}

