// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat
// quest.c

inherit F_CLEAN_UP;

#include <ansi.h>
#include <dbase.h>
#include <origin.h>

void create()
{
        seteuid(getuid());
}

int quest_give (object me, object who, object ob)
{
   if (me->query("quest/pending/give/name") != who->query("name") ||
            me->query("quest/pending/give/id")   != who->query("id"))
     return 0;

   if (me->query("quest/pending/give/objectname") != ob->query("name") ||
            me->query("quest/pending/give/objectid") != ob->query("id"))
     return 0;

   me->set("quest/pending/give/done",1);
   return 1;
}

string quest_ask (object me, object who, string topic)
{

   if (me->query("quest/pending/ask/name") != who->query("name") ||
            me->query("quest/pending/ask/id")   != who->query("id"))
     return 0;
   
   if (me->query("quest/pending/ask/topic") != topic)
     return 0;

   me->set("quest/pending/ask/done",1);
   return me->query("quest/pending/ask/acknowledge");
}

void quest_kill (object me)
{
   object killer = me->query_temp("last_damage_from");

   if (! killer)
     return;

   if (killer->query("quest/pending/kill/name") != me->query("name") ||
            killer->query("quest/pending/kill/id")   != me->query("id"))
     return 0;
   
   killer->set("quest/pending/kill/done",1);
}

string check_quests_detail(object who, object checker)
{
    string name = checker == who ? "��" : who->query("name");
    string str = "";
    mapping mapp;

    if (who->query("quest") == 0) {
        str += (name+"û�н��κ��ԡ�\n");
        return str;
    }

    str += (name+"�Ѿ�����"+(who->query("quest/number"))+"���ԡ�\n");

    str += ("    ʳ�"+"����"+(who->query("quest/food/times"))+"�Σ�"+
        "���"+(who->query("quest/food/reward"))+"��Ʒ�¡�\n");
    str += ("    ���"+"����"+(who->query("quest/give/times"))+"�Σ�"+
        "���"+(who->query("quest/give/reward"))+"��Ʒ�¡�\n");
    str += ("    ���ͣ�"+"����"+(who->query("quest/ask/times"))+"�Σ�"+
        "���"+(who->query("quest/ask/reward"))+"��Ʒ�¡�\n");
    str += ("    ������"+"����"+(who->query("quest/kill/times"))+"�Σ�"+
        "���"+(who->query("quest/kill/reward"))+"��Ʒ�¡�\n");
    str += ("    ������"+"����"+(who->query("quest/weapon/times"))+"�Σ�"+
        "���"+(who->query("quest/weapon/reward"))+"��Ʒ�¡�\n");
    str += ("    ���ף�"+"����"+(who->query("quest/armor/times"))+"�Σ�"+
        "���"+(who->query("quest/armor/reward"))+"��Ʒ�¡�\n");
    str += ("    ���"+"����"+(who->query("quest/cloth/times"))+"�Σ�"+
        "���"+(who->query("quest/cloth/reward"))+"��Ʒ�¡�\n");
    str += ("    ���Σ�"+"����"+(who->query("quest/wearing/times"))+"�Σ�"+
        "���"+(who->query("quest/wearing/reward"))+"��Ʒ�¡�\n");
    str += ("    ��ʲ��"+"����"+(who->query("quest/furniture/times"))+"�Σ�"+
        "���"+(who->query("quest/furniture/reward"))+"��Ʒ�¡�\n");
    str += ("\n");

    str += (name+"����ã�\n");
    str += ("    Ǳ�ܣ�"+(who->query("quest/gain/potential"))+"�㡣\n");
    str += ("    ���У�"+COMBAT_D->chinese_daoxing(who->query("quest/gain/combat_exp"))+"���С�\n");
    str += ("    ���ܣ�\n");
    mapp = who->query("quest/gain/skills");
    if (mapp) {
        string *my_keys = keys(mapp);
        int i = sizeof(my_keys);
        while (i--) {
            str += ("      "+SKILL_D(my_keys[i])->name()+(mapp[my_keys[i]])
                +"�㡣\n");
        }
    }
    str += ("    ���ԣ���ʱ���ƣ���\n");
    mapp = who->query("quest/gain/apply");
    if (mapp) {
        string *my_keys = keys(mapp);
        int i = sizeof(my_keys);
        while (i--) {
            str += ("      "+(my_keys[i])+(mapp[my_keys[i]])
                +"�㡣\n");
        }
    }
    str += ("    ���ӣ�"+(who->query("quest/gain/silver"))+"����\n");
    str += ("\n");

    str += (name+"�ո���ɵ����ǣ�\n");
    if (who->query("quest/reason")) {
        str += ("  ��"+who->query("quest/reason")+"������");
        if (who->query("quest/reward")) {
            if (wizardp(checker)) 
                str += ("  ������"+(who->query("quest/reward"))+"�㽱����\n");
            else  
                str += ("  �����н�����\n");
            }  
        else
            str += ("\n");
    }
    str += ("\n");

    str += (name+"�������¼������ڽ���ԣ�\n");
    if (mapp = who->query("quest/pending/food")) {
        str += ("  ʳ�"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/give")) {
        str += ("  ���"+mapp["name"] + " " + mapp["objectname"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/ask")) {
        str += ("  ���ͣ�"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/kill")) {
        str += ("  ������"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/weapon")) {
        str += ("  ������"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/armor")) {
        str += ("  ���ף�"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/cloth")) {
        str += ("  ���"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/wearing")) {
        str += ("  ���Σ�"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    if (mapp = who->query("quest/pending/furniture")) {
        str += ("  ��ʲ��"+mapp["name"]);
        if (wizardp(checker))
            str += (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
        else 
            str += ("\n");
    }
    str += ("\n");

    if (!wizardp(checker))
        return str;

    str += (name+"�����ݴ�ʹ��ͳ�ƣ�\n");
    if (mapp = who->query("quest/cache/food"))
        str += ("  ʳ�"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/give"))
        str += ("  ���"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/ask"))
        str += ("  ���ͣ�"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/kill"))
        str += ("  ������"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/weapon"))
        str += ("  ������"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/armor"))
        str += ("  ���ף�"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/cloth"))
        str += ("  ���"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/wearing"))
        str += ("  ���Σ�"+(sizeof(mapp))+"��\n");
    if (mapp = who->query("quest/cache/furniture"))
        str += ("  ��ʲ��"+(sizeof(mapp))+"��\n");
    str += ("\n");

    return str;
}
