// ALI by NewX

// fabao smelter

#include <ansi.h>
#include <weapon.h>
#include <armor.h>

inherit ITEM;

void confirm_recycle(string arg, object ob, object fabao_ob);
void pay(object me, object ob);
void get_new_desc(object ob, string arg);

int is_container() { return 1; }

void create()
{
    set_name("��������¯", ({"fabao smelter", "smelter", "lzl"}));
    set_weight(1000);
    set_max_encumbrance(100000);
    seteuid(getuid());
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", @LONG
һ��С�ɵ���¯������͸�����ص�������
����������֣�ȫ���ǹ������Ʒ����ķ��š�

                  (** ��������ָ�� **)
  �����·���               make_fabao                         
  ����(����)����           recycle                            
  �鿴��������/��������    cost                               
  ����                     upgrade <prop>                     
  ����ǿ��                 enhance                            
                                                              
  �������Ĵ���             change_id <fabao_id> <new id>      
  ����������               change_name <fabao_id> <new name>  
  ������������             change_desc <fabao_id> <new desc>  
  �������ĵ�λ����         change_unit <fabao_id> <new unit>  
  ��ӡ���ܣ�����ר�ã�     seal <fabao_id>                    
  �⿪��ӡ������ר�ã�     unseal <fabao_id>                  
LONG);
        set("material", "bronze");
        set("value", 1000000);
        set("no_sell", 1);
    }

    setup();
}

void set_owner(object who)
{
    set_temp("owner", who);
    who->set_temp("smelter", this_object());
    set("name", "��" + who->name(1) + "���ķ�������¯");
}

void reset()
{
    object owner = query_temp("owner");
    object env = environment();
    if (!env || !owner) {
        destruct(this_object());
        return;
    }
    if (env != owner && env != environment(owner)) {
        tell_room(env, name() + "��Ȼ����һ�����������Զ����\n");
        destruct(this_object());
        return;
    }
}

void init()
{
    add_action("do_make", "make_fabao");
    add_action("do_recycle", "recycle");
    add_action("do_cost", "cost");
    add_action("do_upgrade", "upgrade");
    add_action("do_enhance", "enhance");
    add_action("do_change_name", "change_name");
    add_action("do_change_id", "change_id");
    add_action("do_change_desc", "change_desc");
    add_action("do_change_unit", "change_unit");
    add_action("do_seal", "seal");
    add_action("do_unseal", "unseal");
}

int do_make()
{
    if (!FABAO_D->varify_formula("", this_object()))
        return 0;
    if (!FABAO_D->varify_player("", this_player(), this_object()))
        return 0;
    
    FABAO_D->start_make_fabao(this_player(), this_object());
    return 1;   
}

void complete_make_fabao(object ob)
{
    string fabao_type;
    object fabao_ob;
    
    fabao_ob = FABAO_D->new_fabao_ob(ob);
    if (!fabao_ob) {
        write("�������󴴽�ʧ�ܡ�\n");
        return;
    }

    fabao_ob->setup();

    ob->set("fabao/" + ob->query_temp("fabao_new"),
        fabao_ob->query("series_no"));

    pay(ob, fabao_ob);

    if (!fabao_ob->move(this_object()))
        if (!fabao_ob->move(ob))
            fabao_ob->move(environment(ob));

    fabao_ob->save();
    ob->save();
    
    tell_room(environment(ob), HIY "����к�Ȼӿ��һ�����ƣ���Լ���������ִ�������ϸһ����ԭ����"
            + ob->name() + "���Ƴ���һ" + fabao_ob->query("unit") + fabao_ob->query("name") + HIY "��\n" NOR, ob);
    tell_object(ob, HIY "����к�Ȼӿ��һ�����ƣ���Լ���������ִ����������Ƴ���һ"
            + fabao_ob->query("unit") + fabao_ob->query("name") + HIY "��\n" NOR);
}

int do_recycle()
{
    object me = this_player();
    object fabao_ob = first_inventory();
    
    if (!objectp(fabao_ob))
        return notify_fail("���ȷ��뷨��������������ָ�\n");
    if (objectp(next_inventory(fabao_ob)))
        return notify_fail("��ֻ���뷨������Ҫ����������Ʒ��\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no"))
        return notify_fail("�ⲻ�Ƿ���Ү��\n");

    printf("%s\n%s", fabao_ob->short(), fabao_ob->long());
    printf("------------------------------------------------\n");
    printf("%s�������̺���������%s(������������Եõ����е�75%%)\n%s", YEL, HIR, NOR);
    printf("%s������ %s%d%s\t", YEL, HIG, fabao_ob->query("power/force"), NOR);
    printf("%s������ %s%d%s\t", YEL, HIG, fabao_ob->query("power/mana"), NOR);
    printf("%s���У� %s%s%s\n", YEL, HIG, COMBAT_D->chinese_daoxing(fabao_ob->query("power/exp")), NOR);
    write("��ȷ��Ҫ�������������(y/n)");
    input_to( (: confirm_recycle, me, fabao_ob :) );
    return 1;
}

void confirm_recycle(object ob, object fabao_ob, string arg)
{
    int i, series, moving = 0;
    string type;
    
    if (arg != "y" && arg != "Y") {
        write("OK, �Ǿ����ˡ�\n");
        return;
    }
    
    type = fabao_ob->query("fabao_type");
    for (i = 1; series = ob->query("fabao/" + type + i); i++) {
        if (fabao_ob->query("series_no") == series) {
            //seteuid(getuid(ob));
            //rm( fabao_ob->query_save_file() + __SAVE_EXTENSION__ );
            ob->add("max_force", fabao_ob->query("power/force"));
            ob->add("max_mana", fabao_ob->query("power/mana"));
            ob->add("combat_exp", fabao_ob->query("power/exp"));
            ob->delete("fabao/" + type + i);
            moving = 1;
        }
        else if (moving) {
            ob->set("fabao/" + type + (i - 1), ob->query("fabao/" + type + i));
            ob->delete("fabao/" + type + i);
        }
    }
    ob->save();
    tell_room(environment(ob), "��ɫͻȻһ������Լ���ƺ���������Ŀ�����ԭ������"
        + ob->name() + "������" + fabao_ob->name() + "������������������ʵ��������\n", ({ ob }));
    printf("��������%s�������%d��������%d�㷨����%s���С�\n",
        fabao_ob->name(),
        fabao_ob->query("power/force"),
        fabao_ob->query("power/mana"),
        COMBAT_D->chinese_daoxing(fabao_ob->query("power/exp")));
    destruct(fabao_ob);
}

int do_cost(string arg)
{
    object fabao_ob, me = this_player();
    
    foreach (object ob in all_inventory()) {
        if (ob->query("owner_id") && ob->query("series_no")) {
            if (objectp(fabao_ob))
                return notify_fail("�㵽����鿴��һ���������������ѡ�\n");
            fabao_ob = ob;
        }
    }
    
    FABAO_D->show_upgrade_cost(fabao_ob, me);
    return 1;
}

int do_upgrade(string arg)
{
    object me = this_player(), ob = this_object(), fabao_ob;
    int   upgraded;
    
    if (!arg || arg == "")
        return notify_fail("��ѷ�����������¯�ڣ��� upgrade <����> ���������������Կ���cost�鿴��\n");

    if (!FABAO_D->varify_formula(arg, ob))
        return 0;
    
    if (!FABAO_D->varify_player(arg, me, ob))
        return 0;
    
    fabao_ob = ob->query_temp("fabao_ob");
    
    pay(me, fabao_ob);
    
    upgraded = fabao_ob->add("upgraded/" + arg, 1);
    if (upgraded == 5) {
        fabao_ob->add("stars/" + arg, 1);
        fabao_ob->set("upgraded/" + arg, 0);
    }
    tell_room(environment(ob), HIY + name() + HIY "�Ϻ�Ȼ������һ�������̣����е�"
        + fabao_ob->name() + HIY "ɢ����ǿ�����Ϣ��\n" NOR, me);
    tell_object(me, HIG "��������¯��ͻȻ����������������������ڵ�����ǿ�г�ȡ��һ���֣����㲻������ѣ�Ρ�����\n"
        "�����㲢û�о��ţ������о����˷ܡ�\n"
        "��Ϊ������ĸо���¯�е�" + fabao_ob->name() + HIG "�䡺"
        + query_temp("upgraded_prop") + HIG "(" + arg +")��������ǿ��\n" NOR);
    
    fabao_ob->setup();
    fabao_ob->save();
    me->save(); 

    return 1;
}

int do_enhance()
{
    object me = this_player(), ob = this_object(), fabao_ob;
    string fabao_type, elem_type, elem_name;
    int elem_point;

    if (!FABAO_D->varify_formula("enhance", ob))
        return 0;
    
    if (!FABAO_D->varify_player("enhance", me, ob))
        return 0;
    
    fabao_ob = ob->query_temp("fabao_ob");
    fabao_type = fabao_ob->query("fabao_type");
    
    pay(me, fabao_ob);
    
    elem_type = query_temp("enhance/type");
    elem_point = query_temp("enhance/point");
    elem_name = query_temp("enhance/name");
    
    fabao_ob->add(fabao_type + "_prop/" + elem_type, elem_point);
    tell_room(environment(ob), HIY + name() + HIY "�Ϻ�Ȼ������һ�������̣����е�"
        + fabao_ob->name() + HIY "ɢ����ǿ�����Ϣ��\n" NOR, me);
    tell_object(me, HIG "��������¯�Ϻ�Ȼ������һ�������̣����еĲ��Ͻ�������" + fabao_ob->name() + HIG "�С�\n"
        "������ĸо���" + fabao_ob->name() + HIG "�ġ�" + elem_name + HIG "������������ǿ�ˡ�\n" NOR);
    
    fabao_ob->setup();
    fabao_ob->save();
    me->save(); 
    
    return 1;
}

void pay(object me, object ob)
{
    mapping my_costs;
    
    if (mapp(my_costs = me->query_temp("fabaod"))) {
        foreach (string prop in keys(my_costs)) {
            me->add(prop, -(int)my_costs[prop]);
            ob->add("power/" + prop, (int)my_costs[prop]);
        }
    }
    me->delete_temp("fabaod");
    
    foreach (object m in all_inventory())
        if (m != ob) {
            message_vision(name() + "����һ�������̣����е�" + m->name() + "�ڻ��ˡ�\n\n", me);
            destruct(m);
        }
}

int do_change_id(string arg)
{
    string name, newname;
    object fabao_ob, me = this_player();
    string *id_list, *t_list;
    
    if (!arg || arg == "") 
        return notify_fail("���� change_id ���� ��Ӣ���� ��������\n");
    if (sscanf(arg, "%s %s", name, newname) != 2)
        return notify_fail("���� change_id ���� ��Ӣ���� ��������\n");
    if (!objectp(fabao_ob = present(name, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
        return notify_fail("�Ǹ����Ƿ���Ү��\n");
    if (fabao_ob->query("equipped"))
        return notify_fail("�������·������ܸ�����\n");
    if (!LOGIN_D->check_legal_id(newname, 20, 1)) return 1;
    
    newname = replace_string(newname, " ", "_"); 
    fabao_ob->set("id", newname);
    
    id_list = ({ newname });
    t_list = explode(newname, "_");
    if (sizeof(t_list) > 1) {
        id_list += t_list;
    }
    fabao_ob->set_name(fabao_ob->query("name"), id_list); 
    fabao_ob->save();
    
    write("�Ķ��ɹ���\n");
    return 1;
}

int do_change_name(string arg)
{
    string id, newname;
    object fabao_ob, me = this_player();
    
    if (!arg || arg == "") 
        return notify_fail("���� change_name ���� �������� ��������\n");
    if (sscanf(arg, "%s %s", id, newname) != 2)
        return notify_fail("���� change_name ���� �������� ��������\n");
    if (!objectp(fabao_ob = present(id, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
        return notify_fail("�Ǹ����Ƿ���Ү��\n");
    if (fabao_ob->query("equipped"))
        return notify_fail("�������·������ܸ�����\n");
    
    newname += "$NOR$";
    arg = newname;

    arg = replace_string(arg, "$BLK$", "");
    arg = replace_string(arg, "$RED$", "");
    arg = replace_string(arg, "$GRN$", "");
    arg = replace_string(arg, "$YEL$", "");
    arg = replace_string(arg, "$BLU$", "");
    arg = replace_string(arg, "$MAG$", "");
    arg = replace_string(arg, "$CYN$", "");
    arg = replace_string(arg, "$WHT$", "");
    arg = replace_string(arg, "$HIR$", "");
    arg = replace_string(arg, "$HIG$", "");
    arg = replace_string(arg, "$HIY$", "");
    arg = replace_string(arg, "$HIB$", "");
    arg = replace_string(arg, "$HIM$", "");
    arg = replace_string(arg, "$HIC$", "");
    arg = replace_string(arg, "$HIW$", "");
    arg = replace_string(arg, "$NOR$", "");
    
    if (!LOGIN_D->check_legal_name(arg, 12)) return 1; 
    
    arg = newname;
    
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);
    
    fabao_ob->set("name", arg);
    fabao_ob->save();     
    
    write("�Ķ��ɹ���\n");
    return 1;
}

int do_change_desc(string arg)
{
    string id, desc;
    object fabao_ob, me = this_player();
    
    if (!arg || arg == "") 
        return notify_fail("���� change_desc ���� ������ ���޸�������\n");
    if (sscanf(arg, "%s %s", id, desc) != 2)
        return notify_fail("���� change_desc ���� ������ ���޸�������\n");
    if (!objectp(fabao_ob = present(id, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
        return notify_fail("�Ǹ����Ƿ���Ү��\n");
    if (fabao_ob->query("equipped"))
        return notify_fail("�������·������ܸ�����\n");
    
    fabao_ob->set("long", desc);
    fabao_ob->save();
    
    write("�Ķ��ɹ���\n");
}

int do_change_unit(string arg)
{
    string name, newname;
    object fabao_ob, me = this_player();
    
    if (!arg || arg == "") 
        return notify_fail("���� change_unit ���� ��λ ��ָ��������λ��\n");
    if (sscanf(arg, "%s %s", name, newname) != 2)
        return notify_fail("���� change_unit ���� ��λ ��ָ��������λ��\n");
    if (!objectp(fabao_ob = present(name, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
        return notify_fail("�Ǹ����Ƿ���Ү��\n");
    if (fabao_ob->query("equipped"))
        return notify_fail("�������·������ܸ�����\n");
    
    if (!LOGIN_D->check_legal_name(newname, 2)) return 1;
    
    fabao_ob->set("unit", newname);
    fabao_ob->save();
    
    write("�Ķ��ɹ���\n");
    return 1;
}

int do_seal(string arg)
{
    int equipped = 0;
    object fabao_ob, me = this_player();
    
    if (!arg || arg == "") 
        return notify_fail("��Ҫ��ӡ��һ��������\n");
    if (!objectp(fabao_ob = present(arg, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no"))
        return notify_fail("�Ǹ����Ƿ���Ү��\n");
    if (fabao_ob->query("fabao_type") != "weapon")
        return notify_fail("����������ܷ�ӡ��\n");
    if (fabao_ob->query("seal"))
        return notify_fail("��������Ѿ�����ӡ�ˡ�\n");

    if (equipped = fabao_ob->query("equipped"))
        fabao_ob->unequip();
    fabao_ob->set("seal", 1);
    FABAO_D->build_weapon(fabao_ob);
    message_vision("$N����" + name() + "�ϵ���������һ�����\n��ʱ��"
            + fabao_ob->name() + "�Ϸ�����һ�㵭���Ĺ⣬���ֻ������Ϣ��ʧ�ˡ�\n",
        me);
    fabao_ob->save();
    if (equipped)
        fabao_ob->wield();
    return 1;
}

int do_unseal(string arg)
{
    int equipped = 0;
    object fabao_ob, me = this_player();
    
    if (!arg || arg == "") 
        return notify_fail("��Ҫ��ӡ��һ��������\n");
    if (!objectp(fabao_ob = present(arg, me)))
        return notify_fail("������û��������������\n");
    if (!fabao_ob->query("owner_id") || !fabao_ob->query("series_no"))
        return notify_fail("�����Ʒ���Ƿ�����\n");
    if (fabao_ob->query("fabao_type") != "weapon")
        return notify_fail("����������ܷ�ӡ��\n");
    if (!fabao_ob->query("seal"))
        return notify_fail("�������û�б���ӡ����\n");

    if (equipped = fabao_ob->query("equipped"))
        fabao_ob->unequip();
    fabao_ob->delete("seal");
    FABAO_D->build_weapon(fabao_ob);
    message_vision("$N����" + name() + "�ϵ���������һ�����\n��ʱ��"
            + fabao_ob->name() + "�Ϸ����ҫ�۵Ĺ�â��һ�ɻ������Ϣ���������\n",
        me);
    fabao_ob->save();
    if (equipped)
        fabao_ob->wield();
    return 1;
}
