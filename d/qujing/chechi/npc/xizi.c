// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("Ϸ��", ({"xi zi", "zi"}) );
  set("gender", "����" );
  set("age", 35);
  set("long","һλװ�缫Ϊ���صĳ��ٹ�Ϸ�ӡ�\n");

  set("combat_exp", 6500);
  set("str", 25);
  set("attitude","heroism");

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 2);
}

void init()
{
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N��̨�����˼�����\n",
    "$N��������ʲô��\n",
    "$N�ڿ���ʹ��һ��������һ����ͷ���˹�����\n",
    "$N���������дǡ�\n",
    "$Nһ����������̨�ǡ�\n",
    "$N���˸�����\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  call_out("says",random(40),me);
}

