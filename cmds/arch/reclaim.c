// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// reclaim.c

int main(object me, string arg)
{
   int mem;

   write("������������� " + reclaim_objects() + " ��������\n");
   return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : reclaim

�ô� : �������ڼ����������õı��������, �Լ��ټ������ʹ�á�
HELP
     );
     return 1;
}
