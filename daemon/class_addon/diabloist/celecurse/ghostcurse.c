#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
        if((int)me->query_skill("cursism") < 100 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");

        write("�����˭�Ļꣿ");
        input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new;
	string msg;
	object room;
	string *list;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("��ֹʩ����\n");
                return;
        }

                ob = find_living(name);
		room = environment(me);
	me->receive_wound("kee",100);
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)){
		write("���޷����ܵ�����˵Ĺ�ꡣ\n");
		return; }
        msg = HIW "$N˫������һ�ӣ�һ��Ũ��ӵ��¾��������\n" ;
        ob_list = room->query("objects");
	list = keys(ob_list);
	for(i=0;i<sizeof(list);i++)
		if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
			{HERE=1;break;}
	if(HERE) {
			seteuid(geteuid(me));
			new = new(base_name(ob));
			new->be_ghost(1);
			new->set("combat_exp", ((int) new->query("combat_exp"))*10);
			new->move(room);	
			new->set("title",HIB "�л�"NOR);
	msg +=  "Ũ���ƺ���$N��߽�����Ũ����һ����Ӱ������\n" NOR;
		new->start_call_out((: call_other, __FILE__, "melt", new :), 
(int)me->query_skill("cursism")/10 + 5);
		}
	else
	msg += "Ũ��������ʧ�ˣ�����\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision("$N�������黯����ʧ�ˣ�����\n",ob);
	destruct(ob);
}
