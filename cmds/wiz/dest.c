// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string option, target, msg;
    object obj, *body, ob, *clones;
    int i;

    if (!arg) return notify_fail("ָ���ʽ : dest <���֮���ƻ���>\n" );

    if (sscanf(arg, "%s %s", option, target)!=2) target = arg;
    if (option != "-r" && option != "-p" && option != "-c") target = arg;

    // added by mon. 3/12/97
    if (arg == "-p") {
        body = children(USER_OB);
        for (i=0; i<sizeof(body); i++) {
            ob = body[i];
            if (clonep(ob) && ob->query("max_gin")==0)
                write(getuid(ob)+" "+ob->short()+"\n");
        }
        return 1;
    }

    if (option == "-c") {
        seteuid(geteuid(me));
        clones = children(target);
        if (!clones || !sizeof(clones)) return notify_fail("û�����������\n");
        
        for (i = 0; i<sizeof(clones); i++) {
            ob = clones[i];
            if (environment(ob)) {
                if (environment(ob) == environment(me)) {
                    if (!stringp(msg = me->query("env/msg_dest")))
                        msg = "$N�ٻ���һ���ڶ�����$n��û�ˡ�";
                    message_vision(msg + "\n", me, ob);
                } else {
                    message_vision("����к�Ȼ������һ���ڶ�����$N��û�ˡ�\n", ob);
                }
            }
            printf("�ݻ������%O ", ob);
            destruct(ob);
            if (ob) write("---> �ݻ�ʧ�ܡ�\n");
            else write("---> Ok.\n");
        }
        write("Ok.\n");
        return 1;
    }

    if (option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)")
        seteuid(ROOT_UID);
    else
        seteuid(geteuid(me));

    obj = find_object(target);
    if (!obj) obj = present(target, me);
    if (!obj) obj = present(target, environment(me));
    if (!obj) obj = find_object( resolve_path(me->query("cwd"), target));
    if (!obj) return notify_fail("û�����������\n");

    if (environment(me)==environment(obj)) {
        if (!stringp(msg = me->query("env/msg_dest")))
            msg = "$N�ٻ���һ���ڶ�����$n��û�ˡ�";
        message_vision(msg + "\n", me, obj);
    }
    printf("�ݻ������%O\n", obj);
    destruct(obj);
    if (obj) write("���޷����������ݻ١�\n");
    else write("Ok.\n");

    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : dest [-r|-c] <���֮���ƻ���>
           dest [-p] show damaged player objects.

���ô�һָ��ɽ�һ�����(object)���������(class)�Ӽ�������������������
������(����ָ�������������)����һ�βο�����������ʱ������½������롣

���� (admin) ��ֵ���ʦ������ -r ѡ���� ROOT_UID ���������������������
ʹ���ߡ�

ʹ�� -c ѡ������Դݻ�һ�����������clonep�����

�ο����ϣ� destruct()
HELP
    );
    return 1;
}
