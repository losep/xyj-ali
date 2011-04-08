// ALI by NewX

// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

//string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�", "����֮ѡ"});

string *sex_ranking = ({"��������", "��������", "���ڸ���", "��������", "��������", "��Ů����"});

string bar_string = "��������������������������������������������������";
string blank_string ="��������������������������������������������������";

string display_attr(int gift, int value);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
    object ob;
    mapping my;
    string line;

    seteuid(getuid(me));

    if(!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    } else
        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

    my = ob->query_entire_dbase();

    line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob),
        ob->short(1) );

    line += sprintf(" ���壺" HIG "%s" NOR
            " �Ա�" HIG "%s" NOR
            " ���䣺" HIY "%s��" NOR
            " ���У�" RED "%s��" NOR "\n\n",
            my["race"], my["gender"], chinese_number(my["age"]),
            my["combat_exp"] > 1000 ? chinese_number(my["combat_exp"]/1000)
                : "����һ"
            );

    line += sprintf(
            " ������[%s]  ���ݣ�[%s]  ������[%s]  ���ԣ�[%s]\n"
            " ������[%s]  ��ʶ��[%s]  ������[%s]  ���ǣ�[%s]\n"
            " Ӳ��: [%s]  ���У�[%s]  ���ԣ�[%s]  ��Ե��[%s]\n\n",
            display_attr(my["str"], ob->query_str()),
            display_attr(my["dex"], ob->query_dex()),
            display_attr(my["int"], ob->query_int()),
            display_attr(my["spi"], ob->query_spi()),
            display_attr(my["cps"], ob->query_cps()),
            display_attr(my["cor"], ob->query_cor()),
            display_attr(my["per"], ob->query_per()),
            display_attr(my["con"], ob->query_con()),
            display_attr(my["rig"], ob->query_rig()),
            display_attr(my["sns"], ob->query_sns()),
            display_attr(my["met"], ob->query_met()),
            display_attr(my["kar"], ob->query_kar()),
            );

#if 0
    if (mapp(my["family"])) {
        if (my["family"]["master_name"])
            line += sprintf(" ʦ����" YEL "%s" NOR, my["family"]["master_name"] );
    }
#endif

    if (mapp(my["makelove"]) && sizeof(my["makelove"]) > 0) {
        int gender = my["gender"] == "����";
        int lover = sizeof(my["makelove"]);
        lover = lover > 30 ? 30 : lover;
        line += " �Ծ��飺" HIY +sex_ranking[(lover/10)*2+gender] + NOR;
    } else {
        string gender = my["gender"];
        line += " �Ծ��飺" HIB "��" + gender[0..1] + NOR;
    }
    
    if (undefinedp(my["sex_leaning"]))
        line += "\n";
    else if (my["sex_leaning"] == "both")
        line += " ������"HIY"����"NOR"��"HIY"Ů��"NOR"\n";
    else if (my["sex_leaning"]=="same") {
        if (my["gender"]=="Ů��")
            line += " ������"HIY"Ů��"NOR"\n";
        else
            line += " ������"HIY"����"NOR"\n";
    } else if (my["sex_leaning"]=="diff") {
        if (my["gender"]=="Ů��")
            line += " ������"HIY"����"NOR"\n";
        else
            line += " ������"HIY"Ů��"NOR"\n";
    } else
        line += "\n";

    line += sprintf(" ս  ����ɱ %d �ˣ�����NPC %d �ˣ�������� %d ��\n",
        my["MKS"] + my["PKS"], my["MKS"], my["PKS"]);
        
    if (ob->query("kill/pkgain")) { 
        line +=sprintf(" �У˵������ӣ� %s  \n",
            COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
    }
    if (ob->query("kill/pklose")) {
        line +=sprintf(" �У˵��м��٣� %s\n",
            COMBAT_D->chinese_daoxing(ob->query("kill/pklose")));
    }
    if (ob->query("kill/nkgain")) {
        line +=sprintf(" �Σ˵������ӣ� %s\n",
            COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
    }

    if (ob->query("obstacle/number"))
        line += sprintf(" ��������ȡ�澭�ѹ���"RED"%s��"NOR"��\n\n",
                chinese_number(ob->query("obstacle/number")));
    else
        line += sprintf("\n");

    line += " <��>  " + tribar_graph(my["gin"], my["eff_gin"],
        my["max_gin"], HIY) + "\n";
    line += " <��>  " + tribar_graph(my["kee"], my["eff_kee"],
        my["max_kee"], HIR) + "\n";
    line += " <��>  " + tribar_graph(my["sen"], my["eff_sen"],
        my["max_sen"], HIB) + "\n";

#if 0
/*
        line += sprintf(" ���� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d
/ %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"],
my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),
my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),
my["force"], my["max_force"],
                my["force_factor"] );
        line += sprintf(" �� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d
/ %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"],
my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),
my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"],
my["max_mana"],
                my["mana_factor"] );
*/
/*
        line += sprintf(" ʳ�%d/%d����ˮ��%d/%d\n\n",
                my["food"], ob->max_food_capacity(), my["water"],
ob->max_water_capacity());
*/
#endif

    {
    /* ap/dp calc */
    string skill_type;
    object weapon;
    int attack_points, dodge_points, parry_points;

    if (objectp(weapon = ob->query_temp("weapon")))
        skill_type = weapon->query("skill_type");
    else
        skill_type = "unarmed";

    attack_points = COMBAT_D->skill_power(ob, skill_type,
        SKILL_USAGE_ATTACK);
    parry_points = COMBAT_D->skill_power(ob, skill_type,
        SKILL_USAGE_DEFENSE);
    dodge_points = COMBAT_D->skill_power(ob, "dodge",
        SKILL_USAGE_DEFENSE);

    line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR
        "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
        attack_points/100 + 1, ob->query_temp("apply/damage"),
        (dodge_points + (weapon? parry_points:
            (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
    }

    line += " ʳ�" + tribar_graph(my["food"],
        ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
    line += " ��ˮ��" + tribar_graph(my["water"],
        ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n\n";

    line += sprintf(" ɱ  ���� " RED "%-9d" NOR "            ",ob->query("bellicosity") );
    line += sprintf(" Ǳ  �ܣ� " HIY "%-9d\n" NOR,(int)ob->query("potential") -(int)ob->query("learned_points") );
    //line += sprintf(" ��  ���� " HIM "%-9d" NOR,ob->query("shen") );
    //line += sprintf(" ��  �ۣ� " HIC "%-9d\n" NOR,ob->query("score") );

    write(line);
    return 1;
}

string display_attr(int gift, int value)
{
    if (value > gift) return sprintf( HIY "%3d" NOR, value );
    else if (value < gift) return sprintf( CYN "%3d" NOR, value );
    else return sprintf("%3d", value);
}

string tribar_graph(int val, int eff, int max, string color)
{
    return color + bar_string[0..(val*25/max)*2-1]
        + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "")
        + NOR;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ���ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}

