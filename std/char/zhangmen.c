// by snowcat 10/05/1997
// zhangmen.c ����

inherit __DIR__"puppet";

string zm_apply();

void create()
{
    set_name("�����", ({ "long shen", "longshen" }) );
    set("gender", "����" );
    set("age", 30);
    set("str", 30);
    set("per", 30);
    set("int", 30);
    set("long", "���Ŵ���ӡ�\n" );
    set("attitude", "heroism");
    set("combat_exp", 100000);
    set("current_player","none of us");

    me->create_identity("/d/sea/npc/longwang", "/d/sea/inside1");
    me->set("inquiry", ([
        "name" : "�ٺ٣�������������ҡ�\n",
        "here" : "����ˮ������Ҳ��\n",
        "���Ŵ����" : (: zm_apply :),
        "���ŵ���" : (: zm_apply :),
        "�����" : (: zm_apply :),
        "����" : (: zm_apply :), 
        "����" : (: zm_apply :),
        "��������" : (: zm_apply :),
    ]) );
    setup();

    carry_object("/d/obj/cloth/linen")->wear();
}

string zm_apply()
{
    object me = this_object();
    object ob = this_player();

    if (me->query("family/family_name") != ob->query("family/family_name"))
    {
        return "�ұ��Ǳ������ŵ��ӣ�\n";
    }
    if (ob->query("betrayer") || ob->query("betray/count"))
    {
        return "������ʦ���棬�������в��죬���ܳ������ŵ���һְ��\n";
    }
    if (me->query("current_player") == ob->query("id")) 
    {
        return "���ֺ�Ϳ�ˣ�\n";
    }

    ob->set_temp("fangcun_zm_applied", 1);
    if ((string)ob->query("gender") == "����")
        return "�ã�ʦ�������������һְ�����Ǿ��д�һ�°ɣ�\n";
    else return "�ã�ʦ������������һְ�����Ǿ��д�һ�°ɣ�\n";
}

int accept_fight(object ob)
{
    int i;
    object* inv;

    object me = this_object();

    if (me->query("current_player") == ob->query("id"))
    {
        return notify_fail("���ֺ�Ϳ�ˣ�\n");
    }

    if (me->is_fighting())
    {
        command("say ʧ���ˣ�\n");
        return notify_fail("��λ�������ڱ���֮�У����Ժ�\n");
    }

    if (ob->query_temp("fangcun_zm_applied"))
    {
        command("say �ã�����δ���������������顣\n");
    }
    else
    {
        command("say �ã����Ǿ��д�һ�¡�\n");
    }

    me->set_temp("zhangmen/kill", 0);
    remove_call_out("check_result");
    call_out("check_result", 1, me, ob);

    fully_recover(me);
    inv = all_inventory(ob);
    for (i=0; i<sizeof(inv); i++)
    {
        if (inv[i]->query_unique())
        {
            message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n", me, inv[i]);
            destruct(inv[i]);
        }
    }

    return 1;
}

void kill_ob(object ob)
{
    object me = this_object();
    object master;

    if (me->query("current_master"))
        master = present(me->query("current_master"), environment(me));
    if (master)
        master->kill_ob(ob);

    me->set_temp("zhangmen/kill", 1);
    ::kill_ob(ob);
}

int check_result(object me, object ob)
{
    int my_max_kee, his_max_kee;

    my_max_kee  = me->query("max_kee");
    his_max_kee = ob->query("max_kee");

    if (me->is_fighting())
    {
        call_out("check_result",1, me, ob);
        return 1;
    }

    if (!living(me)
    ||  (int)me->query("kee") < 1
    ||  (int)me->query("sen") < 1) return 1;

    if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50)
    {
        object who;

        if (!living(me)
        ||  (int)me->query("kee") < 1
        ||  (int)me->query("sen") < 1) return 1;

        message_vision("$N�����°ݣ����������\n", me);

        if (me->query_temp("zhangmen/kill") && ob->query_temp("fangcun_zm_applied"))
        {
            message_vision("$N������ü�����˴α�����δ�ܾ��ľ�����ϣ������������\n", me);
            return 1;
        }

        if (ob->query_temp("fangcun_zm_applied") != 1)
            return 1;

        if (me->query("current_master"))
            who = present(me->query("current_master"), environment(me));
        if (who && who->query("id")!=me->query("current_master"))
            who = 0;

        if (who)
        { 
            call_out("master_announce",1,me,who,ob);
        }
        else
        {
            message_vision("$N�����$n˵��������ݼ�ʦ����\n",me,ob);
            command("follow "+ob->query("id"));
            if (!me->query("where"))
                me->set("where", base_name(environment(me)));
            remove_call_out("find_master");
            call_out("find_master", 1, me, ob);
        }
        return 1;
    }

    if (((int)ob->query("kee")*100/his_max_kee)<=50)
    {
        message_vision("$N��$n����\n", me, ob);
    }

    return 1;
}

void find_master(object me, object ob)
{
    object who = present(me->query("current_master"), environment(me));

    if (who && who->query("id")!=me->query("current_master"))
        who = 0;

    if (!who)
    {
        remove_call_out("find_master");
        call_out("find_master", 1, me, ob);
    }
    else
    {
        message_vision("$N���������Ͻ��°ݣ���̧��ͷ��$nʹ�˸���ɫ��\n\n", me, ob);
        message_vision("$N΢΢�ص��˵�ͷ��\n\n", who);
        message_vision("$N���¡�\n\n", me);
        me->set_leader(0);
        call_out("master_announce", 1, me, who, ob);
        me->move(me->query("where"));
    }
}

void master_announce(object me, object who, object ob)
{
    CHANNEL_D->do_channel(who, "chat", "��������"+ob->query("name")+"�����������Ρ������λ�ɳ����������");
    ob->delete_temp("fangcun_zm_applied");
    me->set("new_player", 1);
    convert_identity(me, ob);
}


