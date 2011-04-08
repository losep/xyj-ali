// ALI by NewX

// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
    ([   "action":     "$N��ȭ����$n��$l",
     "damage_type":   "����",
     ]),
    ([   "action":     "$N��$n��$lһץ",
     "damage_type":   "ץ��",
     ]),
    ([   "action":     "$N��$n��$l�ݺݵ�����һ��",
     "damage_type":   "����",
     ]),
    ([   "action":     "$N����ȭͷ��$n��$l��ȥ",
     "damage_type":   "����",
     ]),
    ([   "action":     "$N��׼$n��$l�����ӳ�һȭ",
     "damage_type":   "����",
     ]),
});

mapping *sex_action = ({
    ([
     "action": "$N���ḧ��$n��$s��",
     "limb": "all",
     "enjoy": 2,
     "self_enjoy": 1,
     "cost": 1,
     ]),
    ([
     "action": "$N��������һ��$n��$s��",
     "limb": "all",
     "enjoy": 2,
     "self_enjoy": 1,
     "cost": 1,
     ]),
    ([
     "action": "$N�����ָ��Ĩ����$n��$l��",
     "limb": "pussy",
     "min_enjoy": 50,
     "effect": "Ĩ�������ֵ���֭��",
     "enjoy": 4,
     "self_enjoy": 2,
     "cost": 1,
     ]),
    ([
     "action": "$Nһ��ץס��$n��$b��",
     "limb": "breast",
     "min_enjoy": 80,
     "effect": "�������˴����������֭��",
     "enjoy": 8,
     "self_enjoy": 5,
     "cost": 2,
     ]),
});

mapping *sex_fuck_action = ({
    ([
     "action": "$N�ó���ǳһ��֮������$L��$n��$l��������ĥ�䣬ֱ��$n�����ĸ����꣬��ˮ���硣\n",
     "enjoy": 30,
     "self_enjoy": 3,
     ]),
    ([
     "action": "$N��סһ��������$L����$n�Ļ����ϣ����Ŀ���Ͳ壬���$nֱ�����ۣ�ˬ�÷ɵ�������ȥ�ˡ�\n",
     "enjoy": 50,
     "self_enjoy": 10,
     ]),
});

void create()
{
    seteuid(getuid());
}

void setup_human(object ob)
{
    mapping my;

    my = ob->query_entire_dbase();

    ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
    ob->set("default_sex_actions", (: call_other, __FILE__, "query_sex_action" :));
    ob->set("default_fuck_actions", (: call_other, __FILE__, "query_fuck_action" :));

    if ( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

    if ( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
    if ( undefinedp(my["dex"]) ) my["dex"] = random(21) + 10;
    if ( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
    if ( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
    if ( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
    if ( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
    if ( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
    if ( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;
    if ( undefinedp(my["rig"]) ) my["rig"] = random(21) + 10;
    if ( undefinedp(my["sns"]) ) my["sns"] = random(21) + 10;
    if ( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
    if ( undefinedp(my["met"]) ) my["met"] = random(21) + 10;

    if ( userp(ob) || undefinedp(my["max_kee"]) ) {
        if ( my["age"] <= 14 ) my["max_kee"] = 100;
        else if ( my["age"] <= 30 )
            my["max_kee"] = 100 + (my["age"] - 14) * my["con"];
        else my["max_kee"] = 100 + 16 * my["con"];

        if ( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;

        if ( my["max_kee"] < 1 ) my["max_kee"] = 1; //mon 1/28/98
    }

    if ( userp(ob) || undefinedp(my["max_sen"]) ) {
        if ( my["age"] <= 14 ) my["max_sen"] = 100;
        else if ( my["age"] <= 30 )
            my["max_sen"] = 100 + (my["age"] - 14) * my["spi"];
        else if ( my["age"] <= 40 ) my["max_sen"] = 100 + 16 * my["spi"];
        else {
            //when age>40, max_sen will drop...but if you have
            //"always_young"(defined in "look.c"), only drop 
            //to atmost your "faked_age"...weiqi,062897.
            if ( my["always_young"] ) {
                if ( my["fake_age"] <= 40 )
                    my["max_sen"] = 100 + 16 * my["spi"];
                else
                    my["max_sen"] = 100 +16 * my["spi"] - (my["fake_age"] - 40) * 5;
            } else
                my["max_sen"] = 100 +16 * my["spi"] - (my["age"] - 40) * 5;
        }

        if ( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"]*2 / 5;
        //here we make mana very useful, so set divided by 2.5, instead of 4.
        if ( my["max_sen"] < 1 ) my["max_sen"] = 1; //mon 1/28/98
    }

    if ( userp(ob) || undefinedp(my["max_gin"]) ) {
        if ( my["age"] <= 14 ) my["max_gin"] = 100;
        else if ( my["age"] <= 30 )
            my["max_gin"] = 100 + (my["age"] - 14) * my["spi"];
        else if ( my["age"] <= 50 ) my["max_gin"] = 100 + 16 * my["spi"];
        else my["max_gin"] = 100 + 16 * my["spi"]  - (my["age"] - 50) * 5;

        if ( my["max_atman"] > 1000 ) my["max_gin"] += 250;
        else if ( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;

        if ( my["max_gin"] < 1 ) my["max_gin"] = 1; //mon 1/28/98
   }

    if ( undefinedp(my["unit"])) my["unit"]="λ";
    if ( undefinedp(my["gender"])) my["gender"]="����";
    if ( undefinedp(my["can_speak"])) my["can_speak"]=1;
    if ( undefinedp(my["attitude"])) my["attitude"]="peaceful";
    if ( undefinedp(my["sexuality"])) my["sexuality"]="pudency";
    if ( undefinedp(my["limbs"])) my["limbs"]=({
        "ͷ��",   "����",   "�ؿ�",   "����",   "���",   "�Ҽ�",   "���",
        "�ұ�",   "����",   "����",   "����",   "С��",   "����",   "����",
        "���",   "�ҽ�"
        }) ;

//   ob->set_default_object(__FILE__);
    if ( !ob->query_weight() )
        ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
    return combat_action[random(sizeof(combat_action))];
}

mapping query_sex_action(object me)
{
    object ob;
    int female = 0;
    mapping act;
    if (objectp(me->query_temp("sex/fuck_ob"))) {
        ob = me->query_temp("sex/fuck_ob");
        female = ob->query("gender") == "Ů��";
    }
    else if (objectp(me->query_temp("sex/makelove_ob"))) {
        ob = me->query_temp("sex/makelove_ob");
        female = ob->query("gender") == "Ů��";
    }
    for (act = sex_action[random(sizeof(sex_action))];
        !female && (act["limb"]=="pussy"||act["limb"]=="breast");
        act = sex_action[random(sizeof(sex_action))])
        ;
    return act;
}

mapping query_fuck_action(object me)
{
    if (random(2)) return query_sex_action(me);
    else return sex_fuck_action[random(sizeof(sex_fuck_action))];
}
