
#include <armor.h>

inherit CHEST;

void create()
{
    set_name( "����", ({ "bra" }) );
    set_weight(1000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�����Ըе����֣�����ֻ�ܸ���ס���Σ�\n");
        set("unit", "��");
        set("value", 800);
        set("material", "cloth");
        set("armor_prop/armor", 1);
        set("armor_prop/personality", 2);
        set("female_only", 1);
    }
    setup();
}

