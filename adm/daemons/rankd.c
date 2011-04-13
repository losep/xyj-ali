// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
    // need this default, otherwise looks too ugly sometimes.
    if (strlen(ob->query("added_title"))<1)
        ob->set("added_title", "δ��");

    if (ob->is_ghost()) return HIB "�� ��  �� ��" NOR;

    switch (ob->query("gender"))
    {
// begin Ů�ԣ�
        case "Ů��":
            switch (wizhood(ob)) {
                case "(admin)":         return GRN "�� ��  Ů ��" NOR;
                case "(arch)":          return GRN "�� ��  Ů ��" NOR;
                case "(wizard)":        return GRN "�� ��  Ů ��" NOR;
                case "(apprentice)":    return GRN "��������Ů��" NOR;
                case "(immortal)":      return GRN "�� С��Ů ��" NOR;
                case "(elder)":         return GRN "��������ҡ�" NOR;
                default:
                switch (ob->query("class"))
                {
//------------------rank for girls--------------------
case "xian":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� ��  Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� С�ɹ� ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� ��  Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"���ӡ�" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "��"+ob->query("added_title")+"ʥŮ��" NOR;
    else
        return GRN "��"+ob->query("added_title")+"Ů����" NOR;
    break;
case "yaomo":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� С��Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� ��  Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"������" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "��"+ob->query("added_title")+"ħŮ��" NOR;
    else
        return GRN "��"+ob->query("added_title")+"Ů����" NOR;
    break;
case "bonze":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� С��� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� Сʦ̫ ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� ʦ  ̫ ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"���᡿" NOR;
    else
        return GRN "��"+ob->query("added_title")+"������" NOR;
    break;
case "taoist":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� Ů��ͯ ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� С���� ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� ��  Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"��Ů��" NOR;
    else
        return GRN "��"+ob->query("added_title")+"ʥĸ��" NOR;
    break;
case "dragon":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� С���� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� ��  Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� С��Ů ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"��Ů��" NOR;
    else
        return GRN "��"+ob->query("added_title")+"������" NOR;
    break;
case "scholar":
    if ((string)ob->query("added_title")=="δ��") {
        if ((int)ob->query_skill("literate", 1)<20)
            return GRN "�� Ůѧͯ ��" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return GRN "�� ��  Ů ��" NOR;
        else
            return GRN "�� Ůѧʿ ��" NOR;
    } else {
     if ((int)ob->query_skill("literate", 1)<20)
         return GRN "�� Ůѧͯ ��" NOR;
     else if ((int)ob->query_skill("literate", 1)<100)
         return GRN "��"+ob->query("added_title")+"��š�" NOR;
     else
         return GRN "��"+ob->query("added_title")+"ѧʿ��" NOR;
    }
    break;
case "soldier":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "�� Ů  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "�� ŮУξ ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "�� Ů���� ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"������" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "��"+ob->query("added_title")+"�󽫾���" NOR;
    else
        return GRN "��"+ob->query("added_title")+"��Ԫ˧��" NOR;
    break;
case "ghost":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "������С��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "���Ի�Ů��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "����ڤŮʹ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "��"+ob->query("added_title")+"�޳���" NOR;
    else
        return GRN "��"+ob->query("added_title")+"Ů����" NOR;
    break;   
case "dancer":
    return GRN "�� ��  �� ��" NOR;
    break;
default:
    return MAG "�� ƽ  �� ��" NOR;
//------------------end rank for girls--------------------
                }
            }
// begin ���ԣ�
        default:
        switch (wizhood(ob))
        {
            case "(admin)":             return HIW "�� ��  ʦ ��" NOR;
            case "(arch)":              return HIW "�� ��  ʦ ��" NOR;
            case "(wizard)":            return HIW "�� ��  ʦ ��" NOR;
            case "(apprentice)":        return HIW "��������ʦ��" NOR;
            case "(immortal)":          return HIW "�� С��ʦ ��" NOR;
            case "(elder)":             return HIW "��������ҡ�" NOR;
            default:
            switch (ob->query("class"))
            {
//------------------rank for men--------------------
case "xian":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� ��  ͯ ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� ɢ  �� ��" NOR;
    else if((int)ob->query("combat_exp")<100000)
        return RED "�� ��  �� ��" NOR;
    else if((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"���ɡ�" NOR;
    else if((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"���ɡ�" NOR;
    else
        return RED "��"+ob->query("added_title")+"����" NOR;
    break;
case "yaomo":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� С  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "�� "+ob->query("added_title")+"�� ��" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"��ħ��" NOR;
    else
        return RED "��"+ob->query("added_title")+"ħ����" NOR;
    break;
case "bonze":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� С���� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "�� ʥ  ɮ ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"���ߡ�" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"�޺���" NOR;
    else
        return RED "��"+ob->query("added_title")+"������" NOR;
    break;
case "taoist":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� С��ʿ ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� ��  ʿ ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"��ʦ��" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"���ˡ�" NOR;
    else
        return RED "��"+ob->query("added_title")+"����" NOR;
    break;
case "dragon":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� Ϻ  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� з  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "��Ѳ��ҹ�桿" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"ҹ�桿" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"����" NOR;
    else
        return RED "��"+ob->query("added_title")+"������" NOR;
    break;
case "scholar":
    if ((string)ob->query("added_title")=="δ��") {
        if ((int)ob->query_skill("literate", 1)<20)
            return RED "�� ͯ  �� ��" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return RED "�� ��  �� ��" NOR;
        else
            return RED "�� ��ѧʿ ��" NOR;
    } else {
        if ((int)ob->query_skill("literate", 1)<20)
            return RED "�� ͯ  �� ��" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return RED "��"+ob->query("added_title")+"��š�" NOR;
        else
            return RED "��"+ob->query("added_title")+"ѧʿ��" NOR;
    }
    break;
case "soldier":
    if ((int)ob->query("combat_exp")<1000)
        return RED "�� С  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "�� С  У ��" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "�� ��  �� ��" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"������" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"�󽫾���" NOR;
    else
        return RED "��"+ob->query("added_title")+"��Ԫ˧��" NOR;
    break;
case "ghost":
    if ((int)ob->query("combat_exp")<1000)
        return RED "������С��" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "������ʹ�ߡ�" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "���ظ��й١�" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "��"+ob->query("added_title")+"�޳���" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "��"+ob->query("added_title")+"������" NOR;
    else
        return RED "��"+ob->query("added_title")+"����" NOR;
    break;
default:
    return "�� ƽ  �� ��";
//------------------end rank for men--------------------
            }
        }
    }
}

string query_respect(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/respect")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "Ů��":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 18 ) return "Сʦ̫";
   else return "ʦ̫";
   break;
case "taoist":
   if( age < 18 ) return "С�ɹ�";
   else return "�ɹ�";
   break;
case "xian":
   if( age < 18 ) return "С�ɹ�";
   else return "�ɹ�";
   break;
default:
   if( age < 18 ) return "С����";
   else if( age < 50 ) return "����";
   else return "����";
   break;
        }
     case "����":
     default:
        switch(ob->query("class")) 
        {
case "xian":
   if( age < 18 ) return "С����";
   else if( age < 50 ) return "����";
   else return "������";
   break;
case "bonze":
   if( age < 18 ) return "Сʦ��";
   else if( age < 50 ) return "��ʦ";
   else return "����";
   break;
case "taoist":
   if( age < 18 ) return "С��ү";
   else if( age < 50 ) return "����";
   else return "����";
   break;
case "soldier":
   if( age < 18 ) return "С����";
   else if( age < 50 ) return "�󽫾�";
   else return "�Ͻ���";
   break;
case "scholar":
   if( age < 18 ) return "С�๫";
   else if( age < 50 ) return "�๫";
   else return "������";
   break;
case "swordsman":
   if( age < 18 ) return "С�ϵ�";
   else if( age < 50 ) return "׳ʿ";
   else return "��ǰ��";
   break;
default:
   if( age < 18 ) return "С�ֵ�";
   else if( age < 50 ) return "׳ʿ";
   else return "��ү��";
   break;
        }
   }
}

string query_rude(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/rude")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "Ů��":
        switch(ob->query("class")) 
        {
case "xian":
   if(age < 30) return "С����";
   else if(age < 50) return "��Ů";
   else return "������";
   break;
case "yaomo":
   if(age < 30) return "С��Ů";
   else if(age < 50) return "��Ů";
   else return "������";
   break;
case "bonze":
   if(age < 30) return "С����";
   else if(age < 50) return "����";
   else return "������";
   break;
case "taoist":
   if(age < 30) return "С��Ů";
   else if(age < 50) return "��Ů";
   else return "������";
   break;
default:
   if( age < 30 ) return "С����";
   else if(age < 50) return "����";
   else return "����̫��";
   break;
        }
     case "����":
     default:
        switch(ob->query("class")) 
        {
case "xian":
   if( age < 50 ) return "������";
   else return "������";
   break;
case "yaomo":
   if( age < 50 ) return "������";
   else return "������";
   break;
case "bonze":
   if( age < 50 ) return "��ͺ¿";
   else return "��ͺ¿";
   break;
case "taoist":
   return "��ţ����";
   break;
case "scholar":
   if( age < 18 ) return "С�����";
   else if( age < 50 ) return "�������";
   else return "��ͯ��";
   break;
default:
   if( age < 18 ) return "С���˵�";
   else if( age < 50 ) return "����";
   else return "��ƥ��";
   break;
        }
   }
}

string query_self(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/self")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "Ů��":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "ƶ��";
   else return "����";
   break;
default:
   if( age < 30 ) return "СŮ��";
   else return "���";
   break;
        }
     case "����":
     default:
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "ƶɮ";
   else return "����";
   break;
case "taoist":
   return "ƶ��";
   break;
case "scholar":
   if( age < 30 ) return "����";
   else return "����";
   break;
default:
   if( age < 50 ) return "����";
   else return "��ͷ��";
   break;
        }
   }
}

string query_self_rude(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/self_rude")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "Ů��":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "ƶ��";
   else return "����";
   break;
default:
   if( age < 50 ) return "������";
   else return "����";
   break;
        }
     case "����":
     default:
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "�������";
   else return "�Ϻ�����";
   break;
case "taoist":
   return "��ү��";
   break;
case "scholar":
   if( age < 50 ) return "���๫";
   else return "�Ϸ�����";
   break;
default:
   if( age < 18 ) return "���Сү��";
   else if( age < 50 ) return "��ү��";
   else return "��үү��";
   break;
        }
   }
}

//descriptions...

//note, be careful with the size of this list, exp increases as n^3. 
string *exp_level_desc = ({
        BLU "�����;" NOR, //in unit of year 
        BLU "�ŵ���ϲ" NOR, //1x2=2   
        BLU "�������" NOR, //8x2=16
        BLU "��ͨ����" NOR, //27x2=56    
        HIB "����Ѿ�" NOR, //64x2=128
        HIB "Ԫ�����" NOR, //125x2=250
        HIB "�����ȹ�" NOR, //216x2=432    
        HIB "һ��ǧ��" NOR, //343x2=686
        CYN "���ߵ�¡" NOR, //512x2=1024
        CYN "��̥����" NOR, //729x2=1458    
        CYN "ϼ�ٷ���" NOR, //1000x2=2000
        CYN "��������" NOR, //1331x2=2662    
        HIC "�����ֻ�" NOR, //1728x2=3456
        HIC "��֤���" NOR, //2197x2=4394    
        HIC "��豹���" NOR, //2744x2=5688 
        HIW "���˺�һ" NOR  //3375x2=6750
});

string *mana_level_desc = ({
        BLU "���߷���" NOR, //    
        BLU "�����仯" NOR, //1x40=40
        BLU "��������" NOR, //4x40=160
        HIB "���Ƽ���" NOR, //9x40=360   
        HIB "�����û" NOR, //16x40=640
        HIB "Ԥ֪����" NOR, //25x40=1000
        HIB "�������" NOR, //36x40=1440    
        CYN "���绽��" NOR, //49x40=1960
        CYN "������ɽ" NOR, //64x40=2560    
        CYN "���ǻ���" NOR, //81x40=3240
        CYN "��������" NOR, //100x40=4000
        HIC "��������" NOR, //121x40=4840    
        HIC "�任Ī��" NOR, //144x40=5760
        HIW "�����ޱ�" NOR  //169x40=6760
});

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "�����ž�" NOR,
        BLU "��ͨƤë" NOR,
        HIB "��֪һ��" NOR,
        HIB "��������" NOR,
        HIB "��������" NOR,
        YEL "������" NOR,
        YEL "ƽ������" NOR,
        YEL "ƽƽ����" NOR,
        HIY "�������" NOR,
        HIY "������ͨ" NOR,
        HIY "����ǳ��" NOR,
        HIM "��������" NOR,
        HIM "�������" NOR,
        HIM "��Ȼ����" NOR,
        HIR "�������" NOR,
        HIR "����Ѿ�" NOR,
        HIR "��Ȼ��ͨ" NOR,
        MAG "�Ƿ��켫" NOR,
        MAG "�����뻯" NOR,
        MAG "����似" NOR,
        CYN "��Ⱥ����" NOR,
        CYN "��������" NOR,
        CYN "׿Ȼ���" NOR,
        HIC "һ����ʦ" NOR,
        HIC "��ǰ����" NOR,
        HIC "���ž���" NOR,
        WHT "������" NOR,
        WHT "������ʥ" NOR,
        WHT "��豹���" NOR,
        HIW "��ɲ�" NOR
/* from xyj2000
        BLU "��ѧէ��" NOR,
        BLU "��֪����" NOR,
        BLU "��ͨƤë" NOR,
        HIB "��ʶ֮��" NOR,
        HIB "��������" NOR,
        HIB "��������" NOR,
        YEL "������" NOR,
        YEL "ƽ������" NOR,
        YEL "ƽƽ����" NOR,
        HIY "������ͨ" NOR,
        HIY "�������" NOR,
        HIY "����ǳ��" NOR,
        HIM "��������" NOR,
        HIM "�������" NOR,
        HIM "�������" NOR,
        HIR "����Ѿ�" NOR,
        HIR "����似" NOR,
        HIR "�����ɵ�" NOR,
        MAG "�����뻯" NOR,
        MAG "��Ȼ��ͨ" NOR,
        MAG "��Ⱥ����" NOR,
        CYN "�Ƿ��켫" NOR,
        CYN "׿Ȼ���" NOR,
        CYN "һ����ʦ" NOR,
        HIC "��������" NOR,
        HIC "��ǰ����" NOR,
        HIC "���ž���" NOR,
        WHT "������" NOR,
        WHT "������ʥ" NOR,
        WHT "��豹���" NOR,
        HIW "��ɲ�" NOR
*/
/* /cmds/std/check.c
    BLU "��ѧէ��" NOR,   BLU "�����ž�" NOR,
    HIB "��ͨƤë" NOR,   HIB "��֪һ��" NOR,
    YEL "��������" NOR,   YEL "������" NOR,
    HIY "����С��" NOR,   HIY "����Ѿ�" NOR,
    HIM "�������" NOR,   HIM "��Ȼ����" NOR,
    HIR "�������" NOR,   HIR "�������" NOR,
    MAG "����似" NOR,   MAG "�����뻯" NOR,
    CYN "��Ȼ��ͨ" NOR,   CYN "�Ƿ��켫" NOR,
    HIC "������˫" NOR,   HIC "һ����ʦ" NOR,
    HIC "������" NOR,   HIW "��ɲ�" NOR
*/
/* /cmds/usr/skills.c
    BLU "��ѧէ��" NOR,
    BLU "�����ž�" NOR,
    HIB "��ͨƤë" NOR,
    HIB "��֪һ��" NOR,
    YEL "��������" NOR,
    YEL "������" NOR,
    HIY "����С��" NOR,
    HIY "����Ѿ�" NOR,
    HIM "�������" NOR,
    HIM "��Ȼ����" NOR,
    HIR "�������" NOR,
    HIR "�������" NOR,
    MAG "����似" NOR,
    MAG "�����뻯" NOR,
    CYN "��Ȼ��ͨ" NOR,
    CYN "�Ƿ��켫" NOR,
    HIC "������˫" NOR,
    HIC "һ����ʦ" NOR,
    HIC "������" NOR,
    HIW "��ɲ�" NOR
*/
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "��������" NOR,
        HIB "��ʶ����" NOR,
        HIB "�����ž�" NOR,
        YEL "��֪һ��" NOR,
        YEL "é���ٿ�" NOR,
        HIY "������" NOR,
        HIY "��������" NOR,
        HIM "��������" NOR,
        HIM "������ͨ" NOR,
        HIR "����ǳ��" NOR,
        HIR "����С��" NOR,
        MAG "�������" NOR,
        MAG "��Ȼ����" NOR,
        CYN "׿����Ⱥ" NOR,
        CYN "��������" NOR,
        HIC "��Ȼ��ͨ" NOR,
        HIC "����ͨ��" NOR,
        WHT "������˫" NOR,
        WHT "������" NOR,
        HIW "��ɲ�" NOR
/* xyj2000
        BLU "��ѧէ��" NOR,
        BLU "��������" NOR,
        BLU "��֪����" NOR,
        HIB "ƽ������" NOR,
        HIB "˾�ռ���" NOR,
        HIB "�����ž�" NOR,
        YEL "��֪һ��" NOR,
        YEL "é���ٿ�" NOR,
        YEL "��ʶ֮��" NOR,
        HIY "��������" NOR,
        HIY "������" NOR,
        HIY "�ᳵ��·" NOR,
        HIM "��������" NOR,
        HIM "������ͨ" NOR,
        HIM "����ǳ��" NOR,
        HIR "����С��" NOR,
        HIR "�������" NOR,
        HIR "��Ȼ����" NOR,
        MAG "����ʶ��" NOR,
        MAG "������ͨ" NOR,
        MAG "׿����Ⱥ" NOR,
        CYN "��������" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "����ͨ��" NOR,
        HIC "������" NOR,
        HIC "��Ⱥ����" NOR,
        HIC "������˫" NOR,
        WHT "��������" NOR,
        WHT "������" NOR,
        WHT "������ʥ" NOR,
        HIW "��ɲ�" NOR
*/
/* /cmds/usr/skills.c
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        YEL "������" NOR,
        YEL "����С��" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ����" NOR,
        CYN "��Ȼ��ͨ" NOR,
        HIC "������˫" NOR,
        HIC "������" NOR,
        HIW "��ɲ�" NOR
*/
});

string describe_exp(int value)
{
    int grade, two_year, n;
    
    two_year = value / 2000;
    for (grade = 0; grade < sizeof(exp_level_desc); grade++) {
        n = (grade+1) * (grade+1) * (grade+1);
        if (two_year < n) break;
    }
    if (grade >= sizeof(exp_level_desc))
        grade = sizeof(exp_level_desc) - 1;
    return exp_level_desc[grade];
}

int grade_exp(string desc)
{
    int grade, n;

    for (grade = 0; grade < sizeof(exp_level_desc); grade++) {
        n = grade;
        if (exp_level_desc[grade] == desc)
            return n;
    }
    return 0;
}

string describe_skills(mapping skills)
{
    int grade, lvl, i;
    string *sk;
    if (!sizeof(skills)) return BLU "һ�ϲ�ͨ" NOR;
    sk = keys(skills);
    for (i = 0; i < sizeof(sk); i++) {
        if (SKILL_D(sk[i])->type() == "knowledge") continue;
        if (lvl < skills[sk[i]]) lvl = skills[sk[i]];
    }
    grade = lvl / 10;
    if (grade >= sizeof(skill_level_desc))
        grade = sizeof(skill_level_desc) - 1;
    return skill_level_desc[grade];
}

varargs string describe_skill(string skill, int lvl)
{
    int grade;
    string *level_desc;
    
    if (SKILL_D(skill)->type() == "knowledge")
        level_desc = knowledge_level_desc;
    else
        level_desc = skill_level_desc;

    grade = lvl / 10;
    if (grade >= sizeof(level_desc))
        grade = sizeof(level_desc) - 1;
    return level_desc[grade];
}

string describe_force(int value)
{
    int year, sixty, left;
    string line;
    
    year = value / 100;
    sixty = year / 60;
    left = year % 60;

    if (year <= 0) {
        line = HIB "����һ��" NOR;
        return line;
    }
    
    if (sixty > 0)
        if (left != 0)
            line = HIW + chinese_number(sixty) + "����" + NOR + "��" +  HIR + chinese_number(left) + "��" + NOR;
        else
            line = HIW + chinese_number(sixty) + "����"  + NOR;
    else 
        line = HIR + chinese_number(year)+"��" + NOR;

    return line;
}

string describe_mana(int value)
{
    int grade, lvl, n;

    //in unit of 40, increase by n^2.
    lvl = value / 40;
    for (grade = 0; grade < sizeof(mana_level_desc); grade++) {
        n = (grade+1) * (grade+1);
        if (lvl < n) break;
    }
    if (grade >= sizeof(mana_level_desc))
        grade = sizeof(mana_level_desc) - 1;
    return mana_level_desc[grade];
}
 
int grade_mana(string desc)
{
    int grade;

    for (grade = 0; grade < sizeof(mana_level_desc); grade++) {
        if ((string)mana_level_desc[grade] == desc)
            return grade;
    }
    return 0;
}

string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    
    if (type == 0) level_desc = exp_level_desc;
    else if (type == 1) level_desc = skill_level_desc;
    else if (type == 2) level_desc = knowledge_level_desc;
    else level_desc = mana_level_desc;
    
    for (i = 0; i < sizeof(level_desc); i++) {
        line += level_desc[i] + "    ";
        if ((i%4) == 3) line += "\n";
    }
    
    return line;
}

