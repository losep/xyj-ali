// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//xiwangmu.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("����ĸ", ({"xi wangmu", "xi", "wangmu","master"}));
    set("long", @LONG

һ����������Ů����ζ��Ů�ӡ�
���ǣ�������ȴ���������������������ţ������ڿ��С���������
���������ߣ�
�����鷿�Ϲ̶���һ������ǯ����ڵĽ������Ӷ񶾵�˺ҧ�Ž��۵�
��٣���ʱ����������ҫ�ţ�������������嶥�ˣ�һ������֭����
�����������������һ��ե�����ռ��������Ѿ����˺ü���ƿ����Ȼ
���Ѿ��������ܾ��ˣ�
�����������𱸲�����һ����Ħ����������������������Ű�ţ���
�������˾޴�Ŀ�У�������������ͣ�������ţ�ͬ����ե֭���ռ�
������Ҳ�Ѿ����˺ü���ƿ��
�������ܵ��������������𺳣�������Ȼ���𺳵������Ů�ӵ�����
������͸�����������Ƿ·��ǻ���һ�е�������
�㲻���е����죬����ǿ��ĵ�Ů������ô�ᱻ��²�أ�
LONG);
    set("title", "���ܵ�");
    set("gender", "Ů��");
    set("age", 30);
    set("class","xian");
    set("attitude", "friendly");
    set("rank_info/respect", "����");
    set("cor", 30);
    set("per", 30);
    set("looking", "��ɫ���٣��޾���ɡ�");
    set("max_kee", 4500);
    set("max_gin", 800);
    set("max_sen", 4500);
    set("force", 4000);
    set("max_force", 2000);
    set("force_factor", 125);
    set("max_mana", 2000);
    set("mana", 4000);
    set("mana_factor", 100);
    set("combat_exp", 2000000);
    set_skill("literate", 150);
    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("force", 180);
    set_skill("parry", 150);
    set_skill("sword", 150);
    set_skill("spells", 180);
    set_skill("moonshentong", 180);
    set_skill("baihua-zhang", 180);
    set_skill("moonforce", 180);
    set_skill("snowsword", 200);
    set_skill("moondance", 150);
    map_skill("spells", "moonshentong");
    map_skill("unarmed", "baihua-zhang");
    map_skill("force", "moonforce");
    map_skill("sword", "snowsword");
    map_skill("parry", "snowsword");
    map_skill("dodge", "moondance");
    set("inquiry", ([
        "name": "�ҡ������Ҿ����¹���ʦ����ĸ������",
        "here": "����Ҳ��֪�������ﰡ������",
    ]));

    set("no_get", "����ĸ���������εĹ̶��ţ������ⲻ������\n");
    set_temp("no_move", 1);
    
    create_family("�¹�", 1, "��");
    setup();
}

void attempt_apprentice(object ob)
{
    command("sigh");
    command("say ��������Ѿ������ⲽ����ˣ����ﻹ����˼��ͽ��\n");
}

int accept_fight(object me)
{
    command("sigh");
    command("say " + RANK_D->query_respect(me)
        + "�����ܿ���Ц�������Ѿ������ⲽ����ˣ����ﻹ�����˽��֣�\n");
    return 0;
}

mixed set_temp(string prop, mixed data)
{
    if (prop == "no_move") return ::set_temp("no_move", 1);
    else return ::set_temp(prop, data);
}

int delete_temp(string prop)
{
    if (prop == "no_move") return ::set_temp("no_move", 1);
    else return ::delete_temp(prop);
}
