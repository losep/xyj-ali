// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("���֮��", ({ "lihuo zhijing", "fire" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "�������ľ������ٻ�һ�еĻ��档\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
        set("elements/fire", 100);
    }

    set_amount(1);
}
