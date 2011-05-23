// rack.c

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("������",({"rack"}));
    set("env/invisibility",1);
    set_max_encumbrance(50000000);
    set_max_items(10000);
    set_weight(100);
    set("no_get",1);
    set("no_magic", 1);
    set("no_fight", 1);
    seteuid(getuid());
    setup();
}

string short()
{
    object owner = query("owner");
    if (!owner) return "������";
    else return sprintf("������(owner: %s)", geteuid(owner));
}

void init()
{
    add_action("do_kun", "kun");
    call_out("start_organize", 5, this_player());
}

int check_in_aolai(object ob, object helper)
{
    if (sscanf(file_name(environment(ob)), "/d/4world/%*s") == 1) {
        helper->speak(({ CYN "˵�����ף�����ô�����ˣ��Ҳ��Ǹ������������Զ������ô�����ҵĻ�����" NOR }));
        call_out((: call_other, helper, "disappear" :), 3);
        return 1;
    }
    return 0;
}

void start_organize(object me)
{
    object owner;
    object helper;

    if (!(owner = query("owner")) || me != owner) return;
    if (!(helper = owner->query_temp("dntg_helper"))) return;
    if (owner->query("dntg/huaguo") != "done") return;
    if (owner->query("dntg/donghai")) return;
    if (environment(owner)->query("exercising")) return;
    if (query("organizing")) return;

    helper->speak(({
            CYN "˵�����ٺٺٺ٣�û�취�˰ɣ��Ҳ��������ɣ�" NOR,
            CYN "˵������ү���а취��" NOR,
            CYN "˵������ҽ𹿰���ү�������ð�����������Ѫ��������һ����ϰ��" NOR,
            CYN "˵��������������ڼ䣬��ɵ��������Զ�㡣" NOR,
            CYN "˵������һ�̼��˰�����������ϰȡ���ˣ��ǿɾͲ��ð��ˡ�" NOR,
            0,
            0,
            0,
            (: call_other, this_object(), "organize_exercise", 0 :),
    }));
}

void organize_exercise(int prog)
{
    object owner, helper;
    if (!(owner = query("owner"))) return;
    if (!(helper = owner->query_temp("dntg_helper"))) return;
    
    switch (prog) {
        case 0:
            helper->speak(({ CYN "˵�����������Ѿ���ʼ�����ˣ���ǧ�������˰���" NOR }));
            break;
        case 1:
        case 2:
        case 3:
            if (check_in_aolai(owner, helper)) return;
            break;
        case 4:
            if (check_in_aolai(owner, helper)) return;
            helper->speak(({ CYN "˵�������ˣ�����������ϰ�Ѿ��ڳﱸ���ˣ�����Ҳ�ڴ������ˣ����ڿ�ǧ����ȥ����" NOR }));
            break;
        case 5:
        case 6:
            if (check_in_aolai(owner, helper)) return;
            helper->speak(({ CYN "˵�����ţ��Ѿ�����Ĳ���ˣ��ٵȵȾͺ��ˡ�" NOR }));
            break;
        case 7:
        case 8:
            if (check_in_aolai(owner, helper)) return;
            break;
        default:
            if (check_in_aolai(owner, helper)) return;
            helper->speak(({ CYN "˵���������������ˣ����ˣ������ߣ���ȥȡ���ǵı����ɡ�" NOR }));
            call_out("start_exercise", 1, helper);
            return;
    }
    call_out("organize_exercise", 10, prog + 1);
}

void start_exercise(object helper)
{
    object ob, room, entrance;

    // drill entrance room
    room = helper->get_drillent_room();
    entrance = room;
    room->set("o_long", room->query("long"));
    room->set("long", @LONG

�����ǰ��������䳡����ڣ�����������ûʲô�˵ģ����ǽ�����
���е��ر�����վ���ż�������Ľ�����ͷ���������������ˡ�
���䳡����Ҳ��ʱ������׳�ĺŽ�����
LONG);
    tell_object(room, "һ�ӶӾ�ʿ���������䳡��½½���������ĳ��佫Ҳ�������䳡����������Ľ�����ͷ��������ǰ��\n");
    tell_object(room, "����������İ��������˺ܶ࣬������Ҫ��ʲô���ˡ�\n");
    ob = new(__DIR__"jiaotou");
    ob->move(room);
    ob = new(__DIR__"jiaotou");
    ob->move(room);
    set("drillent_room", room);

    // drill room
    room = helper->get_drill_room();
    room->set("o_long", room->query("long"));
    room->set("long", @LONG

���������䳡���Ĺ��佫���������£�����ƫ�Խ�У������������
�����У����Ҿ�ʿ����ȫװ�ߴ����ָ�ִꪶ������м�һ���б�ʿ
�������ݵĴ��������С�
LONG);
    tell_object(room, "һ�ӶӾ�ʿ���������䳡��½½���������ĳ��佫Ҳ�������䳡��\n");
    tell_object(room, "�ѵ���Ҫ��ϰ�ˣ�����ǰ��겻���������°���\n");
    foreach (object o in all_inventory(room)) {
        if (userp(o)) {
            tell_object(o, "������ʿ�ܹ������ȵ���������ϰ�������˵���ɢ��\n");
            tell_object(o, "������ʿ����һ�Ѽ����ӳ������䳡��\n");
            tell_room(room, "��ʿ�ǰ�" + o->name() + "���˳�ȥ��\n", ({ o }));
            o->move(entrance);
            tell_object(o, "žߴһ�����㱻ˤ�������䳡��ڴ���ˤ������ð���ǡ�\n");
            tell_room(entrance, o->name() + "�������䳡�����˳�����\n", ({ o }));
        } else {
            tell_room(o, "������ʿ���ְ˽ŵİ�" + o->name() + "�������\n");
            destruct(o);
        }
    }
    ob = new(__DIR__"jiaotou");
    ob->move(room);
    ob = new(__DIR__"jiaotou");
    ob->move(room);
    ob = new(__DIR__"junshi");
    ob->move(room);
    ob = new(__DIR__"junshi");
    ob->move(room);
    set("drill_room", room);

    // arsenal room
    room = helper->get_arsenal_room();
    room->set("o_long", room->query("long"));
    room->set("long", @LONG

�����ǰ������ı����⣬������ֱ���(bingqi)������ǹ������ꪡ�
�����ᡢë�������ޡ��١��Ρ�ﵡ������󡢲桢ì�������㱸��
��������Ķѷ��ţ������������ʿ����������š�
LONG);
    room->set("item_desc", ([
            "bingqi" : "���ָ����ı��������������߲����㣬����(kun)һ�²ź��á�\n"
        ]));
    room->set("exercising", 1);
    foreach (object o in all_inventory(room)) {
        if (o == this_object()) {
        
        } else if (userp(o)) {
            tell_object(o, "������ʿ�ܹ������ȵ���������ϰ�������˵���ɢ��\n");
            tell_object(o, "������ʿ����һ�Ѽ����ӳ������䳡��\n");
            tell_room(room, "��ʿ�ǰ�" + o->name() + "���˳�ȥ��\n", ({ o }));
            o->move(entrance);
            tell_object(o, "žߴһ�����㱻ˤ�������䳡��ڴ���ˤ������ð���ǡ�\n");
            tell_room(entrance, o->name() + "�������䳡�����˳�����\n", ({ o }));
        } else {
            tell_room(o, "������ʿ���ְ˽ŵİ�" + o->name() + "�������\n");
            destruct(o);
        }
    }
    ob = new(__DIR__"pianjiang");
    ob->move(room);
    ob = new(__DIR__"pianjiang");
    ob->move(room);
    ob = new(__DIR__"pianjiang");
    ob->move(room);
    ob = new(__DIR__"pianjiang");
    ob->move(room);
    set("arsenal_room", room);
    
    call_out("finish_exercise", 1200);
}

void finish_exercise()
{
    object room;

    if (room = query("arsenal_room")) {
        room->set("long", room->query("o_long"));
        room->delete("o_long");
        room->delete("item_desc");
        room->delete("exercising");
        tell_object(room, "��ϰ�ƺ������ˣ�������ƫ���ǰ�����ı�����ʰһ�°����ˡ�\n");
        tell_object(room, "��������̸����˼���ƺ��������Щ����������Ǯ��\n");
        tell_object(room, "��������������ƽʱΪʲôû�б����ˡ�\n");
        foreach (object ob in all_inventory(room)) {
            if (!userp(ob) && ob != this_object()) destruct(ob);
        }
    }
    
    if (room = query("drill_room")) {
        room->set("long", room->query("o_long"));
        room->delete("o_long");
        tell_object(room, "��ϰ�ƺ������ˣ���ʿ��½�����뿪�ˣ��ĳ��佫�Ǹ���������ˡ�\n");
        tell_object(room, "��ʿ������ǰ����ɨ��һ������������Χ��������������ˡ�\n");
        foreach (object ob in all_inventory(room)) {
            if (!userp(ob) && ob != this_object()) destruct(ob);
        }
    }
    
    if (room = query("drillent_room")) {
        room->set("long", room->query("o_long"));
        room->delete("o_long");
        tell_object(room, "��ϰ�ƺ������ˣ�һ�ӶӾ�ʿ�׷��뿪�����䳡�������ָֻ������յ�������\n");
        foreach (object ob in all_inventory(room)) {
            if (!userp(ob) && ob != this_object()) destruct(ob);
        }
    }
    
    destruct(this_object());
}

void weather_effect(string weather)
{
    if (weather != "wind") return;
    call_out("away", 2, this_player());
    call_out("go_back", 60, this_player());
}

void away(object who)
{
    object where = environment();
    object who1 = present("pian jiang 1", where);
    object who2 = present("pian jiang 2", where);

    if (!who1) return;

    destruct(who1);
    destruct(who2);
    tell_object(where, "��紵�����Ƕ��������ۣ�����ƫ���޺������˳�ȥ��\n");
}

void go_back(object who)
{
    object who1, who2;
    object where = environment();

    // mon 3/24/99
    // prevent getting too many pian jiang by go_back.
    // at most 4.
    if (present("pian jiang 4", where)) return;

    who1 = new(__DIR__"pianjiang");
    who2 = new(__DIR__"pianjiang");
    who1->move(where);
    who2->move(where);
    tell_object(where, "ƫ���������۾��߻ر����⡣\n");
}

int do_kun(string arg)
{
    object me = this_player();
    object env = environment();
    object jiang, bingqi;

    if (!arg || arg != "bingqi")
        return notify_fail("��Ҫ��ʲô��\n");
    if (!env->query("exercising"))
        return notify_fail("����û�б���\n");
    if (objectp(jiang = present("pian jiang", environment(me))) && living(jiang))
        return notify_fail("ƫ����ȵ����Ҷ��ҹ���������Ķ��������˲��ɣ�\n",me);
    if (me->is_busy())
        return notify_fail("������æ���ء�\n");

    if (me->query("kee") < 50)
        me->unconcious();
    else {
        me->receive_damage("kee", 50);
        message_vision("$N����ææ��ʰ��һ�ѱ�����������������������������һЩ��\n", me);
        bingqi = new(__DIR__"bingqi");
        bingqi->move(me);
        me->start_busy(5, 5);
    }
    return 1;
}
