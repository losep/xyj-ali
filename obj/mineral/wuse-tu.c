// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("��ɫ��", ({ "wuse tu", "mud" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "Ů����ﲹ��ʱ���Ƶ���ɫ��ʯ���������������·绯����������ɫ����\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
    }

    set_amount(1);
}
