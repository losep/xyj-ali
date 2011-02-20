// ALi by NewX
 
// foxqueen.c 槼�

/************************************************************/

// declarations and variables

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string talk_chimeng();

/************************************************************/
void create()
{
    set_name("槼�", ({"daji","fox", "fox queen"}));
    set("gender", "Ů��");
    set("age", 16);
    set("long", @LONG
������ǧ����꾫槼����Դ�������������������ԯ��Ĺ�����ӡ���
��������ǧ�ŵľ������ˣ�һ�һЦ���纣�����գ��滨���ꡣ
LONG);
    set("title", "��β���");
    set("class", "yaomo");
    set("combat_exp", 1000000);
    set("attitude", "heroic");
    create_family("��ԯ��Ĺ", 1, "��ʦ");
    set("second_family_name", "�¹�");
    set("per", 50);
    set("int", 30+random(10));
    set("cor", 25+random(5));
    set_skill("unarmed", 100);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("spells", 150);
    set_skill("force", 150);
    set_skill("fox-force", 120);
    set_skill("sword", 150);
    set_skill("firesword", 100);
    set_skill("whip", 150);
    set_skill("fenqingbian", 150);
    set_skill("moondance", 175);
    set_skill("jingang-quan", 100);
    set_skill("moonforce", 150);
    set_skill("moonshentong", 150);
    set_skill("fascination", 200);
    map_skill("force", "fox-force");
    map_skill("spells", "fox-force");
    map_skill("unarmed", "jingang-quan");
    map_skill("sword", "firesword");
    map_skill("parry", "firesword");
    map_skill("whip", "fenqingbian");
    map_skill("dodge", "moondance");
    map_skill("fascination", "moondance");
    set("max_kee", 1050);
    set("max_sen", 1200);
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 150);
    set("mana", 2500);
    set("max_mana", 2500);
    set("mana_factor", 250);
    set("inquiry", ([
        "name": "�����˴�������",
        "here": "���������ԯ��Ĺ��",
        "rumors": "��Ⱥ���ҷ�����Ȼ�Ѵ����ǻ�Ū���ˣ����������������ߺ�...",
        "����": "������СѾͷ����Ϊʶ���˱����ļ�ı����ʵһ�о��ڱ��������ա�",
        "�϶�": "�϶𣿺Ǻǣ��������Ѿ��Ǳ�������ū��...",
        "����ĸ": "����ĸ�Ѿ����������ֺ�ɱ��",
        "�¹�": "�����¹�����ȫ�������֣������¹�����Ը��Ͷ�뱾�������£�����ҲԸ����ͽ��",
       ]));
    create_family("��ԯ��Ĺ", 1, "Ů��");
    setup();
    carry_object("/d/obj/weapon/sword/fire_sword")->wield();
    carry_object("/d/obj/cloth/huqiu")->wear();
    carry_object("/d/obj/cloth/jingang")->wear();
}

/**************************************************************/
int attempt_apprentice(object me)
{
    string myname = RANK_D->query_rude(me);
    string myid = me->query("id");
    command("look " + myid);
    command("consider");

    if (me->query("gender") != "Ů��") {
        command("say �����ˣ���һ��ȥ��");
        return 1;
    }

    if (me->query("family/family_name") != "��ԯ��Ĺ" && me->query("family/family_name") != "�¹�") {
        command("say ����˭����");
        return 1;
    }

    if (me->query("combat_exp") < 200000) {
        command("say С���ã������Ϊʦ����������Ŷ��");
        return 1;
    }

    if (me->query("per") < 25) {
        command("say С���ã�Ů������Ҫ�ľ������������ɫ���������⸱����...");
        command("grin");
        command("say ���ǸϽ�Ͷ̥ת���ɣ�");
        command("kill " + myid);
        return 1;
    }

    command("grin");
    command("say ���úã��Ժ����������ˡ�");
    command("recruit " +myid);
    return 1;
}

int recruit_apprentice(object ob)
{
    string family_name;
    int gen;

    if (ob->query("family/master_id") == query("id")) return 0;

    if (ob->query("family/family_name") == "�¹�") {
        family_name = "�¹�";
        gen = 2;
    } else {
        family_name = query("family/family_name");
        gen = (int)query("family/generation") + 1;
    }

    ob->set("family/master_id", query("id"));
    ob->set("family/master_name", query("name"));
    ob->set("family/family_name", family_name);
    ob->set("family/generation", gen);
    ob->set("family/enter_time", time());
    ob->assign_apprentice("����", 0);
}

/************************************************************/
int prevent_learn(object me, string skill)
{
    if (me->query("family/family_name") == "�¹�") {
        if (skill == "fox-force") {
            command("shake");
            command("say ��Ǻ��࣬ѧ��������ķ���");
            return 0;
        }
        return 1;
    }

    if (me->query("family/family_name") == "") {
        if (skill == "moonforce" || skill == "moonshentong") {
            command("shake");
            command("say ����������ķ������¹��Ĵ�ǳ����ǿ���ˣ�Ϊ��Ҫѧ�¹����书��");
            return 0;
        }
        return 1;
    }

    return 0;
}

/*********************************************************************/

