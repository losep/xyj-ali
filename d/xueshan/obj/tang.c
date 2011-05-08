inherit ITEM;

#include <ansi.h>

int do_he(string);

void create() 
{
    set_name(YEL "������" NOR, ({"tang"}));
    set_weight(50);
    set("unit","��");
    setup();
}

void setup()
{
    if (!query("prices")) set_name("ˢ��ˮ", ({"tang"}));
    set("long", "һ�뻨�����̵�"+name()+"������(he)ζ����\n");
}

void init()
{
    add_action("do_he", "he");
}

int do_he(string arg)
{
    object who = this_player();

    if (!id(arg)) return notify_fail("�����ɶ��\n");
    message_vision("$N����"+name()+"��ཹ�ཱུĺ�����ȥ��\n", who);
    if (query("prices") <= 0)  message_vision("��ʲô��ζҲû��������\n", who);
    else if ((int)who->query_skill("iceblood-force", 1) < 10
        ||  (int)who->query_skill("iceblood-force", 1) > 199 ) {
            message_vision("$Nֻ�е�һ����ģ�������ת��\n", who);
            who->unconcious();
    } else {
        message_vision("$N������������ǿ����û�³�����\n", who);
        who->improve_skill("iceblood-force", query("prices"));
        tell_object(who, "��ֻ�е�����������ʮ��С���������Ҵ̣���ʹ����������"
            +"�Ž�������ҩ����ȫ���⡣\n");
        tell_object(who, YEL "��ı�����Ѫ��������"+ chinese_number(query("prices"))+"�㣡\n" NOR);
    } 
    destruct(this_object());
    return 1;
}

