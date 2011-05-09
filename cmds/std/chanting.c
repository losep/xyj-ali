// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void finish(object me, int exp_gain);

int main(object me, string arg)
{
    int busy_time, exp_gain;
    int xiudao_lvl;
    mapping fam;
    object where;

    seteuid(getuid());
    where = environment(me);

    if (where->query("no_fight") || where->query("no_magic"))
            return notify_fail("��ȫ���ڽ�ֹ������\n");

//    if (!where->query("jingzuo_room"))
//        return notify_fail("�˴����˾���������\n");

    if ((xiudao_lvl = me->query_skill("spells")) < 20)
        return notify_fail("�㷨����Ϊ̫�ͣ������й�������\n");
    if (me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("��������æ���ء�\n");
    if (me->is_fighting())
        return notify_fail("ս�����޵�������������\n");
    if ((int)me->query("sen") * 100 / (int)me->query("max_sen") < 50)
        return notify_fail("���������ǲ��壬��������Ҫ�߻���ħ��\n");
    if ((int)me->query("kee") * 100 / (int)me->query("max_kee") < 50)
        return notify_fail("����������������������Ҫ�����ˣ�\n");

    exp_gain = xiudao_lvl/20 + random(3);
    busy_time = random(7200)/exp_gain/100;
    exp_gain = 1 + random(exp_gain*2);
    busy_time *= exp_gain;
    exp_gain = OBSTACLES_D->xiudao_accelerate(me, exp_gain);
    if (me->query("food") + me->query("water") < 20) busy_time *= 2;
    message_vision(HIY "$N�����۾�����ϥ���£�����ĬĬ���֪��˵Щʲô��\n" NOR, me);
    me->start_busy(busy_time);
    call_out("finish", busy_time, me, exp_gain);
    return 1;
}

void finish(object me, int exp_gain)
{
    string *msg = ({
        "����Ϊ�࣬����ƣ�ͣ���̰����������Ϊ���������ڡ�",
        "и��׹�䣬���о������Ʒ��ն񣬴ݷ���ħ������������",
        "�޳����������������ѧ���ţ������ǻۣ��ɾͱ�ţ��̻�һ�У�Ϥ�Դ��֡�",
        "ƶ���Թ������Ե��������ʩ������Թ�ף�����ɶ񣬲������ˡ�",
        "������ȼ������������������ģ��ռ�һ�С�",
        "Ը���������������࣬�����������Ͼ����֡�",
        "Ը�Դ˹��£�ׯ�Ϸ������ϱ����ض����¼���;�ࡣ",
        "���м����ߣ�Ϥ�������ģ���������������������顣",
    });
    if (me->query("class") != "bonze") msg = ({
        "���ɵ����ǳ��������������ǳ�����",
        "���������֮ʼ������������֮ĸ��",
        "���½�֪��֮Ϊ����˹���ѣ���֪��֮Ϊ�ƣ�˹�����ѡ�",
        "��ز��ʣ�������Ϊۻ����ʥ�˲��ʣ��԰���Ϊۻ����",
        "����������ν��������֮�ţ���ν��ظ����������棬��֮���ڡ�",
        "����ϣ������壻�ǻ۳����д�α�����ײ��ͣ���Т�ȣ����һ��ң����ҳ���",
        "֪�����ǣ���֪������ʤ������������ʤ��ǿ��֪���߸���ǿ������־����ʧ�����߾ã������������١�",
        "������Ϊ���޲�Ϊ������������֮�����ｫ�Ի���",
    });
    message_vision(HIY "$N���������"+msg[random(sizeof(msg))]+"\n" NOR, me);
    message_vision(HIY "$N���������۾�������һ����վ��������\n" NOR, me);

    tell_object(me, HIC "��ĵ���������" + chinese_number(exp_gain*3) + "ʱ����\n" NOR);
    me->add("combat_exp", exp_gain);

    if (me->query("food") >= exp_gain) me->add("food",-exp_gain);
    else me->set("food", 0);

    if (me->query("water") >= exp_gain) me->add("water",-exp_gain);
    else me->set("water", 0);

    me->receive_damage("sen", me->query("int"));
    me->receive_damage("kee", me->query("int"));
    me->improve_skill("spells", random(exp_gain));

    me->start_busy(1);
}

int help(object me)
{
    write(@HELP
ָ���ʽ : chanting

�о���������ߵ��С�
HELP
    );
    return 1;
}
