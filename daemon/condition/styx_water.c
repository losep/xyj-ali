// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// styx_water.c ڤ��ˮ

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    int limit;

    limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

    if (living(me)) {
        if (duration > limit) {
            me->unconcious();
            return 0;
        }
        else {
            tell_object(me, "�����һ��ѣ�Σ����ˣ����ú�ڤ��ˮ�ģ�\n");
            message("vision", me->name() + "��ɫ�԰ף��ƺ������Ϊ���ס�\n",
                environment(me), me);
            me->receive_damage("gin", 10);
        }
    }

    me->apply_condition("styx_water", duration - 1);
    if (!duration) return 0;
    return 1;
}
