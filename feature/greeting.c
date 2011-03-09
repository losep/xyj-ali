// ALi by NewX

void greeting_for_obstacle(object who)
{
    object me = this_object();
    
    if (!me->visible(who))
        return;
    if (me->is_fighting())
        return;
    
    if (who->query("obstacle/number") > 0) {
        remove_call_out("greeting_for_obstacle_callout");
        call_out("greeting_for_obstacle_callout", 1, me, who);
    }
}

void greeting_for_obstacle_callout(object me, object who)
{
    string str;
    object weapon = me->query_temp("weapon");
    
    if (environment(me)!=environment(who))
        return;

    if (weapon)
        str = "$N�������е�"+weapon->query("name")+"��$n����";
    else
        str = "$N������$n����";
    str += RANK_D->query_respect(who)+"����ȡ��������ب�ţ�\n";

    message_vision(str, me, who);
}

void greeting_for_quest(object who)
{
    object me = this_object();
    
    if (!me->visible(who))
        return;
    if (me->is_fighting())
        return;
    
    if (who->query("quest/reward") > 0) {
        remove_call_out("greeting_for_quest_callout");
        call_out("greeting_for_quest_callout", 1, me, who);
    }
}

void greeting_for_quest_callout(object me, object who)
{
    string str;
    
    if (environment(me)!=environment(who))
        return;

    str = "$N��$nһ����"+RANK_D->query_respect(who)+
        "�����������֣�����ȥ�ݼ�����̫�ڣ�\n";
    message_vision(str, me, who);
}