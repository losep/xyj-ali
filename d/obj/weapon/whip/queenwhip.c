// sixue
 
// queenwhip.c

#include <weapon.h>

inherit WHIP;

void create()
{
    set_name("Ů��֮��", ({"queenwhip", "whip"}));
    set_weight(1000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long","һ����ڵ�Ƥ�ޣ��ʵغ�������������ϲ�����ôʹ��������������ĸо�\n");
        set("unit", "��");
        set("value", 500);
        set("rigidity", 100);
        set("wave", 100);
    }
    init_whip(1);
    setup();
}

