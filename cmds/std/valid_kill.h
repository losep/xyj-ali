// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by mon

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
     if(userp(victim) && killer->query_condition("no_pk_time")>240 
       && userp(killer))
       return notify_fail("�����ɱ��̫�࣬��ʱ��Ȼ�����������أ��²�ȥ�֡�\n");

     return 1;
}

