// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ironarmor.c
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("������", ({"silver armor", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
           set("long", "һ������ӲӵĿ��ף�\n");
                set("value", 8000);
                set("material", "iron");
                set("armor_prop/armor", 45);
     set("armor_prop/dodge", -10);
             }
        setup();
}

