// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// atoi.c

int atoi(string str)
{
   int v;

   if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
   return v;
}
