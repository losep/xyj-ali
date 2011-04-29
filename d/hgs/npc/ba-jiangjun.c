inherit NPC;

void create()
{
    set_name("�Ž���", ({"ba jiangjun","ba","monkey"}));
    set("title", "����ɽ��");
    set("gender", "����");
    set("age", 35);
    set("class", "monkey");
    set("long", "һֻ���˾���ͨ��Գ��\n");
    set("combat_exp", 60000);

    set("attitude", "peaceful");
    set("str",40);
    set_skill("unarmed", 80);
    set_skill("dodge", 110);
    set_skill("parry", 80);
    set_skill("force", 50);
    set("per", 10);
    set("max_kee", 600);
    set("max_gin", 100);
    set("max_sen", 300);
    set("max_force", 400);
    set("force",400);
    set("max_mana",200);
    set("mana",200);
    set("force_factor", 20);

    set("chat_chance", 3);
    set("chat_msg", ({
        "�Ž���˵�����ҼҴ��������쳣�������Ϻõı�����\n",
        "�Ž������������˵���ҵ�֪�����ط��ɸ�Щ��������\n",
    }));

    set("inquiry", ([
        "name" : "�Ҿ��ǻ���ɽˮ�����󽫰Ž�����\n",
        "here" : "����ǻ���ɽ��\n",
        "����" : "�٣��ҼҴ������ǻ���ɽˮ����������\n",
        "weapon" : "��ҵı�������ȥ������͵Щ���ҼҴ����ı��������Ҫ��Щ�������ھ����ˡ�\n",
        "bingqi" : "��ҵı�������ȥ������͵Щ���ҼҴ����ı��������Ҫ��Щ�������ھ����ˡ�\n",
        "����" : "��ҵı�������ȥ������͵Щ���ҼҴ����ı��������Ҫ��Щ�������ھ����ˡ�\n",
    ]));

    setup();
}
