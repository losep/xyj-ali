// sgzl
#include <ansi.h>
#define NAME "����"
#define ID "ao guang"

inherit NPC;

void create()
{
    set_name(NAME, ({ ID }));
    set("gender", "����");
    set("age", 53);
    set("long", "һ����������\n");
    
    setup();
}

void announce_success(object who)
{
    int dx = random(500) + 3000;
    object hb = who->query_temp("dntg_helper");

    who->add("dntg/number", 1);
    who->set("dntg/donghai", "done");
    who->add("combat_exp", dx);
    command("chat "+who->query("name")+"�㾹�������������Ķ��������������Ҳ�ȥ�����ǰ���㣡");
    tell_object(who,"��Ӯ����"+ COMBAT_D->chinese_daoxing(dx) +"�ĵ��У�\n");
    who->save();
    if (hb) hb->report_progress(10);
}

��
