// ALi by NewX

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("������ڽ�", ({ "firesword", "huo jian", "sword" }));
    set_weight(400);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 700);
        set("material", "steel");
        set("long", "����һ�Ѻ�ɫ�ĳ���������ƻ�Ҳ��Ѫ��\n");
        set("wield_msg", "$N���һ�ѻ��ĳ������������С�\n");
        set("unequip_msg", "$N�������е�$n��\n");
        set("weapon_prop/courage", 4);
    }
    init_sword(40);
    setup();
}

