// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// snowcat 4/25/97

#include <weapon.h>

inherit THROWING;

void create()
{
  set_name("���ɰ��", ({"jindan sha", "sha"}));
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һЩ��������Ľ�ɰ��\n");
    set("unit", "Щ");
    set("base_unit", "��");
    set("base_weight", 40);
    set("base_value", 1);
  }
  set("is_monitored",1);
  set_amount(18);
  set("rigidity",100);
  init_throwing(500);
  setup();
}

