// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
void create()
{
  set_name("������", ({"tie long", "long"}));
  set_weight(2800000);
  set("long", "һ����������\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_get", 1);
    set("unit", "��");
    set("material", "stone");
    set("value", 2000);
    set("no_sell", 1);
  }
  setup();
}

