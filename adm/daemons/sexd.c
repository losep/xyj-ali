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
   if (ratio < 60) return RED "����󺹣���ͬˮ���̳�����һ����" NOR;
   if (ratio < 80) return RED "�Ѿ���ȫ��������������Ԩ����ʶ��Щ�����ˡ�" NOR;
   if (ratio < 90) return HIR "�����¶ȸߵ����ˣ���������ʶ��ͦ���ţ������������������������" NOR;
   return HIR "�Ѿ���������ʶ״̬������ʶ������ӭ�϶�������������Ҫֹͣ�ˡ�" NOR;
}

string female_status_msg(int ratio)
{
   if (ratio == 0) return HIG "Ŀɫ����������������ɫ�ʡ�" NOR;
   if (ratio < 10) return HIG "Ŀɫ���룬��Ϣ��Щɢ�ҡ�" NOR;
   if (ratio < 20) return HIY "������Щ���أ�����΢΢��Щ���ߡ�" NOR;
   if (ratio < 40) return HIY "����糺죬��������������������" NOR;
   if (ratio < 60) return RED "�㺹���죬��ʶ��Щģ����" NOR;
   if (ratio < 80) return RED "�Ѿ���ȫ����������������Ԩ������������ͦ������֫��" NOR;
   if (ratio < 90) return HIR "�����¶ȸߵ����ˣ���������ʶ��ͦ���ţ����к���������������" NOR;
   return HIR "�Ѿ���������ʶ״̬������ʶ������ӭ�϶�����ӣ����Ȼ�⶯��ȴ�Ѿ��޷������κ�������" NOR;
}

void report_sex_status(object ob)
{
    if (ob->query("gender") == "Ů��")
        message_vision("( $N" + female_status_msg(
                (int)ob->query("libido")) 
                + " )\n", ob);
    else
        message_vision("( $N" + male_status_msg(
                (int)ob->query("libido")) 
                + " )\n", ob);
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

    attacker->set_temp("sufferer", sufferer);
    sufferer->set_temp("attacker", attacker);
    tell_object(attacker, HIR + "���"+penis+"�Ѿ�������"+sufferer->name()+"��"+pussy+"������\n" + NOR);
    tell_object(sufferer, HIR + attacker->name() +"��"+penis+"�Ѿ����������"+pussy+"������\n" + NOR);
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

    attacker->delete_temp("sufferer");
    sufferer->delete_temp("attacker");
    tell_object(attacker, HIB + "�㽫"+penis+"�γ���"+sufferer->name()+"��"+pussy+"������\n" + NOR);
    tell_object(sufferer, HIB + attacker->name() +"��"+penis+"�γ������"+pussy+"������\n" + NOR);
}

int do_makelove(object me, object victim, int is_fucking)
{
    mapping action;
    string actionstr, effectstr, sens;
    int me_fascination, victim_fascination, hit, back;

    if (is_fucking) {
        if (me->query_temp("sufferer") != victim
        || victim->query_temp("attacker") != me)
            return 0;
        action = me->query("fuck_actions");
    }
    else
        action = me->query("sex_actions");
        
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

    me_fascination = me->query_skill("fascination") / 10;
    victim_fascination = victim->query_skill("fascination") / 10;
    hit = me_fascination < random(victim_fascination + victim->query_cps() / 10 - 5);
    back = me_fascination + me->query_cps() / 10 < random(victim_fascination + 10);
    if (hit)
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
        victim->sex_inspire("libido", action["enjoy"]);
    }
    if (back) {
        message_vision("��$NҲ���þ���һ��һ���������Ȼ������\n", me);
        report_sex_status(me);
        me->sex_inspire("libido", action["self_enjoy"]);
    }

    me->sex_inspire("stamina", action["cost"]);

    if (me->query("libido")>=100)
        me->orgasm();

    if (victim->query("libido")>=100)
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

