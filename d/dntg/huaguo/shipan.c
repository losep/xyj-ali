// shipan

inherit ITEM;

void create()
{
    set_name("ʯ��", ({ "shi pan" }));
    set_weight(500);
    set_max_encumbrance(8000);
    if (clonep()) {
        int i;
        object mht;
        
        seteuid(getuid());
        set_default_object(__FILE__);
        
        for (i = 1;i < 10; i++) {
            mht = new("/d/obj/drug/mihoutao");
            mht->move(this_object());
        }
    } else {
        set("unit", "��");
        set("long", "һ��ʯ���ӡ�\n");
        set("no_give", 1);
    }
}

int is_container() { return 1; }
