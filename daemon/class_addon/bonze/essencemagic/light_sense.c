// void_sense.c

#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);
int conjure(object me, object target)
{
	int lvl,i;
	object env, *inv;
	lvl = (int) me->query_skill("magic");
	lvl += (int) me->query("spi");
	if( me->query("atman") < 100 )
		return notify_fail("�������������\n");
        if( me->query("gin") <= 50 )
                return notify_fail("��ľ�������\n");
	me->add("atman", -100);
	me->receive_damage("gin", 50);
	message_vision(HIW "$N�ڿշ��𣬱���һ��������\n" NOR, me);
        if ( lvl <= random(400) )
                return notify_fail("�����������߶�ʧ���ˣ�\n");
        message_vision(HIR "������$Nȫ�������ȵ�Ѫ���â������\n" NOR, me);
        env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
                bbqthem(me, inv[i]);
        }
        me->start_busy(5);
        return 1;

}

int bbqthem(object me, object obj)
{
	int magic;
	magic = (int) me->query_skill("magic")/2;	
        message_vision(HIR "\n���ȵĺ��������������$N��\n" NOR, obj);
        obj->receive_damage("sen", 0, me);
        if(obj->is_ghost()==1) {
                message_vision(YEL "$N�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()==1) {
                message_vision(YEL "$N�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
                obj->die();
                return 1;
        }
	magic = random(magic/2) + magic/2;
	if(userp(obj) && (((int) obj->query("combat_exp")) >= 2000))
	{
	obj->receive_damage("sen",magic,me);
	COMBAT_D->report_status(obj);
	obj->kill_ob(me);
	me->kill_ob(obj);
	}
	else
	{
        obj->receive_damage("sen",magic,me);
        COMBAT_D->report_status(obj);
        obj->kill_ob(me);
        me->kill_ob(obj);
	}
	return 1;
}
