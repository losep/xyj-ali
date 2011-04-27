// conjure.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string magic, mgc, trg;
    object target;

    seteuid(getuid());

    if (me->is_busy())
        return notify_fail("( ����һ��������û����ɣ�����ʩչ��ͨ��)\n");

    if (!wizardp(me) && environment(me)->query("no_magic"))
        return notify_fail("�����޷�ʹ����ͨ��\n");

    if (!arg) return notify_fail("ָ���ʽ��conjure <��ͨ> [on <Ŀ��>]\n");
    if (sscanf(arg, "%s on %s", mgc, trg) == 2) {
        target = present(trg, environment(me));
        if (!target) target = present(trg, me);
        if (!target) return notify_fail("����û�� " + trg + "��\n");
        
        if (!"/adm/daemons/tempd"->valid_kill(me, target)) return 0;
        if (userp(me) && userp(target) && target->query_temp("netdead"))
            return notify_fail("�Է����ڶ����У����ܶ���ʩ����\n");
    } else {
        mgc = arg;
        target = 0;
    }

    mgc = replace_string(mgc, " ", "_");

    if (stringp(magic = me->query_skill_mapped("magic"))) {
        notify_fail("����ѧ����ͨ��û�����ֹ��ܡ�\n");
        if (!(int)SKILL_D(magic)->conjure_magic(me, mgc, target))
            return (int)SKILL_D("magic")->conjure_magic(me, mgc, target);
        return 1;
    }

    return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ���ͨϵ��\n");
}

int help (object me)
{
    write(@HELP
ָ���ʽ��conjure <��ͨ����> [on <ʩչ����>]

ʩչ��ͨ�������Ҫָ��<��ͨ����>��<ʩչ����>����п��ޡ�
����ʹ��ĳһ����֮ͨǰ����������� enable ָ����ָ����Ҫʹ�õ���ͨϵ��

ע�������ı��Լ�����ͨϵ����ԭ���������Ԫ������ֱ��ת����ȥ������
    �� 0 ��ʼ��
HELP
    );
    return 1;
}
