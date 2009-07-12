// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);
int main(object me, string arg)
{
   object obj;
   string *killer, callname;

   if( !wizardp(me) && environment(me)->query("no_fight") )
     return notify_fail("���ﲻ׼ս����\n");

   if( !arg )
     return notify_fail("����ɱ˭��\n");

   if(!objectp(obj = present(arg, environment(me))))
     return notify_fail("����û������ˡ�\n");

   if( !obj->is_character() || obj->is_corpse() )
     return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

   if(obj==me)
     return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

        if(!valid_kill(me,obj)) return 0;

   callname = RANK_D->query_rude(obj);

   message_vision("\n$N����$n�ȵ�����" 
     + callname + "�����ղ������������һ��\n\n", me, obj);   

   do_kill(me, obj);

   return 1;
}
void do_kill(object me, object obj)
{
   me->kill_ob(obj);
   if( !userp(obj) )
     if(!obj->accept_kill(me) )
     obj->kill_ob(me);
   else {
     obj->fight_ob(me);
     tell_object(obj, HIR "�����Ҫ��" + me->name() 
        + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
   }

}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ����˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ����� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬����һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
