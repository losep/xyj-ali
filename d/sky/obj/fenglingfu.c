// ALi by NewX

inherit ITEM;

void create()
{
    set_name("�����", ({"feng ling fu","fu"}));
    set("unit", "��");
    set_weight(10);
    set("long", "һ�ŷ��Ÿ��ĵ��������Ҫ���ʱ���������Կ���(ji)����\n");
    set("no_give", "�����������������ˣ�\n");
    set("no_sell", "�ƹ��ҡҡͷ˵���ⱦ��С�겻���ա�\n");
    setup();
}

void init()
{
    add_action("do_ji", "ji");
}

int do_ji(string arg)
{
    object me = this_player();
    object env;
    
    if (!arg || !id(arg)) return notify_fail("�����ʲô��\n");

    if (me->query("mana") + random(500) < 1000) {
        message_vision("$N�ó�����������һ��������������\n", me);
        message_vision("��ʲôҲû�з�������\n", me);
    } else {
        message_vision("$N�ó�����������һ��������������\n", me);
        message_vision("��ʱ����������ɳ��ʯ��\n", me);
        message_vision("�ۣ���һ����磡\n", me);
        env = environment(me);
        env->weather_effect("wind");
        foreach (object ob in all_inventory(env)) {
            if (ob) ob->weather_effect("wind");
        }
    }
    destruct(this_object());
    return 1;
}
