// ALI by NewX

// /adm/daemons/fabaod.c

#include <weapon.h>
#include <armor.h>
#include <ansi.h>
#include <login.h>

inherit F_DBASE;

#define MAX_WEAPON  1
#define MAX_ARMOR   4

mapping upgrades = ([
    "weapon" : ([
        "damage" : ({
            ([ "val" : 4, "min_exp" : 100000, "min_force": 500, "force" : 10, "exp" : 200 ]),
            ([ "val" : 6, "min_exp" : 500000, "min_force": 1000, "force" : 20, "exp" : 2000 ]),
            ([ "val" : 6, "min_exp" : 1000000, "min_force": 1500, "force" : 30, "exp" : 4000 ]),
            ([ "val" : 6, "min_exp" : 1500000, "min_force": 2000, "force" : 40, "exp" : 10000 ]),
            ([ "val" : 6, "min_exp" : 3000000, "min_force": 4000, "force" : 50, "exp" : 20000 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_force": 8000, "force" : 0, "exp" : 0 ])
        })
    ]),
    "armor" : ([
        "armor" : ({
            ([ "val" : 1, "min_exp" : 100000, "min_force": 500, "force" : 10, "exp" : 200 ]),
            ([ "val" : 2, "min_exp" : 500000, "min_force": 1000, "force" : 20, "exp" : 1000 ]),
            ([ "val" : 3, "min_exp" : 1000000, "min_force": 1500, "force" : 30, "exp" : 4000 ]),
            ([ "val" : 4, "min_exp" : 1500000, "min_force": 2000, "force" : 40, "exp" : 10000 ]),
            ([ "val" : 5, "min_exp" : 3000000, "min_force": 4000, "force" : 50, "exp" : 20000 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_force": 8000, "force" : 0, "exp" : 0 ])
        }),
        "dodge" : ({
            ([ "val" : 1, "min_exp" : 200000, "exp" : 1000 ]),
            ([ "val" : 1, "min_exp" : 500000, "exp" : 4000 ]),
            ([ "val" : 2, "min_exp" : 1000000, "exp" : 10000 ]),
            ([ "val" : 2, "min_exp" : 1500000, "exp" : 20000 ]),
            ([ "val" : 3, "min_exp" : 3000000, "exp" : 40000 ]),
            ([ "val" : 0, "min_exp" : 9000000, "exp" : 0 ])
        }),
        "force" : ({
            ([ "val" : 1, "min_exp" : 200000, "min_force": 500, "force" : 10, "exp" : 1000 ]),
            ([ "val" : 1, "min_exp" : 500000, "min_force": 1000, "force" : 20, "exp" : 4000 ]),
            ([ "val" : 2, "min_exp" : 1000000, "min_force": 1500, "force" : 30, "exp" : 10000 ]),
            ([ "val" : 2, "min_exp" : 1500000, "min_force": 2000, "force" : 40, "exp" : 20000 ]),
            ([ "val" : 3, "min_exp" : 3000000, "min_force": 4000, "force" : 50, "exp" : 40000 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_force": 8000, "force" : 0, "exp" : 0 ])
        }),
        "armor_vs_force" : ({
            ([ "val" : 10, "min_exp" : 100000, "min_force": 500, "force" : 20 ]),
            ([ "val" : 20, "min_exp" : 500000, "min_force": 1000, "force" : 30 ]),
            ([ "val" : 30, "min_exp" : 1000000, "min_force": 1500, "force" : 50 ]),
            ([ "val" : 40, "min_exp" : 1500000, "min_force": 2000, "force" : 80 ]),
            ([ "val" : 50, "min_exp" : 3000000, "min_force": 4000, "force" : 200 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_force": 8000, "force" : 0 ])
        }),
        "spells" : ({
            ([ "val" : 1, "min_exp" : 200000, "min_mana": 500, "mana" : 10, "exp" : 1000 ]),
            ([ "val" : 1, "min_exp" : 500000, "min_mana": 1000, "mana" : 20, "exp" : 4000 ]),
            ([ "val" : 2, "min_exp" : 1000000, "min_mana": 1500, "mana" : 30, "exp" : 10000 ]),
            ([ "val" : 2, "min_exp" : 1500000, "min_mana": 2000, "mana" : 40, "exp" : 20000 ]),
            ([ "val" : 3, "min_exp" : 3000000, "min_mana": 4000, "mana" : 50, "exp" : 40000 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_mana": 8000, "mana" : 0, "exp" : 0 ])
        }),
        "armor_vs_spells" : ({
            ([ "val" : 10, "min_exp" : 200000, "min_mana": 500, "mana" : 10 ]),
            ([ "val" : 20, "min_exp" : 500000, "min_mana": 1000, "mana" : 30 ]),
            ([ "val" : 30, "min_exp" : 1000000, "min_mana": 1500, "mana" : 60 ]),
            ([ "val" : 40, "min_exp" : 1500000, "min_mana": 2000, "mana" : 100 ]),
            ([ "val" : 50, "min_exp" : 3000000, "min_mana": 4000, "mana" : 250 ]),
            ([ "val" : 0, "min_exp" : 9000000, "min_mana": 8000, "mana" : 0 ])
        })
    ])
]);

mapping props = ([
    "weapon" : ({
        ([ "id": "damage", "name" : HIG "�� �� ��" NOR, "init_val" : 10 ])
    }),
    "armor" : ({
        ([ "id" : "armor", "name" : HIG "�� �� ��" NOR, "init_val" : 5 ]),
        ([ "id" : "dodge", "name" : HIY "�Ṧ�ӳ�" NOR ]),
        ([ "id" : "force", "name" : HIB "�ڹ��ӳ�" NOR ]),
        ([ "id" : "armor_vs_force", "name" : HIM "��������" NOR ]),
        ([ "id" : "spells", "name" : HIC "�����ӳ�" NOR ]),
        ([ "id" : "armor_vs_spells", "name" : HIW "��������" NOR ]),
    })
]);

mapping subtypes = ([
    "weapon" : ({
        ([ "id" : "axe", "name" : "��", "default_file" : "axe/bigaxe" ]),
        ([ "id" : "blade", "name" : "��", "default_file" : "blade/blade" ]),
        ([ "id" : "fork", "name" : "��", "default_file" : "fork/gangcha" ]),
        ([ "id" : "hammer", "name" : "��", "default_file" : "hammer/hammer" ]),
        ([ "id" : "mace", "name" : "�", "default_file" : "mace/ironmace" ]),
        ([ "id" : "spear", "name" : "ǹ", "default_file" : "spear/gangqiang" ]),
        ([ "id" : "staff", "name" : "��", "default_file" : "staff/muzhang" ]),
        ([ "id" : "stick", "name" : "��", "default_file" : "stick/qimeigun" ]),
        ([ "id" : "sword", "name" : "��", "default_file" : "sword/changjian" ]),
        ([ "id" : "whip", "name" : "��", "default_file" : "whip/pibian" ])
    }),
    "armor" : ({
        ([ "id" : "armor", "name" : "����", "default_file" : "armor/tenjia" ]),
        ([ "id" : "cloth", "name" : "�·�", "default_file" : "cloth/linen" ]),
        ([ "id" : "head", "name" : "ñ��", "default_file" : "cloth/hat" ]),
        ([ "id" : "waist", "name" : "����", "default_file" : "cloth/belt" ]),
        ([ "id" : "surcoat", "name" : "����", "default_file" : "cloth/surcoat" ]),
        ([ "id" : "wrists", "name" : "����", "default_file" : "cloth/wrists" ]),
        ([ "id" : "hands", "name" : "����", "default_file" : "cloth/gloves" ]),
        ([ "id" : "boots", "name" : "ѥ��", "default_file" : "cloth/buxie" ]),
        ([ "id" : "shield", "name" : "����", "default_file" : "armor/niupi" ]),
        ([ "id" : "finger", "name" : "��ָ", "default_file" : "cloth/ring" ]),
        ([ "id" : "neck", "name" : "����", "default_file" : "cloth/necklece" ]),
    })
]);

mapping minerals = ([ "wuse tu" : "��ɫ��", "jiuyin xuantie" : "��������", "wuse tu" : "�����ٸ�" ]);

mapping elements = ([ "gold" : "��", "wood" : "ľ", "water" : "ˮ", "fire" : "��", "soil" : "��" ]);

mapping formulas = ([
    "" : ([
        "" : ([ "wuse tu" : 1, "jiuyin xuantie": 1, "liuyang wugang" : 1 ]),
    ]),
    "weapon" : ([
        "damage" : ([ ])
    ]),
    "armor" : ([
        "armor" : ([ ]),
        "dodge" : ([ ]),
        "force" : ([ ]),
        "armor_vs_force" : ([ ]),
        "spells" : ([ ]),
        "armor_vs_spells" : ([ ])
    ])
]);

string display_stars(int stars);

void get_fabao_type(object ob, object smelter, string arg);
void get_fabao_subtype(object ob, object smelter, string arg);
void get_fabao_id(object ob, object smelter, string arg);
void get_fabao_name(object ob, object smelter, string arg);
void get_fabao_desc(object ob, object smelter, string arg);
void get_fabao_unit(object ob, object smelter, string arg);

object new_fabao_ob(object ob);

void build_weapon(object ob);
void build_armor(object ob);
void setup_prop(object ob, string type);

int count_fabao(object me, string type);
int max_series_no(object me);

mixed query_prop(string fabao_type, string prop);
string show_subtypes(string fabao_type);

void create()
{
    seteuid(getuid());
    set("channel_id", "��������");
    set("id", "fabaod");
}

void show_upgrade_cost(object ob, object me)
{
    string fabao_type;
    string str;
    
    if (!objectp(ob)) {
        write("����������ָ�ϡ�\n");
        write("\n");
        write("��ʼ���ƣ�\n");
        write("���ϣ���ɫ�������������������ٸ�\n");
        write("Ҫ�󣺵��д���20�꣬������������300\n");
        write("���ѣ�����50�㣬����50��\n");
        return;
    }
    
    fabao_type = ob->query("fabao_type");
    
    str = ob->name() + "\n" + ob->long() + "\n";
    foreach (mapping prop in props[fabao_type]) {
        int stars = ob->query("stars/" + prop["id"]);
        int upgraded = ob->query("upgraded/" + prop["id"]);
        if (stars == 5)
            str += (prop["name"] + "(" + prop["id"] + ")����������\n"HIC"    �Ѿ��ﵽ�˶�����\n"NOR);
        else {
            mapping *costs = upgrades[fabao_type][prop["id"]];
            int min_exp = costs[stars]["min_exp"]
                    + (costs[stars + 1]["min_exp"] - costs[stars]["min_exp"]) * upgraded / 5;
            int min_force = costs[stars]["min_force"];
            int min_mana = costs[stars]["min_mana"];
            int force = costs[stars]["force"];
            int mana = costs[stars]["mana"];
            int exp = costs[stars]["exp"];
            
            str += (prop["name"] + "(" + prop["id"] + ")����������");
            if (min_exp <= me->query("combat_exp")
            &&  min_force <= me->query("max_force")
            &&  min_mana <= me->query("max_mana"))
                str += (HIY"������������"NOR);
            str += ("\n");
            if (min_exp > 0) str += ("    ����" + COMBAT_D->chinese_daoxing(min_exp) + "����\n");
            if (min_force > 0) str += ("    ����" + chinese_number(min_force) + "����\n");
            if (min_mana > 0) str += ("    ����" + chinese_number(min_mana) + "����\n");
            if (force > 0) str += ("    �����������" + chinese_number(force) + "��\n");
            if (mana > 0) str += ("    ���������" + chinese_number(mana) + "��\n");
            if (exp > 0) str += ("    ���ĵ���" + COMBAT_D->chinese_daoxing(exp) + "\n");
        }
    }
    {
        int f_stars = ob->query("stars/" + props[fabao_type][0]["id"]);
        string *comp = ({}), *zero = ({});
        foreach (string elem in keys(elements)) {
            int points = ob->query(ob->query("fabao_type") + "_prop/" + elem);
            if (points >= 100)
                comp += ({ elem });
            else if (points <= 0)
                zero += ({ elem });
        }
        str += ("�������ԣ�\n");
        foreach (string elem in keys(elements)) {
            str += ("    " + elements[elem] + "�� ");
            if (member_array(elem, comp) != -1)
                str += (HIY"Բ��"NOR);
            else if (member_array(elem, zero) != -1) {
                if (sizeof(comp) < f_stars
                &&  (sizeof(comp) + sizeof(zero)) == 5)
                    str += (HIG"������"NOR);
                else
                    str += (CYN"��"NOR);
            }
            else
                str += (HIR"������"NOR);
            str += ("\n");
        }
        str += "\n";
        str += "�����������Ե�ǿ��(enhance)����Ҫ��������֮����\n";
        str += "����֮��������\n";
        str += "    ���֮������ˮ֮�����׽����ǣ���ľ��꣬����֮�顣\n";
    }
    me->start_more(str);
}

string show_fabao_status(object ob)
{
    string str = "";
    string fabao_type = ob->query("fabao_type");
    mapping *my_props;
    
    if (!arrayp(my_props = props[fabao_type]))
        return "";

    for (int i = 0; i < sizeof(my_props); i++) {
        mapping prop = my_props[i];
        int stars = ob->query("stars/" + prop["id"]);
        str += prop["name"] + "       ";
        str += display_stars(stars) + "    ";
        if (i % 2 != 0) str += "\n";
    }
    
    if (fabao_type == "weapon")
        str += NOR"�����˺�       ";
    else if (fabao_type == "armor")
        str += NOR"���Է���       ";
    str += sprintf("%s��%sľ%sˮ%s��%s��%s\n",
        ob->query(fabao_type + "_prop/gold") ? HIW : WHT,
        ob->query(fabao_type + "_prop/wood") ? HIG : GRN,
        ob->query(fabao_type + "_prop/water") ? HIB : BLU,
        ob->query(fabao_type + "_prop/fire") ? HIR : RED,
        ob->query(fabao_type + "_prop/soil") ? HIY : YEL,
        NOR);
    
    if (fabao_type == "weapon") {
        int subtype_zero, subtype;
        
        subtype_zero = ob->query("fabao_subtype/0");
        str += HIB "��    ̬       " NOR;
        for (int j = 1; subtype = ob->query("fabao_subtype/" + j); j++) {
            if (subtype == subtype_zero) str += HIY;
            else str += YEL;
            str += subtypes["weapon"][subtype - 1]["name"] + " " NOR;
        }
        str += NOR "\n";
    }
    return str;
}

string display_stars(int stars)
{
    return sprintf("%s%s%s%s%s%s%s", HIR,
                stars > 0 ? "��" : "��",
                stars > 1 ? "��" : "��",
                stars > 2 ? "��" : "��",
                stars > 3 ? "��" : "��",
                stars > 4 ? "��" : "��",
                NOR);
}

int varify_formula(string formula_type, object smelter)
{
    object fabao_ob;
    mapping minerals_ob = ([]), elements_ob = ([]);

    foreach (object ob in all_inventory(smelter)) {
        if (ob->query("owner_id") && ob->query("series_no")) {
            if (objectp(fabao_ob))
                return notify_fail("�㵽����ǿ����һ��������\n");
            fabao_ob = ob;
        }
        else if (!ob->query("is_mineral"))
            return notify_fail("���������ʣ������޷����С�\n");
        else {
            mapping element_prop;
            if (!mapp(element_prop = ob->query("elements")))
                minerals_ob += ([ ob->query("id") : ob ]);
            else {
                foreach (string elem in keys(element_prop)) {
                    if (undefinedp(elements_ob[elem]))
                        elements_ob[elem] = ({});
                    elements_ob[elem] += ({ ob });
                }
            }
        }
    }
    
    if (formula_type != "" && !objectp(fabao_ob))
        return notify_fail("��û�з��뷨����\n");
    
    if (formula_type == "enhance") {
        string half, *zero = ({}), enhance_type;
        string fabao_type = fabao_ob->query("fabao_type");
        int stars, comp = 0, enhance_point = 0;
        
        if (sizeof(minerals_ob))
            return notify_fail("���������ʣ������޷����С�\n");
        if (!sizeof(elements_ob))
            return notify_fail("���������һ������֮�����������ǡ�ô���ĳһ���Ŀ�ʼ�׶�"
                        "����û��ȷ����չ���򣩣���ֻ�ܷ���һ������֮����\n");
        
        foreach (string elem in keys(elements)) {
            int elem_prop = fabao_ob->query(fabao_type + "_prop/" + elem);
            if (elem_prop >= 100)
                comp++;
            if (elem_prop > 0 && elem_prop < 100)
                half = elem;
            if (elem_prop == 0 && !undefinedp(elements_ob[elem]))
                zero += ({ elem });
        }

        stars = fabao_ob->query("stars/" + props[fabao_type][0]["id"]);
        if (stringp(half)) {
            if (sizeof(zero))
                return notify_fail(fabao_ob->name() + "�ġ�"
                            + elements[half] + "�����Ի�û�������꣬��Ҫ�����������ʡ�\n");
        }
        else if (sizeof(zero) > 1)
            return notify_fail(fabao_ob->name() + "�ķ�չ����û��ȷ��������뵥һ���������֮����\n");
        else if (sizeof(zero) < 1)
            return notify_fail(fabao_ob->name() + "����Щ���Զ��Ѿ������ˡ�\n");
        else {
            if (comp + 1 > stars)
                return notify_fail(fabao_ob->name() + "�ĵȼ��������޷�ǿ���µ����ԡ�\n");
            enhance_type = zero[0];
        }
        
        foreach (object elem in elements_ob[enhance_type]) {
            enhance_point += elem->query("elements/" + enhance_type);
        }
        
        smelter->set_temp("fabao_ob", fabao_ob);
        smelter->set_temp("enhance/type", enhance_type);
        smelter->set_temp("enhance/point", enhance_point);
        smelter->set_temp("enhance/name", elements[enhance_type]);
        return 1;
    }
    else {
        string fabao_type = "";
        
        if (objectp(fabao_ob))
            fabao_type = fabao_ob->query("fabao_type");
        
        if (undefinedp(formulas[fabao_type][formula_type]))
            return notify_fail("����û����һ����������ԡ�\n");
        
        foreach (string m in keys(formulas[fabao_type][formula_type])) {
            if (undefinedp(minerals_ob[m]))
                return notify_fail("ȱ�ٲ��ϡ�" + minerals[m] + "����\n");
            if (minerals_ob[m]->query_amount() < formulas[fabao_type][formula_type][m])
                return notify_fail("���ϡ�" + minerals[m] + "�����㡣\n");
        }
        
        foreach (string m in keys(minerals_ob)) {
            if (undefinedp(formulas[fabao_type][formula_type]))
                return notify_fail("���������ʣ������޷����С�\n");
        }
        
        if (objectp(fabao_ob)) {
            int comp = 0;
            foreach (string elem in keys(elements)) {
                if (fabao_ob->query(fabao_type + "_prop/" + elem) >= 100)
                    comp++;
            }
            smelter->set_temp("elem_comp", comp);
            smelter->set_temp("fabao_ob", fabao_ob);
        }
    }

    return 1;
}

varargs int varify_player(string prop, object me, object smelter)
{
    object fabao_ob;
    mapping p_info, *costs;
    string fabao_type;
    int stars, upgraded, elem_comp, min_exp, min_force, min_mana;

    fabao_ob = smelter->query_temp("fabao_ob");
    if (!objectp(fabao_ob)) {
        if (me->query("combat_exp") < 20000)
            return notify_fail("��ĵ���̫ǳ���޷�������Ʒ��������\n");
        if (me->query("max_force") < 300)
            return notify_fail("��������������޷�֧�����Ʒ����ľ޴����ġ�\n");
        if (me->query("max_mana") < 300)
            return notify_fail("��ķ����������޷�֧�����Ʒ����ľ޴����ġ�\n");
        if (me->query("force") < (me->query("max_force") + 100))
            return notify_fail("���Ʒ���ʱ������봦��������ӯ��״̬��\n");
        if (me->query("mana") < (me->query("max_mana") + 100))
            return notify_fail("���Ʒ���ʱ������봦��������ӯ��״̬��\n");
        if (count_fabao(me, "weapon") >= MAX_WEAPON
        &&  count_fabao(me, "armor") >= MAX_ARMOR)
            return notify_fail("��ķ������Ѿ��ﵽ�˼��ޣ��ٶ�Ҳû�������ˡ�\n");

        me->delete_temp("fabaod");
        me->set_temp("fabaod/max_force", 50);
        me->set_temp("fabaod/max_mana", 50);
        me->set_temp("fabaod/force", 200);
        me->set_temp("fabaod/mana", 200);
        return 1;
    }

    if (prop == "enhance")
        return 1;

    fabao_type = fabao_ob->query("fabao_type");
    if (!mapp(p_info = query_prop(fabao_type, prop)))
        return notify_fail("û���������ԡ�\n");

    stars = fabao_ob->query("stars/" + prop);
    upgraded = fabao_ob->query("upgraded/" + prop);
    if (stars >= 5)
        return notify_fail("���ԡ�" + p_info["name"] + "���Ѿ����������ˣ�\n");

    costs = upgrades[fabao_type][prop];
    min_exp = costs[stars]["min_exp"];
    min_exp += (costs[stars + 1]["min_exp"] - costs[stars]["min_exp"]) * upgraded / 5;
    min_force = costs[stars]["min_force"];
    min_mana = costs[stars]["min_mana"];
    if (min_exp > me->query("combat_exp")
    ||  min_force > me->query("max_force")
    ||  min_mana > me->query("max_mana"))
        return notify_fail("�������㣬�޷���������������������costָ���ѯ������������\n");

    elem_comp = smelter->query_temp("elem_comp");
    if (elem_comp < stars)
        return notify_fail(fabao_ob->name() + "�ĵ�" + chinese_number(elem_comp + 1)
                    + "������������û��Բ�����޷�����������\n");
    me->delete_temp("fabaod");
    me->set_temp("fabaod/max_force", costs[stars]["force"]);
    me->set_temp("fabaod/max_mana", costs[stars]["mana"]);
    me->set_temp("fabaod/combat_exp", costs[stars]["exp"]);
    smelter->set_temp("upgraded_prop", p_info["name"]);
    return 1;
}

mixed query_prop(string fabao_type, string prop)
{
    foreach (mapping m in props[fabao_type]) {
        if (m["id"] == prop)
            return m;
    }
    return 0;
}

void start_make_fabao(object ob, object smelter)
{
    write("��Ҫ�������෨����\n");
    if (count_fabao(ob, "weapon") < MAX_WEAPON)
        write("w. ����\n");
    if (count_fabao(ob, "armor") < MAX_ARMOR)
        write("a. ����\n");
    write("o. ����(��ȱ)\n");
    // Other kinds of fabao can be added too.. if there is somefile
    // we can use as a default object.
    write("��ѡ��(q ��ȡ��)");

    seteuid(getuid());
    input_to( (: get_fabao_type, ob, smelter :) );
}

void get_fabao_type(object ob, object smelter, string arg)
{
    string fabao_type;
    
    if (arg == "q" || arg == "Q")
        return;
    
    if ((arg != "w" || count_fabao(ob, "weapon") >= MAX_WEAPON)
    &&  (arg != "a" || count_fabao(ob, "armor") >= MAX_ARMOR)) {
        write("��Ҫ�������෨����\n");
        if (count_fabao(ob, "weapon") < MAX_WEAPON)
            write("w. ����\n");
        if (count_fabao(ob, "armor") < MAX_ARMOR)
            write("a. ����\n");
        write("o. ����(��ȱ)\n");
        write("��ѡ��(q ��ȡ��)");
        input_to( (: get_fabao_type, ob, smelter :) );
        return;
    }
    
    if (arg == "w") {
        fabao_type = "weapon";
        write("\n");
        write("��ѡ���������ࣺ\n");
        write(show_subtypes("weapon"));
        write("��ѡ��(q ��ȡ��)");
    }
    else if (arg == "a") {
        fabao_type = "armor";
        write("\n");
        write("��ѡ��������ࣺ\n");
        write(show_subtypes("armor"));
        write("��ѡ��(q ��ȡ��)");
    }
    ob->set_temp("fabao_type", fabao_type);
    ob->set_temp("fabao_new", fabao_type + (count_fabao(ob, fabao_type) + 1));
    input_to( (: get_fabao_subtype, ob, smelter :) );
}

void get_fabao_subtype(object ob, object smelter, string arg)
{
    int  order;
    string fabao_type = ob->query_temp("fabao_type");
    
    if (arg == "q" || arg == "Q") return;
    
    order = atoi(arg);

    if ((fabao_type == "weapon" && order <= 0 && order > 10)
    ||  (fabao_type == "armor" && order <= 0 && order > 13)) {
        if (arg == "w")    {
            fabao_type = "weapon";
            write("\n");
            write("��ѡ���������ࣺ\n");
            write(show_subtypes("weapon"));
            write("��ѡ��(q ��ȡ��)");
        }
        else if (arg == "a")   {
            fabao_type = "armor";   
            write("\n");
            write("��ѡ��������ࣺ\n");
            write(show_subtypes("armor"));
            write("��ѡ��(q ��ȡ��)");
        }
        ob->set_temp("fabao_type", fabao_type);
        input_to( (: get_fabao_subtype, ob, smelter :) );
        return;
    }
    
    ob->set_temp("fabao_subtype", order);
    
    write("\n");
    write("���趨Ӣ�� id ��");
    input_to( (: get_fabao_id, ob, smelter :) );
}

void get_fabao_id(object ob, object smelter, string arg)
{
    arg = lower_case(arg);
    if (!LOGIN_D->check_legal_id(arg)) {
        write("���趨Ӣ�� id ��");
        input_to( (: get_fabao_id, ob, smelter :) ); 
        return;
    }
    
    arg = replace_string(arg, " ", "_");
    ob->set_temp("fabao_id", arg);
    
    write("\n");
    write("���趨��������(�ɼ���ɫ)");
    input_to( (: get_fabao_name, ob, smelter :) );
}

void get_fabao_name(object ob, object smelter, string arg)
{
    string arg_old;
    
    arg += "$NOR$";
    arg_old = arg;
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
    
    if (!LOGIN_D->check_legal_name(arg, 12)) {
        write("���趨��������(�ɼ���ɫ)");
        input_to( (: get_fabao_name, ob, smelter :) );
        return;
    }
    
    arg = arg_old;
    
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
    
    ob->set_temp("fabao_name", arg);
    
    write("\n");
    write("������������");
    input_to( (: get_fabao_desc, ob, smelter :) );
}

void get_fabao_desc(object ob, object smelter, string arg)
{
    ob->set_temp("fabao_desc", arg);
    
    write("\n");
    write("���������ʣ�(Return for default)");
    input_to( (: get_fabao_unit, ob, smelter :) );
}

void get_fabao_unit(object ob, object smelter, string arg)
{
    string fabao_unit;

    if (arg == "")
        fabao_unit = "";
    else if (!LOGIN_D->check_legal_name(arg, 2)) {
        write("���������ʣ�(Return for defult)");
        input_to( (: get_fabao_unit, ob, smelter :) );
        return;
    }
    else
        fabao_unit = arg;

    ob->set_temp("fabao_unit", fabao_unit);
    
    write("��Ϣȷ����ϣ���ʼ���Ʒ�����\n\n\n");
    smelter->complete_make_fabao(ob);
}

object new_fabao_ob(object ob)
{
    object newob;
    int rev;
    string fabao_type = ob->query_temp("fabao_type");
    int    fabao_subtype = ob->query_temp("fabao_subtype");
    string fabao_id = ob->query_temp("fabao_id");
    string fabao_name = ob->query_temp("fabao_name");
    string fabao_desc = ob->query_temp("fabao_desc");
    string fabao_unit = ob->query_temp("fabao_unit");
    
    newob = new("/obj/fabao");
    if (!newob)
        return newob;
    seteuid(getuid(ob));
    rev = export_uid(newob);
    seteuid(getuid());
    
    newob->set("fabao_type", fabao_type);
    newob->set("fabao_subtype/0", fabao_subtype);
    newob->set("fabao_subtype/1", fabao_subtype);

    newob->set("id", fabao_id);
    newob->set("name", fabao_name);
    newob->set("long", fabao_desc);
    if (fabao_unit != "")
        newob->set("unit", fabao_unit);

    newob->set("value", 1);
    newob->set("no_sell", 1);

    newob->set("rigidity", 100);
    newob->set("flag", TWO_HANDED);

    // set owner of fabao
    newob->set("owner_id", getuid(ob));
    newob->set("series_no", max_series_no(ob) + 1);

    foreach (mapping prop in props[fabao_type]) {
        newob->set("stars/" + prop["id"], 0);
        newob->set("upgraded/" + prop["id"], 0);
    }
    foreach (string elem in keys(elements)) {
        newob->set(fabao_type + "_prop/" + elem, 0);
    }
    return newob;
}

void build_weapon(object ob)
{
    int subtype = ob->query("fabao_subtype/0");

    string ob_file = "/d/obj/weapon/"
        + subtypes["weapon"][subtype - 1]["default_file"];

    ob->set("default_file", ob_file);
    ob->set_default_object(ob_file);

    setup_prop(ob, "weapon");

    if (ob->query("seal")) {
        ob->set("short", ob->name() + "(" + capitalize(ob->query("id")) + ")" + CYN + "����ӡ�С�" + NOR);
        ob->set("weapon_prop/damage", 1);
    }
    else {
        ob->delete("short");
    }
}

void build_armor(object ob)
{
    int subtype = ob->query("fabao_subtype/0");

    string ob_file = "/d/obj/"
        + subtypes["armor"][subtype - 1]["default_file"];

    ob->set("default_file", ob_file);
    ob->set_default_object(ob_file);

    setup_prop(ob, "armor");
}

void setup_prop(object ob, string type)
{
    foreach (mapping prop in props[type]) {
        string p_name = prop["id"];
        int val = prop["init_val"];
        int stars = ob->query("stars/" + p_name);
        int upgraded = ob->query("upgraded/" + p_name);
        mapping *effs = upgrades[type][p_name];
        
        for (int i = 0; i < stars + 1; i++) {
            if (i != stars)
                val += effs[i]["val"] * 5;
            else
                val += effs[i]["val"] * upgraded;
        }
        ob->set(type + "_prop/" + p_name, val);
    }
}

int count_fabao(object me, string type)
{
    int i;
    for (i = 1; me->query("fabao/" + type + i); i++)
        ;
    return i;
}

int max_series_no(object me)
{
    int i, series, max_series;
    for (i = 0; series = me->query("fabao/weapon" + i); i++)
        if (max_series < series)
            max_series = series;
    for (i = 0; series = me->query("fabao/armor" + i); i++)
        if (max_series < series)
            max_series = series;
    return max_series;
}

string show_subtypes(string fabao_type)
{
    string str = "";
    int i;
    for (i = 0; i < sizeof(subtypes[fabao_type]); i++) {
        mapping subtype = subtypes[fabao_type][i];
        string no = (i + 1) + ".";
        if (strlen(no) < 3) no += " ";
        str += no + subtype["name"] + "\t";
        if ((i + 1) % 5 == 0) str += sprintf("\n");
    }
    if ((i + 1) % 5 != 1) str += sprintf("\n");
    return str;
}
