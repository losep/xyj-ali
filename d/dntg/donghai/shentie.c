//sgzl

#include <ansi.h>

inherit F_UNIQUE;
inherit ITEM;

void create()
{
    set_name("����������", ({ "shen tie" ,"tie"}));
    set_weight(30000);
    set("long", @LONG

��˵���������Ǵ�����ˮ֮ʱ��������ǳ���һ�����ӡ�
��ǰ��ϸ���ƣ� ԭ����ͷ�������𹿣��м���һ��������
���������Գɵ�һ���֣�����������𹿰�������һ����
ǧ��ٽ
LONG );

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "crimsonsteel");
        set("value", 20000000);
        set("no_get", "��ô�ֵ����������õ�������\n");
        set("no_sell", 1);
    }
    setup();
}

void init()
{
    add_action("do_xiao", "xiao");
}

int do_xiao()
{
    object me = this_object();
    object who = this_player();
    object helper = who->query_temp("dntg_helper");

    if (who->query("dntg/donghai") != "hua gan ji" || !helper) {
        message_vision("$N���һ����С��С��С��������һ�㷴ӦҲû�з�����\n", who);
        return 1;
    }

    if (who->query("mana") < 500)
        message_vision("$N���һ����С��С��С����ʲôҲû�з�����\n", who);
    else {
        who->add("mana", -500);
        if (random(5) < 4)
            message_vision("$N���һ����С��С��С����\nֻ��������Ȼ��̱�ϸ��Щ��\n", who);
        else {
            message_vision("$N���һ����С��С��С����\nֻ������������һ����Ӱ��������$N���ϵ�" +helper->name()+ "��\n", who);
            call_out("finish_summary", 1, who);
            load_object("/obj/empty");
            move("/obj/empty");
        }
    }
    return 1;
}

void finish_summary(object who)
{
    object helper;
    
    if (!who || !(helper = who->query_temp("dntg_helper"))) return;

    who->start_busy(50);
    helper->speak(({
            CYN "˵�����ٺٺٺ٣������Ҳ�Ѿ��µ��ˡ�" NOR,
            CYN "˵�������������û�н𹿰���" NOR,
            CYN "˵������ʵ���Դӵ����ʥүү���Ҵ��������ߣ��ǰ������ˡ�" NOR,
            CYN "˵����������Ϊ�𹿰������⣬���쵣���������˻�������" NOR,
            CYN "˵����ʱ�䳤�ˣ����ﾹȻ����ƾ�չ������һ�������������Ӱ��" NOR,
            CYN "˵�����������������Ա����˼ҳɵ�ȴ�Ǵ�����������Ҳ������������ôһ��Ϸ��" NOR,
            CYN "˵������С�Ӱ����Ҵ�æ�������˼���ȻҲ��������㡣" NOR,
            CYN "˵���������ɣ��ұ㴫��һ������仯֮����ֻҪ�������Ʒ����������ҿ�������ӵ�еڶ�����̬��" NOR,
            CYN "˵������Ȼ����𹿰��仯��ˣ���Ҳ����һ�����á�" NOR,
            CYN "˵������������ʱû�����Ʒ�������Ҳû��ϵ������ү�������ã��������������������ң�����ү��ʱ����" NOR,
            CYN "˵�������˺��ˣ��ϻ�˵���ˣ����ڸ��뿪�ˡ�" NOR,
            (: call_other, this_object(), "finish_announce", who :),
    }));
}

void finish_announce(object ob)
{
    object wang;
    ob->start_busy(-1);
    ob->continue_action();
    ob->command_function("up");
    wang = new(__DIR__"announcer");
    wang->announce_success(ob);
    destruct(this_object());
}
