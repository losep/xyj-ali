// clear error

inherit F_CLEAN_UP;

int main(object me)
{
    me->delete_temp("error");
    write("Ok.\n");
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : clrer

�ȼ���call me->delete("error")
HELP
    );
    return 1;
}
