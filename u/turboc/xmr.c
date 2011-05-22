
//xmr.c
#include <ansi.h>
inherit NPC;

void create()
{
    set_name("С÷��", ({ "xmr" }));
    set("long", HIG"ֻ����һ�Ź��������������ף�һ˫������Ĵ��۾�����ã���˸���ǣ�����ת�Σ�\n"
            "���֮�����ƺ�����һ˫�۾�����˵��һ�㣬����Ц���̣�����һ�������׽�֮�⡣\n"NOR);
    set("title", HIG"����Э��"NOR);
    set("rank", HIY"÷������"NOR);
    set("nickname", HIM"��Ư����"NOR);
    set("gender", "Ů��");
    set("age", 17);
    set("attitude", "friendly");

    set("str", 30);
    set("cps", 30);
    set("cor", 30);
    set("per", 30);
    set("int", 30);
    set("con", 30);
    set("spi", 30);
    set("kar", 30);

    set("max_kee", 100000);
    set("max_gin", 100000);
    set("max_sen", 100000);

    set("max_atman",100000);
    set("atman",100000);
    set("atman_factor",1000);
    set("max_force", 100000);
    set("force", 100000);
    set("force_factor", 1000);
    set("max_mana", 100000);
    set("mana", 100000);
    set("mana_factor", 1000);

    set_skill("parry", 500);
    set_skill("unarmed", 500);
    set_skill("dodge", 500);
    set_skill("force", 500);
    set_skill("spells", 500);
    set_skill("sword", 500);
    set_skill("whip", 500);
    set_skill("flower-hand", 500);
    set_skill("moondance", 500);
    set_skill("moonforce", 500);
    set_skill("moonshentong", 500);
    set_skill("snowsword", 500);
    set_skill("loveless-whip", 500);
    set_skill("literate", 500);
    map_skill("parry", "snowsword");
    map_skill("unarmed", "flower-hand");
    map_skill("dodge", "moondance");
    map_skill("force", "moonforce");
    map_skill("spells", "moonshentong");
    map_skill("sword", "snowsword");
    map_skill("whip", "loveless-whip");
    set("combat_exp", 1000000000);

    set("chat_chance", 10);
    set("chat_msg", ({
        "С÷��Ц�����˵������Ը�⽻�����ˣ���Ը�����������\n",
        "С÷��������Ƥ�ذ��˸�����: �ɱ����˸�ϰ���Σ�mud �����治Ҫ����\n",
        (: random_move :)
    }));

    set("inquiry", ([
        "rumors":  "��֪������Ϣ��:\n"
                "    name, xiaoxiao, feather, Isaac, СС, С��\n",
        "name":   "�ҽ�С÷���ǣ��㲻֪����\n",
        "feather":   "С�����Һ�СС�ĺ����ѣ�����˭�ܼ޸������Ǹ����ˡ�\n",
        "xiaoxiao":   "СС�Ǹ��ɰ���Ů��Ŷ������ϲ�����ѵģ��Ҿ��������Ļ����ˡ�\n",
        "Isaac":   "���񶼲�֪�����ô����ڵ������أ�������!\n",
        "СС":   "СС�Ǹ��ɰ���Ů��Ŷ������ϲ�����ѵģ��Ҿ��������Ļ����ˡ�\n",
        "С��":  "С�����Һ�СС�ĺ����ѣ�����˭�ܼ޸������Ǹ����ˡ�\n",
    ]));

    setup();
    if (clonep()) CHANNEL_D->register_relay_channel("chat");
    carry_object("/d/obj/cloth/shoes")->wear();
    carry_object("/d/obj/cloth/xianyi")->wear();
    add_money("gold", 500);
}

/************************************************************/

void relay_emote(object ob, string verb)
{
    if (!userp(ob)) return;

    switch(verb) {
        case "kick":
            command("chat СС�����ǣ�" + ob->query("name")+ "�۸��� ...\n");
            command(verb + " " + ob->query("id"));
            break;
        case "pat":
            command("chat ��" + ob->query("name") + "�����������Ķ�����ɵ�ˣ�\n");
            command("heng" + " " + ob->query("id"));
            break;
        case "slap":
            command("chat ������ң�ʹ���ˣ�" + ob->query("name")+ "�û�Ŷ���Ҹ���ССȥ��\n");
            command("slap" + " " + ob->query("id"));
            break;
        case "bigsis":
            command("ybrother" + " " + ob->query("id"));
            break;
        case "kok":
            command("chat ������ң�ʹ���ˣ�" + ob->query("name")+ "�û�Ŷ���Ҹ���ССȥ��\n");
            command("sob" + " " + ob->query("id"));
            break;
        case "kiss":
            command("blush");
            command("shy" + " " + ob->query("id"));
            break;
        case "xiaoxiao":
            command("smile" + " " + ob->query("id"));
            break;
        case "kiss2":
            command("puke" + " " + ob->query("id"));
            break;
        case "hit":
            command("chat ������ң�ʹ���ˣ�"+ ob->query("name") + "�û�Ŷ���Ҹ���ССȥ��\n");
            command("hit" + " " + ob->query("id"));
            break;
        case "hammer":
            command("chat ������ң�ʹ���ˣ�"+ ob->query("name") + "�û�Ŷ���Ҹ���ССȥ��\n");
            command("hammer" + " " + ob->query("id"));
            break;
        case "shutup":
            command("shutup" + " " + ob->query("id"));
            break;
        case "heihei":
            command("fear" + " " + ob->query("id"));
            break;
        case "qmarry":
            command("sigh" + " " + ob->query("id"));
            command("marry1");
            break;
        case "haha":
            command("?" + " " + ob->query("id"));
            break;
        case "beauty":
            command("xixi" + " " + ob->query("id"));
            command("blush");
        break;
        case "?":
            command("sick" + " " + ob->query("id"));
            break;
        case "slogan":
            command("inn" + " " + ob->query("id"));
            break;
        case "cry":
            command("comfort1" + " " + ob->query("id"));
            break;
        case "sigh":
            command("sigh" + " " + ob->query("id"));
            break;
        case "rose1":
            command("thank" + " " + ob->query("id"));
            break;
        case "club":
            command("chat ��ѽ��ʹ���ˣ�"+ ob->query("name") + "��ݣ���ô�ɰ�Ư������üҲ�µ�ȥ�֣�\n�ҡ�����Ҫ���ߡ�������\n");
            command("faint" + " " + ob->query("id"));
            break;
        case "xixi":
            command("pat" + " " + ob->query("id"));
            break;
        case "giggle":
            command("haha" + " " + ob->query("id"));
            break;
        case "wolf":
            command("sob" + " " + ob->query("id"));
            break;
        case "wa1":
            command("innocent" + " " + ob->query("id"));
            break;
        case "moon":
            command("blush" + " " + ob->query("id"));
            break;
        case "lovelook":
            command("blush" + " " + ob->query("id"));
            break;
        case "saosao":
            command("sick" + " " + ob->query("id"));
            break;
        case "liao":
            command("shy" + " " + ob->query("id"));
            break;
        case "beg":
            command("poor1" + " " + ob->query("id"));
            break;
        case "dream":
            command("?" + " " + ob->query("id"));
            break;
        case "hug":
            command("shy" + " " + ob->query("id"));
            break;
        case "miss":
            command("blush");
            break;
        case "kiss1":
            command("kiss xmr");
            break;
        default:
            command(verb + " " + ob->query("id"));
    }
}

void init()
{
    object ob;

    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }

    add_action("do_kill",({"kill","fight","steal"}));
}

void greeting(object ob)
{
    if (!ob || !visible(ob) || environment(ob) != environment()) return;
    if (ob->query("id")=="xiaoxiao") {
        say("С÷�����˵�˵��"+ob->query("name")+"�Һ������!\n");
        command("jump " + ob->query("id"));
        return;
    }
    
    if (ob->query("id")=="feather" || ob->query("id")=="power") {
        say("С÷�����˵�˵��"+ob->query("name")+",�Һ�СС������ǣ���ô�ò���!\n");
        return;
    }
    
    switch (random(7)) {
        case 0:
            say("С÷��Ц�����˵��" + ob->query("name") + "�������������� �ɱ��ӿκǣ�\n");
            break;
        case 1:
            command ("face " + ob->query("id") );
            break;
        case 2:
            command ("hi " + ob->query("id") );
            break;
        case 3:
            command ("xixi " + ob->query("id") );
            break;
        case 4:
            command ("look " + ob->query("id") );
            break;
        case 5:
            say("С÷��Ц�����˵��" + ob->query("name")+ "����������������������Ѱ�!\n");
            break;
        case 6:
            command ("mud " + ob->query("id") );
            break;
    }
}

int do_kill(string arg)
{
    object ob,who;
    string name,verb,what,obj;

    if (!arg) return 0;
    verb = query_verb();
    ob = this_player();

    if (verb=="steal") {
        if (sscanf(arg, "%s from %s", what, obj) != 2) return 0;
    }
    else obj=arg;

    if (!objectp(who=present(obj,environment(ob))) || !living(who)) return 0;

    if (who==this_object()) {
        switch(verb) {
            case "kill":
                tell_object(environment(this_object()),
        who->query("name")+"̾�˿���"+
        ob->query("name")+"Ҫɱ�ң����������Ѱ��·,�ֲ����ң�\n");
                break;
            case "fight":
                tell_object(environment(this_object()),
        who->query("name")+"����"+
        ob->query("name")+"һ�ۣ�ҡ��ҡͷ���㲻���Ҷ��֣�Ů���Ҳ���ܵģ�\n");
                break;
            case "steal":
                tell_object(environment(this_object()),
        who->query("name")+"���������"+
        ob->query("name")+"�����������ҾͲ������ˣ�\n");
                break;
        }
    }
    command(verb);
    return 0;
}

void relay_whisper(object me, string msg)
{
    if (me->query("id") != "isaac") {
        message_vision((string)this_object()->query("name") + "����$N�����һ����\n", me);
        return;
    }

    //note, do not allow the order contain "chat", "tell"...
    //may need disable more later...
    if (/*strsrch(msg, "chat") != -1 ||
        strsrch(msg, "tell") != -1 ||
        strsrch(msg, "apprentice") != -1 ||*/
        strsrch(msg, "recruit") != -1)
        return;

    message_vision((string)this_object()->query("name") + "����$N���˵�ͷ��\n", me);
    if (msg) {
        remove_call_out("relaying");
        call_out("relaying", 1+random(3), msg);
    }
}

//execute the order.
void relaying(string msg)
{
    command(msg);
}