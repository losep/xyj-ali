// ALi by NewX

// huqiu.c ǧ����

#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("ǧ����", ({ "huqiu", "cloth" }) );
   set_weight(1000);
   if (clonep())
       set_default_object(__FILE__);
   else {
       set("long", "һ��ѩ�׵ĺ������ۣ��ʵؼ��ᡣ��˵��Ҹ���ã��ϵȵĺ���ֻ��ȡ��ͨ��ƺ���Ҹ�£�����һ�����ò�֪Ҫ�ռ���������ĺ��á�\n");
       set("unit", "��");
       set("value", 8000);
       set("material", "cloth");
       set("armor_prop/armor", 1);
       set("armor_prop/personality", 5);
       set("female_only", 1);
   }
   setup();
}

