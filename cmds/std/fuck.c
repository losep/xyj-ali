// ALI by NewX

// fuck.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj, old_target;

    if ( !wizardp(me) && environment(me)->query("no_fight") )
        return notify_fail("�����ֹս����\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
        return notify_fail("����XX˭��\n");

    if ( !obj->is_character() )
        return notify_fail("�����һ�㣬�ǲ��������\n");

    if ( obj->is_fucking(me) )
        return notify_fail("���ͣ����ͣ����ͣ�\n");

    if (obj==me)
        return notify_fail("�㲻��fuck�Լ���\n");

    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");

    if (!obj->query("can_speak"))
        return notify_fail("�޽���Ŀǰ�����ṩ���ַ���\n");

    if (userp(obj))
        return notify_fail("������xx�����ǲ����ܵġ�\n");

    message_vision("\n$N��$n˵����"
            + RANK_D->query_self(me)
            + me->name() + "��Ը��"
            + RANK_D->query_respect(obj) + "ͬ�Ǽ��֣���֪"
            + RANK_D->query_respect(obj) + "�Ƿ�Ը�⣡\n\n", me, obj);

    if (!userp(obj)) {
        if (obj->query("sexuality") == "virgin") {
            if (obj->query("class") == "yaomo") {
                message_vision("$N����һ������$n˵��"
                        + RANK_D->query_rude(me) + "�����������ȡ"
                        + RANK_D->query_self_rude(obj) + "��"
                        + (obj->query("gender")=="����" ? "������" : "������")
                        + RANK_D->query_self_rude(obj) + "�Ĳ����㣡\n",
                        obj, me);
            } else {
                message_vision("$N��ɫ��䣬ŭ�ȵ���"
                        + RANK_D->query_rude(me) + "��"
                        + RANK_D->query_self_rude(obj)
                        + "��ǰ��Ȼ˵�������������ҿ����ò��ͷ��ˣ�\n",
                        obj, me);
            }
            me->fuck_ob(obj);
            obj->kill_ob(me);
        } else if (obj->query("sexuality") == "carnality") {
            message_vision("$NЦ����"
                    + RANK_D->query_self(obj)
                    + "��֮���ã�\n", obj);
            me->fuck_ob(obj);
            obj->fuck_ob(me);
        //} else if (obj->query("sexuality") == "pudency") {
        } else {
            message_vision("$N��ʱ����һ�죬��֪������Ǻá�\n", obj);
            tell_object(obj, HIM + me->name() + "�����㷢��һ����Ц����Ȼû��ʲô���ģ�\n" NOR);
            me->fuck_ob(obj);
            obj->fight_ob(me);
        }
    }

    return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : fuck <����>

HELP
    );
    return 1;
}
 
