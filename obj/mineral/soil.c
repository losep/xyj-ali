// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("����֮��", ({ "wutu zhiling", "soil" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "����Ԫ�صľ���������һ�е�������\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
        set("elements/soil", 100);
    }

    set_amount(1);
}
