// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string target, item;
    object obj, who, *inv, obj2;
    int i, amount, rev_val;
    mixed no_give;

    if (me->is_busy())
        return notify_fail("����æ���أ�����\n");

    if (!arg) return notify_fail("��Ҫ��˭ʲô������\n");

    if (sscanf(arg, "%s to %s", item, target)==2
    ||  sscanf(arg, "%s %s", target, item)==2)
        ;
    else
        return notify_fail("��Ҫ��˭ʲô������\n");

    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");

    if (me == who) {
        write("Ok.\n");
        return 1;
    }


    if (sscanf(item, "%d %s", amount, item)==2) {
        if (!objectp(obj = present(item, me)))
            return notify_fail("������û������������\n");
        if (!obj->query_amount())
            return notify_fail(obj->name() + "���ܱ��ֿ����ˡ�\n");
        if (amount < 1)
            return notify_fail("����������������һ����\n");
        if (amount > obj->query_amount())
            return notify_fail("��û����ô���" + obj->name() + "��\n");
        else if (amount == (int)obj->query_amount())
            return do_give(me, obj, who);
        else {
            obj2 = new(base_name(obj));
            obj2->set_amount(amount);
            rev_val = do_give(me, obj2, who);
            if (rev_val == 2) {
                if (obj)
                    obj->set_amount((int)obj->query_amount() - amount);
            } else
                destruct(obj2);
            return rev_val; 
        }
    }

    if (arg=="all") {
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
            if (inv[i]->query("no_give")) continue;
            do_give(me, inv[i], who);
        }
        write("Ok.\n");
        return 1;
    }

    if (!objectp(obj = present(item, me)))
        return notify_fail("������û������������\n");
    return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
    int is_accept;
    object *inv;
    mixed no_give;

    if (me->is_busy())
        return notify_fail("����æ���أ�����\n");
    if (who->is_busy())
        return notify_fail("�Է���æ���أ�ûʱ�����㣮����\n");
    // no_accept should be in do_give Bula
    if (who->query("env/no_accept"))
        return notify_fail("�Է�����Ը��������Ķ�����\n");
    if (no_give=obj->query("no_give"))
        return notify_fail(stringp(no_give) ? no_give : "���������������ⶪ����\n");
/*
   inv = all_inventory(who);
   if( sizeof(inv) > 30 )
      return notify_fail("�Է�������Ҳװ�����κζ����ˡ�\n");
*/
    if (!userp(who) && QUEST_D->quest_give(me, who, obj)) {
        message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n", me, who);
        message_vision("$N���Ե���$n��л��\n", who ,me);
        destruct(obj);
        return 1;
    } 
    if (!userp(who)) {
        notify_fail("�Է���Ҫ��Ķ�����\n");
        is_accept=who->accept_object(me, obj);
        if (is_accept == 0)
            return 0;
        else if (is_accept == 2) // if accept_object() return 2, the 'who' will do all the things.
            return 1;
        else {
            if (obj->value()) { // give money to npc
                message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
                destruct(obj);
                return 2;
            }
            else if (obj->move(who)) {
                string unit;
                if (obj->query_temp("d_mana")>0)
                    unit=obj->query_temp("unit");
                else
                    unit=obj->query("unit");
                if (strlen(unit)<2) unit="��";
                message_vision(sprintf("$N��$nһ%s%s��\n", unit, obj->name()), me, who);
                //if (!userp(who) && !userp(obj)) destruct(obj);
                who->receive_object(me, obj);
                return 2;
            }
            else
                return 0;
        }
    }
    else if (obj->move(who)) {
        string unit;
        if (obj->query_temp("d_mana")>0)
            unit=obj->query_temp("unit");
        else
            unit=obj->query("unit");
        if (strlen(unit)<2) unit="��";
        message_vision(sprintf("$N��$nһ%s%s��\n", unit, obj->name()), me, who);
        return 2;
    }
    else
        return 0;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.

������ʱ : set no_accept <����ֵ>
���½��� : unset no_accept
HELP
    );
    return 1;
}
