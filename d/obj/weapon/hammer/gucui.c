// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("�സ", ({"luochui", "hammer"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        init_hammer(1);
        setup();
}

