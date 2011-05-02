
#include <ansi.h>

#define NAME "��Ԫ˧"
#define ID "ma yuanshuai"

inherit NPC;

void create()
{
    set_name(NAME, ({ ID }));
    set("gender", "����");
    set("age", 23);
    set("long", "һֻ����\n");
    set("combat_exp", 1000000);

    set_skill("dodge", 120);
    set_skill("parry", 120);
    set_skill("dragonstep", 120);
    map_skill("dodge", "dragonstep");
    set("force", 900);
    set("max_force", 900);
    set("force_factor", 10);

    setup();
}

void announce_success(object who)
{
    int dx = 3000 + random(500);
    object panzi;
    object hb = who->query_temp("dntg_helper");

    who->add("dntg/number",1);
    who->set("dntg/huaguo", "done");
    who->add("combat_exp", dx);
    command("chat "+who->query("name")+"ն�˰�ռ����ˮ������ħͷ��˳�����������칬��һ�أ�");
    command("chat �Ӵ���ʮ���������Ӧ��"+who->query("name")+"Ϊ������ʱ�����ǲ��");
    tell_object(who, "��Ӯ����"+ COMBAT_D->chinese_daoxing(dx) +"�ĵ��У�\n");

    panzi = new(__DIR__"shipan");
    panzi->move(who);
    message_vision(HIY NAME+"��ͷ�����Ķ�$N˵���������������ֵܵ�һ���С��˼�����ɾ��⡣\n" NOR,who);
    tell_object(who, "��Ԫ˧����һ��ʯͷ���ӡ�\n");
    who->save();
    if (hb) hb->report_progress(10);
}
