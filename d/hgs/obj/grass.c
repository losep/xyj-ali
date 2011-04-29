// grass.c

inherit ITEM;

void create()
{
    set_name("С��", ({"grass"}));
    set_weight(10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�������͵�С�ݡ�\n");
        set("unit", "��");
    }
}

void init()
{
    add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    object me = this_player();
    if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
    message_vision("$N������ʳ��ҧ�˼�����ݣ�����ֶ����˳�����\n" , me);
    destruct(this_object());
    return 1;
}
