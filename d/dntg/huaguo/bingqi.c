// bingqi.c

inherit ITEM;

void create()
{
    set_name("����",({"bing qi"}));
    set_weight(20000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long","һ��������������ǹ������ꪡ������ᡢ������\n"
"ʲô���У����涼���м������֣����������ƣ���\n");
        set("unit","��");
    }
}

void init()
{
    object ob = this_object();
    object where = environment();

    if (userp(where)) {
        if (!ob->query("owner"))
            ob->set("owner", where);
        else if (ob->query("owner") != where)
            call_out("destruct_me", 5, ob);
    }
}

void destruct_me(object ob)
{
    if (ob) {
        tell_object(environment(ob), "����������������һ�ء�\n");
        destruct(ob);
    }
}
