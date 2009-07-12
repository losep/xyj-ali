// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bigaxe.c

#include <weapon.h>

inherit AXE;

void create()
{
   set_name("大板斧", ({ "bigaxe", "axe" }) );
   set_weight(22000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("long", "这是一把沉重的大板斧，砍起东西来非常顺手。\n");
     set("value", 11);
     set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
     set("unwield_msg", "$N放下手中的$n。\n");
   }
   init_axe(11, TWO_HANDED);
   setup();
}
