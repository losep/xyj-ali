// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//
inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����޷����У�\n");

   if((string)me->query("family/family_name")!="���޵ظ�" )
     return notify_fail("�����Ž��Լ���Ϊ���壬��Ѫ��֮��ȴ��ôҲ��������\n");

        message_vision("$N�૵����˼������\n", me);

   if(me->is_fighting() ) {
     if(random((int)me->query("max_mana")) >
(int)target->query("max_mana")/2) {

message_vision("$N�������һ�ɺڷ磬������Ҳ���źڷ�ɢȥ������\n", me);
me->receive_damage("sen", 100);
me->move("/d/death/gate");
   }
   else
message_vision("$Nת�����ܣ�ȴ��$nһ��������ס��\n", me, target);
me->receive_damage("sen", 100);
   }
   if(!me->is_fighting() ){

message_vision("$N�������һ�ɺڷ磬������Ҳ���źڷ�ɢȥ������\n", me);
   me->receive_damage("sen", 100);
   me->move("/d/death/gate");
   }
//        me->start_busy(1+random(2));
        return 5+random(5);
}

