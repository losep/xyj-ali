// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dump.c (should be admin cmd?)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
   seteuid(geteuid(me));

    dumpallobj();

   return 1;
}

int help(object me)
{
   write(@HELP
ָ���ʽ : dump
 
dump the stats of all objects to a file in root dir 
named OBJ_DUMP.

HELP
    );
    return 1;
}
 
