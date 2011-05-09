inherit F_CLEAN_UP;

#include <ansi.h>

mapping obstacles = ([
    "levels" : ([
        "wuzhuang"   : "  1. ��ׯ�ۣ��˲ι�",
        "baoxiang"   : "  2. �����������ɽ",
        "pingding"   : "  3. ƽ��ɽ����������ѹ��ɽ��ѹ����",
        "wuji"       : "  4. �ڼ�����������",
        "chechi"     : "  5. ���ٹ��������",
        "tongtian"   : "  6. ͨ��ӣ��¼�ׯ",
        "jindou"     : "  7. ��ɽ���𶵶�",
        "nuerguo"    : "  8. Ů����������ɽ",
        "dudi"       : "  9. ����ɽ�����ö�",
        "firemount"  : " 10. ����ɽ������ɽ",
        "jilei"      : " 11. ����ɽ��Ħ�ƶ�",
        "jisaiguo"   : " 12. ���������̲�̶",
        "jingjiling" : " 13. �����룯ľ����",
        "xiaoxitian" : " 14. С���죯С������",
        "zhuzi"      : " 15. ���Ϲ�������ɽ�������",
        "pansi"      : " 16. ��˿�룯��˿�����ƻ��ۣ�����ɽ",
        "biqiu"      : " 17. ��������廪ׯ���廪��",
        "wudidong"   : " 18. �޵׶���������",
        "qinfa"      : " 19. �շ���",
        "yinwu"      : " 20. ����ɽ��������",
        "fengxian"   : " 21. ���ɿ�",
        "yuhua"      : " 22. ���أ���ͷɽ�����ڶ������ɽ�������̻���",
        "jinping"    : " 23. ��ƽ��������ɽ����Ӣ��",
        "tianzhu"    : " 24. ���ù���ëӱɽ������Ѩ",
    ]),
    "rec" : "obstacle",
    "zero_msg" : "��δ������ȡ�澭��",
    "done_fmt" : "%s������ȡ�澭�ѹ���%s�أ�",
    "todo_fmt" : "%s������ȡ�澭�����%s�أ�",
    "over_msg" : "������ȡ�澭�����������е��ѹء�",
]);

mapping dntg = ([
    "levels" : ([
        "huaguo" : " 1. ���ض���������ĺ�ǧɽ����",
        "donghai": " 2. ��������̽������ֿ�����",
        "hell"   : " 3. �������޵ظ�������ʮ�����",
        "bmw"    : " 4. ��ͥ�����»�����ӷ������",
        "lijing" : " 5. ��������������Է������ʥ",
        "pantao" : " 6. ͵���������Ϸˣ������Ů",
        "yaochi" : " 7. ��׬��Ŵ��ɣ��������ʢ��",
        "laojun" : " 8. ����ʮ���죬��ȡ�ɵ���ҩ",
        "erlang" : " 9. �¶��������������÷ɽ��ʥ",
        "bagualu": "10. ����¯���Ӵ�ʥ�������������칬",
    ]),
    "rec" : "dntg",
    "zero_msg" : "��û���������¡�",
    "done_fmt" : "%s�����칬�ѹ���%s�أ�",
    "todo_fmt" : "%s�����칬�����%s�أ�",
    "over_msg" : "�����칬�Ѿ�����Բ����",
]);

varargs mapping query_obstacle_levels(string opt)
{
    return (mapping)(opt == "dntg" ? dntg["levels"] : obstacles["levels"]);
}

varargs int check_obstacles(object who, string opt)
{
    mapping def = opt == "dntg" ? dntg : obstacles;
    return who->query(def["rec"] + "/number") >= sizeof(obstacles);
}

// mode 0: all
// mode 1: only done
// mode 2: only todo
varargs string check_obstacles_long(object who, int mode, int not_self, string opt)
{
    string name = not_self ? who->query("name") : "��";
    mapping def = opt == "dntg" ? dntg : obstacles;
    int size = sizeof(def["levels"]);
    string *names = keys(def["levels"]);
    string *dones = allocate(size);
    string *todos = allocate(size);
    int nb = 0, sb = 0;
    int i;
    string str = "";

    for (i = 0; i < size; i++) {
        dones[i] = "none";
        todos[i] = "none";
    }

    for (i = 0; i < size; i++) {
        if (who->query(def["rec"] + "/" + names[i]) == "done") {
            dones[nb] = def["levels"][names[i]];
            nb++;
        } else {
            todos[sb] = def["levels"][names[i]];
            sb++;
        }
    }

    if (mode != 2) {
        if (nb == 0)
            str += sprintf("%s%s\n", name, def["zero_msg"]);
        else {
            str += sprintf(def["done_fmt"] + "\n", name, chinese_number(nb));
            who->set(def["rec"] + "/number", nb);
            dones = (string *)sort_array(dones, 1);
            for (i = 0; i < nb; i++)
                str += sprintf("    %s\n", dones[i]);
        }
    }
    if (mode != 1) {
        if (sb == 0)
            str += sprintf("%s%s\n", name, def["over_msg"]);
        else {
            str += sprintf(def["todo_fmt"] + "\n", name, chinese_number(sb));
            todos = (string *)sort_array (todos, 1);
            for (i = 0; i < sb; i++)
                str += sprintf("    %s\n", todos[i]);
        }
    }
    return str;
}

varargs string check_obstacles_short(object who, string opt)
{
    mapping def = opt == "dntg" ? dntg : obstacles;
    int size = sizeof(def["levels"]);
    string *names = keys(def["levels"]);
    int nb = 0, sb = 0;
    int i;
    string str = "";

    for (i = 0; i < size; i++) {
        if (who->query(def["rec"] + "/" + names[i]) == "done") nb++;
        else sb++;
    }

    if (nb == 0) return def["zero_msg"];
    else if (sb == 0) return def["over_msg"];
    else return sprintf(def["done_fmt"], "", chinese_number(nb));
}

int xiudao_accelerate(object me, int pot_gain)
{
    return pot_gain + (int)me->query("obstacle/number") * pot_gain / 2 / sizeof(obstacles["levels"]);
}
