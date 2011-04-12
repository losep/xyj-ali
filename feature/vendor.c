// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// vendor.c

#include <dbase.h>

int is_vendor() { return 1; }

int buy_object(object me, string what)
{
    string ob;

    if (stringp(ob = query("vendor_goods/" + what)))
        return ob->query("value");
    else
        return 0;
}

int complete_trade(object me, string what)
{
    string ob_file;
    object ob;
    int price;

    if (stringp(ob_file = query("vendor_goods/" + what))) {
        ob = new(ob_file);
        if (ob->move(me)) {
            message_vision("$N��$n����һ" + 
                ob->query("unit") + ob->query("name") + "��\n", me, this_object() );
            return 1;
        }
        return notify_fail("û��������������\n");
    }
}

string price_string(int v)
{
    string str="";
    int val;

    val = v / 10000;
    if (val) str += chinese_number(val) + "���ƽ�";
    val = (v % 10000) / 100;
    if (val) str += chinese_number(val) + "������";
    val = (v % 100);
    if (val) str += chinese_number(val) + "��Ǯ";

    if (str=="") str = "����Ǯ";
    return str;
}

int do_vendor_list(string arg)
{
    mapping goods;
    string list, *name;
    int i;
    string tlist;
    
    if (!mapp(goods = query("vendor_goods"))) return 0;
    if (arg && !this_object()->id(arg)) return 0;
    name = keys(goods);
    list = "����Թ���������Щ������\n";
    for (i=0; i<sizeof(name); i++)  {
        tlist = sprintf("%s(%s)", goods[name[i]]->query("name"), name[i]);
        list += sprintf("%-30s��%s\n", tlist,
                    price_string(goods[name[i]]->query("value"))
                );
    }
    write(list);
    return 1;   
}
