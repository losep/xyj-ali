// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("��ľ���", ({ "qingmu fenghun", "wood" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "��ľ���������֮���ϵĲ��\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
        set("elements/wood", 100);
    }

    set_amount(1);
}
