// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

// huangtong-key.c 

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY "��ͭԿ��" NOR, ({"huangtong key", "key"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "һ�ѻ�ͭԿ�ס�\n");
   }
  
   set("is_monitored",1);
   setup();
}


