// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
  set_name("����", ({"jinjing shou", "shou"}));
  set("long", "һͷ˫���Ź⣬�����񰰵Ľ��ޡ�\n");
  set("race", "Ұ��");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "��");
  set("ride/dodge", 35);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

