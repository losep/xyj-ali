// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// snowcat

void greeting1(object who)
{
    object me = this_object();
    
    if (!visible(who))
        return;
    if (me->is_fighting())
        return;
    
    if (who->query("obstacle/number") > 0) {
        remove_call_out("greeting1_callout");
        call_out("greeting1_callout", 1, me, who);
    }
}

void greeting1_callout(object me, object who)
{
    string str;
    object weapon = me->query_temp("weapon");
    
    if (weapon)
        str = "$N�������е�"+weapon->query("name")+"��$n����";
    else
        str = "$N������$n����";
    str += RANK_D->query_respect(who)+"����ȡ��������ب�ţ�\n";
    
    message_vision(str, me, who);
}

void greeting2 (object who)
{
    object me = this_object();
    
    if (!visible(who))
        return;
    if (me->is_fighting())
        return;
    
    if (who->query("quest/reward") > 0) {
        remove_call_out("greeting1_callout");
        call_out("greeting1_callout", 1, me, who);
    }
}

void greeting2_callout(object me, object who)
{
    string str;
    str = "$N��$nһ����"+RANK_D->query_respect(who)+
        "�����������֣�����ȥ�ݼ�����̫�ڣ�\n";
    message_vision(str, me, who);
}