// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>

#include <dbase.h>
#include <armor.h>

inherit NECK;

void create()
{
    set_name("�ɻ�", ({ "flower"}));
    set_weight(100);
    set("unit", "��");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 2);
    setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me = this_player();
    int qn = 0;
    int score = query("score");
    if (!arg || !id(arg)) return 0;
    message_vision(HIC"$N����һ��"+query("name")+HIC"��ֻ���������˱ǣ��ݼշҷ���\n"NOR, me);
    if (query("target")==me && score>0) {
        me->add("combat_exp", score);
        qn = score*(20+random(10))/100;
        if (me->query("potential")-me->query("learned_points") < 1000)
            me->add("potential", qn);
        tell_object(me, HIC"��õ���"+COMBAT_D->chinese_daoxing(score)+"���У�"+qn+"��Ǳ�ܡ�\n"NOR);
        MONITOR_D->report_system_object_msg(me, " got "+score+" exp "+qn+" pots from baihua-gu.\n" );
        log_file("baihuagu", me->query("id")+" got "+score+" exp "+qn+" pots on "+ctime(time())+".\n");
    }
    destruct(this_object());
    return 1;
}