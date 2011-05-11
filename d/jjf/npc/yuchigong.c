//created 5-20-97 pickle
 
inherit NPC;

void create()
{
    set_name("ξ�ٹ�", ({"yuchi gong", "yuchi", "gong", "yuchigong", "jingde", "yuchi jingde", "yuchijingde", "master", "shifu"}));
    set("long", @LONG
ξ�ٹ����־��£�������̫�������ͽ�����Ϊ����ʱ��
ʮ�����ú���������Ƿ��������ݵ�ǰԪ˧���������
���ơ�����ʹһ�����ǹ����ϲʹһ�Դ�����ڸֱޡ�
LONG);

    set("title", "����Ԫѫ");
    set("gender", "����");
    set("age", 43);
    set("str", 45);
    set("per", 15);
    set("int", 20);
    set("cor", 50);
    set("cps", 40);
    set("combat_exp", 1400000);
    set_skill("spear", 120);
    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("parry", 120);
    set_skill("mace", 180);
    set_skill("jinglei-mace", 150);
    set_skill("yanxing-steps", 120);
    set_skill("bawang-qiang", 100);
    set_skill("lengquan-force", 150);
    set_skill("unarmed", 120);
    set_skill("changquan", 100);
    map_skill("mace", "jinglei-mace");
    map_skill("force", "lengquan-force");
    map_skill("unarmed", "changquan");
    map_skill("spear", "bawang-qiang");
    map_skill("parry", "jinglei-mace");
    map_skill("dodge", "yanxing-steps");
    set("max_sen", 1500);
    set("max_kee", 4000);
    set("force", 1000);
    set("max_force", 2500);
    set("force_factor", 100);

    create_family("������", 2, "��");
    setup();

    carry_object("/d/obj/weapon/spear/gangqiang");
    carry_object("/d/obj/weapon/mace/malemace")->wield();
    carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
    command("say �Ϸ����أ��������˷��������ˡ�\n");
    return 0;
}

void attempt_apprentice(object me)
{
    string myname = RANK_D->query_rude(me);
    int effstr = (int)(me->query("str")+me->query_skill("unarmed",1)/10-2);

    if (effstr < 20 || (int)me->query_con() < 25) {
        command("say ��"+myname+"���޸���֮������������ͽ�ܣ�");
        return;
    }
    if ((int)me->query("cps") < 20 && (int)me->query_cor() < 20) {
        command("say ��"+myname+"���ӻ�����ֻ����");
        return;
    }
    command("say Ҫ�����Ϊʦ����Ҳ���ѡ�ֻ�轫����Ԫ��������С�����Ӹ���׽������������һ�پ��У�\n");
    return;
}

int accept_object(object me, object ob)
{
    string myname = RANK_D->query_rude(me);
    string obname = ob->query("id");
    int kar = me->query_kar(), diff;

    if (!ob->is_character()
    ||  userp(ob)
    ||  (obname != "li jiancheng" && obname != "li yuanji")) {
        command ("say ����ʲô���ã�");
        return 0;
    }
    me->add_temp("yuchg/give " + obname, 1);
    
    if (me->query_temp("yuchg/give li jiancheng") && me->query_temp("yuchg/give li yuanji")) {
        command("hehe");
        command("say ������˻����ǻ������⽫������С�����Ӹ���ŵ����Ƕ��棬�����Ǵ��˽��ơ�");
        command("say ��Ȥ����Ȥ��");
        command("say �����Ǹ��޳��е���Ȥ�����������Ǳ�������С������Ū���ģ���񸴻���Ҳ���������ǵ��鷳�����Ǹ㲻����");
        if (me->query_temp("pending/apprentice") == this_object()) {
            command("look " + me->query("id"));
            command("nod");
            command("say "+myname+"��Ȼ�������ӣ��Ϸ��������ɣ�");
            command("recruit " + me->query("id"));
        } else if (!me->query("family")) {
            command("look " + me->query("id"));
            command("nod");
            command("say "+myname+"���ҿ���������棬�Ǹ��������ţ����統�ҵ�ͽ�ܰɡ�");
            command("recruit " + me->query("id"));
        } else if (me->is_apprentice_of(this_object())) {
            command("recruit " + me->query("id"));
        } else {
            command("look " + me->query("id"));
            command("nod");
            command("say ��ϧ��"+myname+"���Ѿ�����ʦ�ţ������Ϸ�Ҫ����Ϊͽ��");
            command("whisper "+ me->query("id") +"�ô�Ҳ�������ģ����ڳ�����������������һ���ؼ���"+myname+"��������Ȥ������ȥ���ҡ�");
        }
        me->delete_temp("yuchg");
    } else {
        command("say �ã��ã��ã�");
        command("say ����һ�������Ǹ�ҲŪ������Ȼ����ĺô���");
    }
    
    call_out("destroy", 1, ob);
    return 1;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "fighter");
}

void destroy(object ob)
{
    if (ob) destruct(ob);
}
