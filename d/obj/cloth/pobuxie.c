// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//pobuxie.c
#include <armor.h>

inherit BOOTS;

void create()
{
   set_name("�Ʋ�Ь", ({"po buxie", "buxie", "shoes"}));
   set_weight(800);
   if( clonep() ) set_default_object(__FILE__);
   else 
   {
     set("unit", "˫");
     set("material", "cloth");
     set("armor_prop/armor", 1);
   }
   setup();
}

