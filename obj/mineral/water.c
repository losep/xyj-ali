// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("��ˮ֮��", ({ "kanshui zhijing", "water" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "��ڤ��ˮ�ľ���������һ�е���������֮ˮ��\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
        set("elements/water", 100);
    }

    set_amount(1);
}
