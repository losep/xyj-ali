// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") <
(int)me->query_skill("yunshouforce") * 50 )
                return
notify_fail("���ɱ���������޷����������������񹦣�\n");

        return 1;
}

int practice_skill(object me)
{
        return
notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("puti") + "/wuxiangforce/" + func;
}

