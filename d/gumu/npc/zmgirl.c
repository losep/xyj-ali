// ALi by NewX

inherit NPC;

void create()
{
    set_name("����Ů", ({"girl", "nv"}));
    set ("long", @LONG
һ���������Ů����͹���µ����ģ��������˵���ò������
�������˵�������
LONG);

    set("gender", "Ů��");
    set("age", 15+random(20));
    set("per", 20+random(15));
    set("combat_exp", 10000);
    set_skill("dodge", 10);
    set_skill("moondance", 20);
    set("max_gin", 200);
    set("max_atman", 200);
    set("chat_chance", 5+random(40));
    set("chat_msg", ({
        "����Ů��˫�ָ�������ǰ��˫�壬�ʺ����ͷ�������Σ������ֵİ�����Խ���������...\n",
        "����Ů����ָ�������Լ��Ļ�Ѩ��ֻ�����˵���ָ�ڽ��޵Ļ����н��������������������������֭�����Ǳ�������...\n",
        "����Ů���Լ��İ���֮�£�������������Ϸ����˶��˵Ľ������ۿ���Ҫ�ﵽ��е��۷塣\n",
        "����Ů���һ�����������ҵĲ�������Ѩ�������һ����������������Ȼ�Ѿ��ﵽ�˸߳���\n"
        }) );

    setup();
}