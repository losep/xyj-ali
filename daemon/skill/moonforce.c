// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// moonforce.c  ��̫���ľ���
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
    return notify_fail("̫���ľ�ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
    return CLASS_D("girl") + "/moonforce/" + func;
}

int help(object me)
{
    write(@HELP
��̫���ľ���
����������̫���ǣ���̫��֮�����۶��ɣ���ʱ�޿̲���ɢ����̫��
�»����¹�һ����ѧ�����Ļ�����������̫���»���
�¹�ԭ�����ڹ��ķ���Ϊ��Բ���ķ�����ֻ��һ�ײɼ��»����̱���
Ԫ���ľ�����Ϊ�ֱɡ�
��槼�һս������ĸ����Բ���ķ�������������ˡ�̫���ľ�����
��ʱ����������
̫���ľ���ԭ��������ֲŮ�Ե���֮�ڵ�������Ԫ�������ڵ�̫��
���������������̫�������������гɺ󣬿����ڵ����������һ��
��̫�����֡���ʹ�����ڲ���������Ϣ��������

�����ⷨ�š�
��  ����  exert heal
��  ����  exert moon(δʵ��)
��  ӳ��  exert sun
HELP);
    return 1;
}

