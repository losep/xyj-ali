// ALI by NewX

inherit COMBINED_ITEM;

void create()
{
    set_name("�����ٸ�", ({ "liuyang wugang", "steel" }));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "���ٸ�����ȡ�ľ������ϣ����м����ս�Լ�ֵ�����ʵ�г�͢ר����\n");
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("is_mineral", 1);
        set("value", 100000);
        set("no_sell", "�����ٸ��ǳ�͢ר�����ʣ�˽�˽�ֹ������");
    }

    set_amount(1);
}
