
#include <armor.h>

inherit CROTCH;

void create()
{
    set_name( "��Ƥսȹ", ({ "zhan qun", "qun" }) );
    set_weight(2000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ����Ƥ���Ƶ�սȹ���䲻���£����ܽ�ʵ��\n");
        set("unit", "��");
        set("value", 500);
        set("material", "leather");
        set("armor_prop/armor", 6);
    }
    setup();
}

