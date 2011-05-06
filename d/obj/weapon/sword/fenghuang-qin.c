// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

void create()
{
    set_name("�����", ({"fenghuang qin","qin","sword"}));
    set_weight(4000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�ѵ���ɫ��ϸ����������͸�������洦���ŵ�㺮�⡣\n"
"�������ƺ��и�������װ (install) Щ������ȥ��\n");
        set("unit", "��");
        set("value", 3000);
        set("material", "steel");
        set("wield_msg", "$N��Цһ�����ӱ���γ��˷���١�\n");
        set("unwield_msg", "$N�����еķ���ٲ�����У���Ƕ���һ˿Ц�⡣\n");

        set("anqi/allow", 1);
        set("anqi/max", 50);
        set("anqi/now", 0);
    }
    init_sword(60);
    setup();
}

void init()
{
    add_action("do_install", "install");
    add_action("do_uninstall", "uninstall");
}


int do_install(string arg)
{
    object me = this_object();
    object who = this_player();
    object aq;
    int remain;

    if (!arg) return notify_fail("����װʲô��\n");

    aq = present(arg, who);
    if (!present(arg, who))
        return notify_fail("������û���ⶫ����\n");
    else if (aq == me)
        return notify_fail("�Լ�װ�Լ���\n");
    else if (aq->query("name") != "����" && aq->query("name") != "����" && aq->query("name") != "��ȸ��") 
        return notify_fail("������̫���ˣ�װ����ȥ��\n");
    else if (query("anqi/now") == query("anqi/max"))
        return notify_fail(name()+"�Ѿ�װ�������ˡ�\n");
    else if (query("anqi/now") > 0 && query("anqi/type") != aq->query("name"))
        return notify_fail(name()+"����װ��ͬ�İ�����\n");
    else {
        message_vision("$N��"+name()+"�Ļ��أ���һ"+aq->query("unit")+aq->query("name")+"װ�˽�ȥ��\n", who);
        who->start_busy(3);
        if (query("anqi/now") == 0) {
            me->set("anqi/type", aq->query("name"));
            me->set("anqi/base_unit", aq->query("base_unit"));
        }
        if (query("anqi/now") + aq->query_amount() > query("anqi/max")) {
            remain = query("anqi/now") + aq->query_amount() - query("anqi/max");
            me->set("anqi/now", query("anqi/max"));
            aq->set_amount(remain);
        } else {
            me->set("anqi/now",query("anqi/now") + aq->query_amount());
            destruct(aq);
        }
        return 1;
    }
}

int do_uninstall(string arg)
{
    object ob;
    object me = this_object();
    object who = this_player();
    
    if (!me->id(arg)) return notify_fail("�����ʲô��\n");
    else if (query("anqi/now") == 0) return notify_fail(name()+"����ʲôҲû�С�\n");
    else {
        if (query("anqi/type") == "����") ob = new("/d/obj/weapon/throwing/yinzhen");
        else if (query("anqi/type") == "��ȸ��") ob = new("/d/obj/weapon/throwing/kongque-ling");
        else ob = new("/d/obj/weapon/throwing/yinzhen");
        ob->set_amount(query("anqi/now"));
        ob->move(who);
        me->set("anqi/now", 0);
        message_vision("$N��"+name()+"������һ"+ob->query("unit")+ob->query("name")+"��\n", who);
        who->add_busy(3);
        return 1;
    }
}

string extra_long()
{
    if (!query("anqi/now")) return "";
    else return sprintf("�����Ѿ�װ��%s%s%s��������uninstall��\n",
                    chinese_number(query("anqi/now")), query("anqi/base_unit"), query("anqi/type"));
}
