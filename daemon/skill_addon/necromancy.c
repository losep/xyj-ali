// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("necromancy",1))
		return notify_fail("�����ʦ������Ϊ�������޷��������������������\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}
int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"
			+ bug->name() + "�ɣ�\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ����޷����С�\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("���Ŀ�����������⣬��ʼ��ϰ��������еķ���....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("��������˼һ�ң������һֻ��Ŀ������" + bug->name() + "��\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("��Ļ�������" + bug->name() + "��ס������������ɣ�\n");
	}	
	else return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -50;
}

