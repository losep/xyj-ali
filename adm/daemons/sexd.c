// ALI by NewX

#include <ansi.h>

string *penis_names = ({ "���", "����", "����", "����", "����", "��ǹ", "��ǹ", "����" });
string *pussy_names = ({ "����", "���", "���", "�ܵ�", "��з", "����", "����", "��Ѩ", "��Ѩ", "��Ѩ", "�ۺ�" });
string *ass_names = ({ "�ջ�", "��Ѩ", "�ո�", "�ؾ�", "����", "ѩ��", "����" });
string *finger_names = ({ "��ָ", "��ָ" });
string *breast_names = ({ "�鷿", "����", "����", "����", "���", "����", "����", "��ͷ", "���" });
string *sensitive_names_m = ({ "����", "��ͷ" });
string *sensitive_names_f = ({ "����", "����", "��", "��", "���", "����", "����", "����", "����", "����" });

string male_status_msg(int ratio)
{
   if (ratio == 0) return HIG "Ŀɫ����������������ɫ�ʡ�" NOR;
   if (ratio < 10) return HIG "Ŀɫ���룬��Ϣ��Щɢ�ҡ�" NOR;
   if (ratio < 20) return HIY "������Щ���أ�����΢΢��Щ���ߡ�" NOR;
   if (ratio < 40) return HIY "����ͨ�죬������ţ��" NOR;
   if (ratio < 60) return HIR "����󺹣���ͬˮ���̳�����һ����" NOR;
   if (ratio < 80) return HIR "�Ѿ���ȫ��������������Ԩ����ʶ��Щ�����ˡ�" NOR;
   if (ratio < 90) return RED "�����¶ȸߵ����ˣ���������ʶ��ͦ���ţ������������������������" NOR;
   return RED "�Ѿ���������ʶ״̬������ʶ������ӭ�϶�������������Ҫֹͣ�ˡ�" NOR;
}

string female_status_msg(int ratio)
{
   if (ratio == 0) return HIG "Ŀɫ����������������ɫ�ʡ�" NOR;
   if (ratio < 10) return HIG "Ŀɫ���룬��Ϣ��Щɢ�ҡ�" NOR;
   if (ratio < 20) return HIY "������Щ���أ�����΢΢��Щ���ߡ�" NOR;
   if (ratio < 40) return HIY "����糺죬��������������������" NOR;
   if (ratio < 60) return HIR "�㺹���죬��ʶ��Щģ����" NOR;
   if (ratio < 80) return HIR "�Ѿ���ȫ����������������Ԩ������������ͦ������֫��" NOR;
   if (ratio < 90) return RED "�����¶ȸߵ����ˣ���������ʶ��ͦ���ţ����к���������������" NOR;
   return RED "�Ѿ���������ʶ״̬������ʶ������ӭ�϶�����ӣ����Ȼ�⶯��ȴ�Ѿ��޷������κ�������" NOR;
}

void report_sex_status(object ob)
{
    if (ob->query("gender") == "Ů��")
        message_vision("( $N" + female_status_msg((int)ob->query("lust")) + " )\n",
            ob);
    else
        message_vision("( $N" + male_status_msg((int)ob->query("lust")) + " )\n",
            ob);
}

void announce(object ob, string event)
{
    object makelover = ob->query_temp("sex/makelove_ob");
    object fucker = ob->query_temp("sex/fuck_ob");
    switch (event) {
        case "erect":
            message_vision(HIR "\n$N��" + penis_names[random(sizeof(penis_names))] + "��ǿ��ͦ����������\n\n" NOR, ob);
            break;
        case "wet":
            message_vision(HIR "\nһ����֭��$N��" + pussy_names[random(sizeof(pussy_names))] + "����ӿ������$P��Ȼ�Ѿ����飡\n\n" NOR, ob);
            break;
        case "no_erect":
            message_vision(HIC "\n�������������ˣ�$N��" + penis_names[random(sizeof(penis_names))] + "Ҳ�𽥻ָ��˳�̬��\n\n" NOR, ob);
            break;
        case "no_wet":
            message_vision(HIC "\n�������������ˣ�$NҲ�𽥻ָ��˳�̬��\n\n" NOR, ob);
            break;
        case "ejaculate":
            if (!objectp(fucker)) {
                message_vision(HIR "\n$N��" + penis_names[random(sizeof(penis_names))] + "�������һ��������\n\n" NOR, ob);
            } else {
                tell_object(fucker, "\n" + HIR + ob->name() + "�侫�ˣ�ǿ��ĳ�������ҵĳ������Ļ��ģ�\n\n" NOR);
            }
            break;
        case "orgasm":
            tell_room(environment(ob), HIR "\n" + ob->name() + "�Ļ�����ҵĲ��������з���������ļ�У�������ʢ����һ����糺�Ļ���...\n���Ѿ��ﵽ�˿�е��۷壡\n\n" NOR, ({ob}));
            if (objectp(fucker)) {
                tell_object(fucker, HIR + "��е�" + ob->name() + "��" + pussy_names[random(sizeof(pussy_names))] + "һ������ҵ�������һ�������ӻ�������ӿ�����������������"+penis_names[random(sizeof(penis_names))]+"�ϣ�\n\b" NOR);
            }
            break;
    }
}

void gain_enjoy(object ob, string event)
{
    switch (event) {
        case "ejaculate":
            break;
        case "orgasm":
            break;
    }
}

object get_attacker(object me, object ob)
{
    if (me->query("gender") == ob->query("gender")) {
        if (ob->query_temp("sex_initiative") > me->query_temp("sex_initiative")) {
            return ob;
        } else {
            return me;
        }
    } else {
        if (me->query("gender") == "����") {
            return me;
        } else {
            return ob;
        }
    }
}

object get_sufferer(object me, object ob)
{
    if (me->query("gender") == ob->query("gender")) {
        if (me->query("sex_initiative") >= ob->query("sex_initiative")) {
            return ob;
        } else {
            return me;
        }
    } else {
        if (me->query("gender") == "����") {
            return ob;
        } else {
            return me;
        }
    }
}

void push_penis(object me, object ob)
{
    object attacker, sufferer, penis_ob;
    string penis, pussy;

    attacker = get_attacker(me, ob);
    sufferer = get_sufferer(me, ob);

    if (attacker->query("gender") == "����") {
            penis = penis_names[random(sizeof(penis_names))];;
    } else {
        penis_ob = attacker->query_temp("penis");
        if (objectp(penis_ob)) {
            penis = penis_ob->name();
        } else {
            penis = finger_names[random(sizeof(finger_names))];
        }
    }

    if (sufferer->query("gender") == "Ů��") {
        pussy = pussy_names[random(sizeof(pussy_names))];
    } else {
        pussy = ass_names[random(sizeof(ass_names))];
    }

    attacker->set_temp("sex/fuck_ob", sufferer);
    sufferer->set_temp("sex/fuck_ob", attacker);
    attacker->fuck_ob(sufferer);
    sufferer->fuck_ob(attacker);
    if (attacker->add_temp("no_move", -1) <= 0) attacker->delete_temp("no_move");
    if (sufferer->add_temp("no_move", -1) <= 0) sufferer->delete_temp("no_move");
    tell_object(attacker, HIR + "\n\n���"+penis+"�Ѿ�������"+sufferer->name()+"��"+pussy+"������\n" + NOR);
    tell_object(sufferer, HIR + "\n\n" + attacker->name() +"��"+penis+"�Ѿ����������"+pussy+"������\n" + NOR);
}

void pull_penis(object me, object ob)
{
    object attacker, sufferer, penis_ob;
    string penis, pussy;

    if ( me->query_temp("sufferer") == ob
       || ob->query_temp("attacker") == me ) {
        attacker = me;
        sufferer = ob;
    } else if ( me->query_temp("attacker") == ob
            || ob->query_temp("sufferer") == me ) {
        attacker = ob;
        sufferer = me;
    } else
        return;

    if (attacker->query("gender") == "����") {
            penis = penis_names[random(sizeof(penis_names))];;
    } else {
        penis_ob = attacker->query_temp("penis");
        if (objectp(penis_ob)) {
            penis = penis_ob->name();
        } else {
            penis = finger_names[random(sizeof(finger_names))];
        }
    }

    if (sufferer->query("gender") == "Ů��") {
        pussy = pussy_names[random(sizeof(pussy_names))];
    } else {
        pussy = ass_names[random(sizeof(ass_names))];
    }

    attacker->delete_temp("sex/fuck_ob");
    sufferer->delete_temp("sex/fuck_ob");
    tell_object(attacker, HIB + "\n\n�㽫"+penis+"�γ���"+sufferer->name()+"��"+pussy+"������\n" + NOR);
    tell_object(sufferer, HIB + "\n\n" + attacker->name() +"��"+penis+"�γ������"+pussy+"������\n" + NOR);
}

int is_fucking(object ob1, object ob2)
{
    return ob1->query_temp("sex/fuck_ob") == ob2 &&  ob2->query_temp("sex/fuck_ob") == ob1;
}

int do_makelove(object me, object victim, int is_fucking)
{
    mapping action;
    string actionstr, effectstr, sens;
    int me_ap, victim_ap, me_dp, victim_dp, hit, back;

    if (is_fucking) {
        if (!is_fucking(me, victim)) {
            push_penis(me, victim);
            return 0;
        }
        action = me->query("fuck_actions");
    }
    else {
        if (me->query_temp("sex_heat")
        &&  victim->query_temp("sex_heat")
        &&  !is_fucking(me, victim)
        &&  random(2) == 1) {
            push_penis(me, victim);
            return 0;
        }
        action = me->query("sex_actions");
    }
        
    if (victim->query("gender")=="Ů��") {
        switch (random(4)) {
            case 0:
                sens = pussy_names[random(sizeof(pussy_names))];
                break;
            case 1:
                sens = ass_names[random(sizeof(ass_names))];
                break;
            case 2:
                sens = breast_names[random(sizeof(breast_names))];
                break;
            case 3:
                sens = sensitive_names_f[random(sizeof(sensitive_names_f))];
                break;
            default:
                sens = pussy_names[random(sizeof(pussy_names))];
                break;
        }
    } else {
        switch (random(2)) {
            case 0:
                sens = penis_names[random(sizeof(penis_names))];
                break;
            case 1:
                sens = sensitive_names_m[random(sizeof(sensitive_names_m))];
                break;
            default:
                sens = penis_names[random(sizeof(penis_names))];
                break;
        }
    }

    actionstr = action["action"];
    actionstr = replace_string(actionstr, "$s", sens);
    actionstr = replace_string(actionstr, "$L", penis_names[random(sizeof(penis_names))]);
    actionstr = replace_string(actionstr, "$l", pussy_names[random(sizeof(pussy_names))]);
    actionstr = replace_string(actionstr, "$b", breast_names[random(sizeof(breast_names))]);

    me_ap = me->query_per();
    victim_ap = victim->query_per();
    me_dp = me->query_cps();
    victim_dp = victim->query_cps();
    hit = me_ap > random(victim_dp * 3 / 4);
    back = me_dp < random((victim_dp + victim_ap) * 1 / 2);
    if (!hit)
        effectstr = "Ū��$n����һ������æ����һ����������û��ʧ��";
    else {
        if (undefinedp(action["effect"]))
            effectstr = "Ū��$n����һ�����ƺ��Ѿ���������";
        else
            effectstr = action["effect"];
    }

    message_vision("\n" + actionstr + "��\n", me, victim);
    message_vision("���" + effectstr + "��\n", me, victim);
    if (hit) {
        report_sex_status(victim);
        victim->sex_excite("lust", action["enjoy"]);
    }
    if (back) {
        if (hit)
            message_vision("��$NҲ���þ���һ��һ���������Ȼ������\n", me);
        else
            message_vision("������$N��������һ����һ���������Ȼ������\n", me);
        report_sex_status(me);
        me->sex_excite("lust", action["self_enjoy"]);
    }

    //me->add("atman", -action["cost"]);

    if (me->query("lust")>=100)
        me->orgasm();

    if (victim->query("lust")>=100)
        victim->orgasm();

    return action["damage"];
}

void makelove(object me, object victim)
{
    if (me->query_temp("sex/fuck_ob") == victim) {
        do_makelove(me, victim, 1);
    } else {
        do_makelove(me, victim, 0);
    }
}

