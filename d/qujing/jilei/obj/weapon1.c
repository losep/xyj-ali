// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("ţͷ��", ({ "niutou dao", "dao", "blade" }) );
  init_blade(35);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 110);
    set("material", "bone");
  }
  setup();
}

