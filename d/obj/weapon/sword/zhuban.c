// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhuban.c

#include <weapon.h>

inherit SWORD;

void create()
{
   set_name("���", ({ "zhu ban","ban" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 200);
     set("material", "bamboo");
     set("long", "һ��˵�������õ���塣\n");
     set("wield_msg", "$N�ó�һ����壬���˼��£������ʮ�㡣\n");
     set("unwield_msg", "$N��$n����������\n");
   }
   init_sword(10);
   setup();
}
