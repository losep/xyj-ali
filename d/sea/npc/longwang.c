// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//Changed by sjmao, 09-10-97
#include <skill.h>

inherit NPC;

string expell_me(object me);

void create()
{
    set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));

    set("long",@LONG
�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
����ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����
LONG);
    set("gender", "����");
    set("age", 66);
    set("title", "��������");
    set("class","dragon");
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("combat_exp", 1260000);
    set("rank_info/respect", "����");
    set("rank_info/rude", "������");
    set("per", 20);
    set("str", 30);
    set("max_kee", 3000);
    set("max_gin", 400);
    set("max_sen", 800);
    set("force", 3000);
    set("max_force", 1500);
    set("force_factor", 120);
    set("max_mana", 800);
    set("mana", 1600);
    set("mana_factor", 40);
    set("chat_msg", ({
        "�������ߵ�˵��������������ӣ������Ƕ��������Ķ�������������ˡ�\n",
        "���㳤̾һ������֪��ʱ���ܽ���֮���ջذ���\n",
        "�������Ķ���˵����˵����Ӱ������ڻ���ɽ��ʯ�����֪�Ƿ���ʵ��\n",
        "����̾�����������ܽ����ͻ����������¶����м�������\n",
    }));
    set("chat_chance", 5);

    set("combat_exp", 500000);
    set_skill("unarmed", 100);
    set_skill("dodge", 120);
    set_skill("force", 120);
    set_skill("parry", 100);
    set_skill("fork", 110);
    set_skill("spells", 100);
    set_skill("seashentong", 100);
    set_skill("dragonfight", 100);
    set_skill("dragonforce", 120);
    set_skill("fengbo-cha", 110);
    set_skill("dragonstep", 120);
    map_skill("spells", "seashentong");
    map_skill("unarmed", "dragonfight");
    map_skill("force", "dragonforce");
    map_skill("fork", "fengbo-cha");
    map_skill("parry", "fengbo-cha");
    map_skill("dodge", "dragonstep");

    set("inquiry", ([
        "����": "���������˺��أ�Ŀǰ�������ˣ��ص㲻��͸¶��\n",
        "���": "��𽣿�����˭��û��˵����\n",
        "�빬": (: expell_me :),
        "leave": (: expell_me :),
        ]) );

    create_family("��������", 2, "ˮ��");
    set_temp("apply/armor",50);
    set_temp("apply/damage",25);
    setup();

    carry_object("/d/sea/obj/longpao")->wear();
}

void init()
{
    ::init();
    add_action("do_agree", "agree");
    add_action("do_learn", "xuexi");
}

int accept_object(object who, object ob)
{
    if ((string)ob->query("id") == "jingu bang" ) {
        command("sigh");
        call_out("destroy", 1200, ob);
        if (who->query("combat_exp") < 400000 || who->query_skill("unarmed", 1) <150) {
            command("say һ���ƹ��ӣ��ıȵ��Ҷ�����������֮������\n");
            command("say ����" + RANK_D->query_respect(who) + "�����һ���Ķ������룬С����Ҫ��л��\n");
            return 1;
        }
        command("say ��Ȼ������ı��" + RANK_D->query_respect(who) + "Ҳ�����������ˡ�\n");
        command("say �ҿ��Դ���һЩ����ȭ�Ź���" + RANK_D->query_respect(who) + "��Ҫץ��ѧ(xuexi)���ǣ�\n");
        who->set_temp("temp/learn", 1);
        call_out("unsetlearn", 1200, who);
        return 1;
    }
    else return notify_fail("����ҡҡͷ������мһ�˵����ӡ�\n");
}

void destroy(object ob)
{
    destruct(ob);
    return;
}

void unsetlearn(object ob)
{
    if (find_player(ob->query("id"))) {
        ob->set_temp("temp/learn", 0);
        ob->save();
    }
}

string *reject_msg = ({
    "˵������̫�����ˣ�����ô�ҵ���\n",
    "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
    "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

int do_learn(string arg)
{
    string skill, teacher, master;
    object me= this_player(), ob;
    int master_skill, my_skill, sen_cost;

    if (!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
        return notify_fail("ָ���ʽ��xuexi <����> from <ĳ��>\n");

    if (me->is_fighting())
        return notify_fail("����ĥǹ������������\n");

    if (!(ob = present(teacher, environment(me))) || !ob->is_character())
        return notify_fail("��Ҫ��˭��̣�\n");

    if (!living(ob))
        return notify_fail("�ţ���������Ȱ�" + ob->name() + "Ū����˵��\n");

    if (!master_skill = ob->query_skill(skill, 1))
        return notify_fail("���������±����ұ���ѧ�ˡ�\n");

    if (skill != "unarmed" || !me->query_temp("temp/learn")) 
        return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

    notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
    if (!SKILL_D(skill)->valid_learn(me)) return 0;

    sen_cost = 250 / (int)me->query_int();
    my_skill = me->query_skill(skill, 1);
    if (!my_skill) {
        sen_cost *= 2;
        me->set_skill(skill,0);
    }

    if ((int)me->query("learned_points") >= (int)me->query("potential"))
        return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

    printf("����%s����йء�%s�������ʡ�\n", ob->name(),
        SKILL_D(skill)->name());

    if ((int)ob->query("sen") > sen_cost/5 + 1) {
        if (userp(ob)) ob->receive_damage("sen", sen_cost/5 + 1);
    } else {
        write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
        return 1;
    }

    if ((int)me->query("sen") > sen_cost) {
        if ((string)SKILL_D(skill)->type()=="martial"
        &&  my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp")) {
            printf("Ҳ���ǵ��в��������%s�Ļش������޷���ᡣ\n", ob->name());
        } else {
            if (my_skill >= master_skill)
                printf("�����ԣ��������ĳ̶��Ѿ�����%s�ˡ�\n"
                    "Ȼ��������ǣ�%s�Ľ���ƫƫ����ǳ���������\n",
                    ob->name(), ob->name());
            else
                printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
            me->add("learned_points", 1);
            me->improve_skill(skill, random(me->query_int()));
        }
    } else {
        sen_cost = me->query("sen");
        write("�����̫���ˣ����ʲôҲû��ѧ����\n");
    }

    me->receive_damage("sen", sen_cost );

    return 1;
}

void attempt_apprentice(object ob)
{   
    if (((int)ob->query("combat_exp") < 100000)) {
        command("say " + RANK_D->query_respect(ob) +
            "�����ȵ�С����СŮ���ѻ������������������ɡ�\n");
        return;
    }
    command("smile");
    command("say �ѵ�" + RANK_D->query_respect(ob) +
        "�д���־�������պ���Ŭ����Ϊ�Ҷ����������⡣\n");
    command("recruit " + ob->query("id") );
    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "dragon");
}

string expell_me(object me)
{
    me = this_player();
    if ((string)me->query("family/family_name")=="��������") {
        me->set_temp("betray", 1);
        command("sigh");
        return ("��Ҫ�뿪��Ҳ����ǿ����ֻ�ǰ��Ҷ�����أ�ȴ���ܷ���\n"
"���¼���������࣬�������ķ��벩����������ǰ����ת�����Ը��(agree)?\n");
    }
    return ("ȥ����Ԭ�����ɣ�������֪����\n");
}

int do_agree(string arg)
{
    object me;
    me = this_player();
    if (me->query_temp("betray")) {
        message_vision("$N���������Ը�⡣\n\n", me);
        command("say �˸���־������" + RANK_D->query_respect(me)
            + "��Ը���ڶ������������ȥ�ɡ�ֻ�ǽ����ն�" + RANK_D->query_respect(me)
            + "������Ϊ֮������\n");
        me->set_skill("dragonforce", (int)me->query_skill("dragonforce",1)/2);
        me->set_skill("dragonfight", (int)me->query_skill("dragonfight",1)/2);
        me->set("combat_exp", me->query("combat_exp")*95/100);
        me->delete("family");
        me->delete("class");
        me->set("title", "��ͨ����");
        me->set_temp("betray", 0);
        me->add("betray/count", 1);
        me->add("betray/longgong", 1);
        me->save();
        return 1;
    }
    return 0;
}

