// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string key, chinz;
    
    if( !arg || arg=="" )
        return notify_fail("ָ���ʽ��chinese <Ӣ��>==<����>\n");
    
    if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
        if (chinz != "") {
            CHINESE_D->add_translate(key, chinz);
            write( key + " == " + chinz + "\nOk.\n");
        }
        else {
            CHINESE_D->remove_translate(key);
            write(key + " remove OK.\n");
        }
        return 1;
    }
    
    return 0;
}

int help()
{
    write ( @HELP
���Ӷ��գ�chinese <Ӣ��>==<����>
ɾ�����գ�chinese <Ӣ��>==<>
HELP
    );
    return 1 ;
}
