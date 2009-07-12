
#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;
	if( me->query("gender")=="����" )
		return notify_fail("����Ҳ��һЦ��ǣ������������ˣ�ү�Ƕ���\n");
	if( (int)me->query("force") < 100 )
		return notify_fail("�������������\n");
    if( !me->is_fighting())
        return notify_fail("������ս���в�Ҫ��Ц��С���������ˡ�\n");
    if( (int)me->query_skill("moonforce", 1) < 60 )
    return notify_fail("���Բ���ķ���򲻹���\n");

    skill = me->query_skill("moonforce",1)*2+me->query("per")*2;

	me->add("force", -100);
	me->receive_damage("sen", 10);

    me->start_busy(random(4));
	tell_object(me,"��۾�����ʼʩչ���Ļ�Ц��������\n");
	message_vision(
		HIM "$N�����촽����ת�ﲨ����ȻһЦ����������\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me 
			|| ob[i]->query("race")!="����" 
			|| ob[i]->query("gender")=="Ů��" ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) 
			{
			message_vision("$N�޶����ԡ�����\n",ob[i]);
			continue;
			}
		damage = skill - ((int)ob[i]->query("max_force") / 10);
		if( damage > 0 ) {
			if( damage > ob[i]->query("sen"))
				{
				tell_object(ob[i],"���������һ�ҡ�������\n");
				tell_room(environment(me),ob[i]->query("name")+
				"����ͨ�죬ҡҡ�λε���"+me->query("name")+
				"���˼�����˵������ü�����ã��á�����\n",ob[i],ob[i]);
				}
			else{
				tell_object(ob[i], "���������һ�ȣ�����С¹��ײ������һƬ�հף�Ԫ���ȡ���\n");
			 	tell_room(environment(me),ob[i]->query("name")+
				"����ͨ�죬�е�����������ӡ�\n",ob[i],ob[i]);  
		  	    }
		 	ob[i]->receive_damage("sen", damage);
			if( (int)ob[i]->query("force") < skill * 2 )
			ob[i]->receive_wound("sen", damage/2);
				}
		
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}

	return 1;
}
