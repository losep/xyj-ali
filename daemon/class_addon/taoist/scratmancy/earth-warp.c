// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("scratching") < 20 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("���紫�ͷ�Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 50 ) 
		return notify_fail("��ķ��������ˣ�\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "���紫�ͷ�" NOR, 
		({ "earth-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -50);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ�����紫�ͷ���\n" NOR, me);
        return 1;
}

int do_warp(string target, object who)
{
        object env;

        if( who && who!=this_player() )
                return notify_fail("���紫�ͷ�ֻ�ܶ��Լ�ʹ�á�\n");

        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "����һ�����紫�ͷ���\n"
"��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n"
                "Ȼ��һ����ͻȻ����\n" NOR, env);
        message("vision", "����...." + this_player()->name() + 
"�Ѿ������ˡ�\n", environment(this_player()), ({this_player()}));
        message("vision",
                CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n"
                NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n"
                        "ȴ��һ����....\n", this_player() );
        this_player()->move(DEATH_ROOM);
        return 1;
}
 
