// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void setup()
{}

void init()
{
  add_action("do_eat", "eat");
}

void create()
{
  set_name("��Ƿ�", ({"jingu fen", "fen"}));
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ������ɫ��ҩ�ۡ�\n");
    set("value", 3000);
    set("drug_type", "��ҩ");
  }
  setup();
}

int do_eat(string arg)
{
  if (arg != "jingu fen" && arg != "fen")
    return 0;

  if ((int)this_player()->query("eff_kee") == 
    (int)this_player()->query("max_kee"))
    return notify_fail("�����ڲ���Ҫ�ý�Ƿۡ�\n");
  else {
    this_player()->receive_curing("kee", 40+random(10));
    message_vision("$N����һ����Ƿۣ���ʱ����һ���Ⱥ���\n",this_player());
    destruct(this_object());
    return 1;
  }
}

