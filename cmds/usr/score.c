// ALI by NewX

// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string *sex_ranking = ({"��������", "��������", "���ڸ���", "��������", "��������", "��Ů����"});

string display_attr(int gift, int value);

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
    object ob;
    mapping my;
    string line, str;

    seteuid(getuid(me));

    if (!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    } else
        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

    my = ob->query_entire_dbase();

    write(NOR YEL"�ԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡԡ�\n"NOR);
    line = sprintf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1));
    line += NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;

    line += sprintf(" �Ա�%s%-4s%s  ���䣺%s%-4s��%s%-6s\n\n",
            HIG, my["gender"], NOR,
            HIY, my["always_young"] ? chinese_number(my["fake_age"]) : chinese_number(my["age"]), NOR,
            my["always_young"] ? "("CYN+chinese_number(my["age"])+"��"NOR ")" : "      ",
            );

    line += sprintf(
            " ������[%s]  | ������[%s]  | ��ʶ��[%s]  | ��ò��[%s]\n",
            display_attr(my["str"], ob->query_str()),
            display_attr(my["cps"], ob->query_cps()),
            display_attr(my["cor"], ob->query_cor()),
            display_attr(my["per"], ob->query_per()),
            );
    line += sprintf(
            " ���ԣ�[%s]  | ���ԣ�[%s]  | ���ǣ�[%s]  | ��Ե��[%s]\n\n",
            display_attr(my["int"], ob->query_int()),
            display_attr(my["spi"], ob->query_spi()),
            display_attr(my["con"], ob->query_con()),
            display_attr(my["kar"], ob->query_kar()),
            );
/*
    if (my["eff_gin"] < my["max_gin"]) str = HIR + "����";
    else if (my["gin"]*100 / my["max_gin"]>=70) str = HIG + "��ӯ";
    else if (my["gin"]*100 / my["max_gin"]>=40) str = HIR + "���";
    else str = HIB + "����";
    line += sprintf(" ������[%s%3s%s]  | ��%s��Ԫ%s�� %s [%4s%s]\n",
                NOR, display_attr(my["int"], ob->query_int()), NOR,
                HIR, NOR, tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], NOR, HIR, HIW),
                str, NOR);

    if (my["eff_kee"] < my["max_kee"]) str = HIR + "�˲�";
    else if (my["kee"]*100 / my["max_kee"]>=70) str = HIG + "����";
    else if (my["kee"]*100 / my["max_kee"]>=40) str = HIR + "����";
    else str = HIB + "����";
    line += sprintf(" ���ǣ�[%s%3s%s]  | ��%s��Ѫ%s�� %s [%4s%s]\n",
                NOR, display_attr(my["con"], ob->query_con()), NOR,
                HIR, NOR, tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], NOR, HIR, HIW),
                str, NOR);

    if (my["eff_sen"] < my["max_sen"]) str = HIR + "ʧ��";
    else if (my["sen"]*100 / my["max_sen"]>=70) str = HIG + "����";
    else if (my["sen"]*100 / my["max_sen"]>=40) str = HIR + "ƣ��";
    else str = HIB + "����";
    line += sprintf(" ���ԣ�[%s%3s%s]  | ��%s����%s�� %s [%4s%s]\n",
                NOR, display_attr(my["spi"], ob->query_spi()), NOR,
                HIR, NOR, tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], NOR, HIR, HIW),
                str, NOR);

    if (my["food"] * 100 / ob->max_food_capacity() >= 80) str = HIG + "�Ա�";
    else if (my["food"] * 100 / ob->max_food_capacity() >= 50) str = HIC + "����";
    else if (my["food"] * 100 / ob->max_food_capacity() >= 20) str = HIR + "ȱʳ";
    else str = HIB + "����";
    line += sprintf(" ��ò��[%s%3s%s]  | ��%sʳ��%s�� %s [%4s%s]\n",
                NOR, display_attr(my["per"], ob->query_per()), NOR,
                HIC, NOR, tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), NOR, HIC, HIR),
                str, NOR);

    if (my["water"] * 100 / ob->max_water_capacity() >= 80) str = HIG + "����";
    else if (my["water"] * 100 / ob->max_water_capacity() > 60) str = HIG + "����";
    else if (my["water"] * 100 / ob->max_water_capacity() > 30) str = HIR + "ȱˮ";
    else str = HIB + "����";
    line += sprintf("              | ��%s��ˮ%s�� %s [%4s%s]\n",
                HIC, NOR, tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), NOR, HIC, HIR),
                str, NOR);

    line += "\n";
*/
    if (mapp(my["family"]))
        line += sprintf(" ��  �ɣ�" HIC "%-6s" NOR, my["family"]["family_name"]);
    else
        line += sprintf(" ��  �ɣ�" HIC "��" NOR);
    if (mapp(my["family"]) && my["family"]["master_name"])
        line += sprintf("  ʦ  ����" YEL "%s" NOR, my["family"]["master_name"]);
    else
        line += sprintf("  ʦ  ����" YEL "��" NOR);
    if (stringp(my["secret_master_name"]))
        line += sprintf("  ����ʦ����" MAG "%s\n" NOR, my["secret_master_name"]);
    else
        line += "\n";

    line += sprintf(" ս  ����ɱ %d �ˣ�����NPC %d �ˣ�������� %d ��\n",
        my["MKS"] + my["PKS"], my["MKS"], my["PKS"]);

    line += " �Ծ��飺";
    if (mapp(my["sex"]) && mapp(my["sex"]["lovers"])) {
        line += HIY + sex_ranking[sizeof(my["sex"]["lovers"])/10*2+(int)(my["gender"]=="����")] + NOR;
        if (my["gender"] == "����" && !my["sex"]["first_semen_lost"])
            line += "�����Ա���" HIB "ͯ��֮��" NOR;
        else if (my["gender"] == "Ů��" && !my["sex"]["hymen_broken"])
            line += "�����Ա���" HIB "����֮��" NOR;
    }
    else
        line += HIB + (my["gender"]=="����"?"ͯ":"��") + "��֮��" NOR;
    
    if (undefinedp(my["sex_leaning"]))
        line += "\n";
    else if (my["sex_leaning"] == "both")
        line += " ������" HIY "����" NOR "��" HIY "Ů��" NOR "\n";
    else if (my["sex_leaning"]=="same") {
        if (my["gender"]=="Ů��")
            line += " ������" HIY "Ů��" NOR "\n";
        else
            line += " ������" HIY "����" NOR "\n";
    } else if (my["sex_leaning"]=="diff") {
        if (my["gender"]=="Ů��")
            line += " ������" HIY "����" NOR "\n";
        else
            line += " ������" HIY "Ů��" NOR "\n";
    } else
        line += "\n";

    if (ob->query("balance"))
        line += " ��  �" + MONEY_D->money_str((int)ob->query("balance"))+"���\n\n";
    else
        line += " ��  �" HIW "û���κδ��" NOR "\n\n";

    line += RED " ����ȡ��" NOR "��" + OBSTACLES_D->check_obstacles_short(ob) + "\n";
    line += RED " �����칬" NOR "��" + OBSTACLES_D->check_obstacles_short(ob, "dntg") + "\n";

    line += NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;

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
    
        line += sprintf(" �������ۣ�%s%-10d%s(%s%+5d%s)  �������ۣ�%s%-10d%s(%s%+5d%s)\n",
            HIW, attack_points/100 + 1, NOR,
            HIR, ob->query_temp("apply/damage"), NOR,
            HIW, (dodge_points + (weapon? parry_points:(parry_points/10)))/100 + 1, NOR,
            HIY, ob->query_temp("apply/armor"), NOR);
    }

    line += sprintf(" ���о��磺%s           ��ѧ���磺%s\n",
                RANK_D->describe_exp(ob->query("combat_exp")),
                RANK_D->describe_skills(ob->query_skills()));
    line += sprintf(" ������Ϊ��%s           ������Ϊ��%s\n",
                RANK_D->describe_mana(ob->query("max_mana")),
                RANK_D->describe_force(ob->query("max_force")));

    line += YEL"�ԡԡԡԡԡԡԡԡԡ� "GRN"���μ�" HIY "��"HIG"��������"NOR YEL" �ԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
    line += sprintf(" Ϊ�������ƽ%s�Ѿ����� %s ������ \n",
        ob == me ? "��" : ob->name(1),
        HIR + FINGER_D->age_string( (int)ob->query("mud_age")) + NOR);
    write(line);
    return 1;
}

string display_attr(int gift, int value)
{
    if (value > gift) return sprintf( HIY "%3d" NOR, value );
    else if (value < gift) return sprintf( CYN "%3d" NOR, value );
    else return sprintf("%3d", value);
}

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
    string ret;
    int i, n, eff_n, max_n = 12;

    if (max == 0) max = 1;
    n = val * 100 / max / 10;
    eff_n = eff * 100 / max / 10;

    if (n < 0) n = 0;
    if (eff_n < 0) eff_n = 0;
    if (n > max_n) n = max_n;
    if (eff_n > max_n) eff_n = max_n;

    ret = NOR  + bcolor + fcolor ;
    for (i = 0 ; i < max_n; i++) {
        if (i > eff_n) ret += dcolor;
        if (i < n)  ret += "��";
        else ret += HIW"��"NOR;
    }
    ret += fcolor + NOR ;
    return ret;
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

