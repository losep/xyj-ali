// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( GRN "��������" NOR, ({ "houndbane blade", "houndbane", "blade" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѱ���ɫ�Ĺ�ͷ����������������ء�\n");
		set("value", 42000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N��쬡���һ�����һ�ѱ����б���$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("weapon_prop/courage",10);
	}

	init_blade(96);
	setup();
}
