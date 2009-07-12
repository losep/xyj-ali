// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// animate.c

inherit F_CLEAN_UP;

int cast(object me, object target)
{
   if( me->is_fighting() )   return notify_fail("������ս���У�\n");
   
   if( !target || !target->is_corpse() ) return notify_fail("��Ҫ������һ�ߡ��壿\n");
   
   if( (int)me->query("mana") < 200 ) return notify_fail("��ķ���������\n");

   message_vision(
     "$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, target);

   target->animate(me, (int)me->query_skill("spells") * 3 + 30);

   me->add("mana", -100);
   me->receive_damage("sen", 50);

   return 3+random(5);
}
