// ALi by NewX
 
// foxqueen.c 槼�

/************************************************************/

// declarations and variables

#include <ansi.h>
inherit NPC;

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
    set("per", 50);
    set("int", 30+random(10));
    set("cor", 25+random(5));
    set_skill("unarmed", 100);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("spells", 150);
    set_skill("force", 150);
    set_skill("foxforce", 120);
    set_skill("foxphantom", 130);
    set_skill("sword", 150);
    set_skill("firesword", 100);
    set_skill("whip", 150);
    set_skill("lovefire-whip", 150);
    set_skill("moondance", 175);
    set_skill("jingang-quan", 100);
    set_skill("moonforce", 150);
    set_skill("moonshentong", 150);
    set_skill("archery", 150);
    set_skill("xuanyuan-archery", 100);
    set_skill("charm", 200);
    map_skill("force", "foxforce");
    map_skill("spells", "foxphantom");
    map_skill("unarmed", "jingang-quan");
    map_skill("sword", "firesword");
    map_skill("parry", "firesword");
    map_skill("whip", "lovefire-whip");
    map_skill("archery", "xuanyuan-archery");
    map_skill("dodge", "moondance");
    map_skill("charm", "moondance");
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
    set("secret_family_name", "�¹�");
    setup();
    carry_object("/d/obj/weapon/sword/fire_sword")->wield();
    carry_object("/d/obj/cloth/huqiu")->wear();
    carry_object("/d/obj/cloth/jingang")->wear();
}

/**************************************************************/
void attempt_apprentice(object me)
{
    string myname = RANK_D->query_rude(me);
    string myid = me->query("id");
    command("look " + myid);
    command("consider");

    if (me->query("gender") != "Ů��") {
        command("say �����ˣ���һ��ȥ��");
        return;
    }

    if (me->query("family/family_name") != "��ԯ��Ĺ" && me->query("family/family_name") != "�¹�") {
        command("look " + myid);
        command("say ����˭����");
        return;
    }

    if (me->query("combat_exp") < 200000) {
        command("touch " + myid);
        command("say С���ã��㻹���˵㣬��ݱ���Ϊʦ����������Ŷ��");
        return;
    }

    if (me->query("per") < 25) {
        command("say С���ã�Ů������Ҫ�ľ������������ɫ���������⸱����...");
        command("grin");
        command("say ���ǸϽ�Ͷ̥ת���ɣ�");
        command("kill " + myid);
        return;
    }

    command("grin");
    command("say ���úã��Ժ����������ˡ�");
    command("recruit " +myid);
    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "yaomo");
}

/************************************************************/
int prevent_learn(object me, string skill)
{
    if (me->query("family/family_name") == "�¹�") {
        if (skill == "fox-force") {
            command("shake");
            command("say ��Ǻ��࣬ѧ��������ķ���");
            return 1;
        }
    }
    else if (me->query("family/family_name") == "��ԯ��Ĺ") {
        if (skill == "moonforce" || skill == "moonshentong") {
            command("shake");
            command("say ����������ķ������¹��Ĵ�ǳ����ǿ���ˣ�Ϊ��Ҫѧ�¹����书��");
            return 1;
        }
    }

    return 0;
}

/*********************************************************************/

