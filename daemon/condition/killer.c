// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// iceshock.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

   me->apply_condition("killer", duration - 1);

   if( duration < 1 ) return 0;

   return CND_CONTINUE;
}
