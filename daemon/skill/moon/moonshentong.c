// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// moonshentong.c ��̫���ɾ���
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("spells", 1) < 10
        || (int)me->query_skill("spells", 1) <=
            (int)me->query_skill("moonshentong", 1))
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ̫���ɾ���\n");
    return 1;
}

string cast_spell_file(string spell)
{
    return CLASS_D("girl") + "/moonshentong/" + spell;
}

int help(object me)
{
    write(@HELP
��̫���ɾ���
�����������¹�����ɫ�����¹��ɷ������ǽ����»��е�̫��֮����
�У����˷���ʤ����
��槼�һս������ĸ���ڡ��¹��ɷ����д����������˹�Ĺ���أ�
ʹ���¹��ķ���ˮƽ������һ��¥�������¹��ɷ����ݱ���ˡ�̫��
�ɾ�����
��̫���ɾ�����ԭ��ͬ��Ҳ�Ǹ���ǿ��ʩ�������ڵ�������Ԫ����
���ڵ���Ԫ���������̫��֮�����Ӷ�ʹ�÷�������׼�������ܡ�
�����������Ĺ���صĴ��۾���ʹ��ԭ��ǿ����ʥ������¹�������
Ⱦ����һ���Ĺ������ɫ�ʡ��Դˣ���Щ�����������飬����������
ĸ��ǿ�������£��¹������ĸ���������������ȥ��

�����ⷨ�š�
��  ������     cast bow
��  �������     cast arrow on <object>
��  �������     cast invocation on <object>
��  �Ի�         cast mihun on <object>
��  ����         cast huimeng on <object>
��  ʴ��         cast shiyue on <object>
HELP);
    return 1;
}

