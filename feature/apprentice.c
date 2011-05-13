// apprentice.c

#include <dbase.h>

varargs int is_apprentice_of(object ob, int raw)
{
    mapping family;
    string hist_id;
    
    if (!mapp(family = query("family"))) return 0;
    
    if (family["master_id"] == (string)ob->query("id")
    &&  family["master_name"] == (string)ob->query("name")
    &&  family["family_name"] == (string)ob->query("family/family_name"))
        return 1;
    
    if (raw) return 0;
    
    hist_id = "family_history/";
    hist_id +=  (string)ob->query("family/family_name");
    hist_id += "/";
    hist_id += (string)ob->query("id");
    hist_id += "/master_name";
    if (query(hist_id) == (string)ob->query("name")) return 1;
    
    return 0;
}

void assign_apprentice(string title, int privs)
{
    mapping family;
    
    if (!mapp(family = query("family"))) return;
    
    family["title"] = title;
    family["privs"] = privs;
    
    if (userp(this_object()) || !query("title")) {
        if (family["generation"] == 1)
            set("title", family["family_name"] + "��ɽ��ʦ");
        else
            set("title", sprintf("%s��%s��%s", family["family_name"],
            chinese_number(family["generation"]), family["title"]));
    }
}

// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
    mapping family;
    
    family = allocate_mapping(6);
    
    family["family_name"] = family_name;
    family["generation"] = generation;
    
    set("family", family);
    
    // priv = -1 for ALL privileges.
    assign_apprentice(title, -1);
}

int recruit_apprentice(object ob)
{
    mapping my_family, family, old_family, hist;
    string old_family_name, old_master_id;
    string second_family_name = query("second_family_name");
    int speciel_mode = 0;
    
    if (ob->is_apprentice_of(this_object(), 1)) return 0;
    if (!mapp(my_family = query("family"))) return 0;
    
    if (mapp(old_family = ob->query("family"))) {
        old_family_name = old_family["family_name"];
        old_master_id = old_family["master_id"];
        
        if (!mapp(hist = ob->query("family_history/" + old_family_name)))
            hist = ([]);
        if (undefinedp(hist[old_master_id])) {
            hist[old_master_id] = allocate_mapping(4);
            hist[old_master_id]["master_name"] = old_family["master_name"];
            hist[old_master_id]["generation"] = old_family["generation"];
            hist[old_master_id]["first_enter"] = old_family["enter_time"];
        }
        hist[old_master_id]["last_out"] = time();
        ob->set("family_history/" + old_family_name, hist);
    }
    
    if (stringp(second_family_name)
    &&  stringp(old_family_name)
    &&  second_family_name == old_family_name)
        speciel_mode = 1;
    family = allocate_mapping(sizeof(my_family));
    family["master_id"] = query("id");
    family["master_name"] = query("name");
    family["family_name"] = speciel_mode ? second_family_name : my_family["family_name"];
    family["generation"] = speciel_mode ? 2 : my_family["generation"] + 1;
    family["enter_time"] = time();
    ob->set("family", family);
    ob->assign_apprentice("����", 0);
    return 1;
}

int expell_apprentice(object ob)
{
    object me = this_object();
    string myfamily = (string)me->query("family/family_name");

    if (me->query("family/privs") == -1
    &&  myfamily ==(string)ob->query("family/family_name")) {
        message_vision("$N����$n˵�����ӽ���������Ҳ������" + myfamily + "�ĵ����ˣ����߰ɣ�\n\n", me, ob);
        tell_object(ob, "\n�㱻" + me->query("family/title") + "�����ʦ���ˣ�\n\n");
    } else if (ob->is_apprentice_of(me, 1)) {
        message_vision("$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n", me, ob);
        message_vision("$N����$n˵���������粨���ƶ����Σ�����Ϊ֮������\n\n", me, ob);
        tell_object(ob, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
    } else
        return notify_fail("����˲�����ĵ��ӡ�\n");
    
    ob->delete("family/master_name");
    ob->delete("family/master_id");
    ob->set("title", ob->query("family/family_name") + "��ͽ");
    return 1;
}
