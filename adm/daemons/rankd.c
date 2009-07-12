// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
   if(strlen(ob->query("added_title"))<1) ob->set("added_title", "δ��");
   //need this default, otherwise looks too ugly sometimes.

   if( ob->is_ghost() ) return HIB "�� ��  �� ��" NOR;
   switch(ob->query("gender")) 
   {
   case "Ů��":
     switch(wizhood(ob)) {
        case "(admin)":   return GRN "�� ��  Ů ��" NOR;
        case "(arch)":     return GRN "�� ��  Ů ��" NOR;
        case "(wizard)":   return GRN "�� ��  Ů ��" NOR;
        case "(apprentice)":   return GRN "��������Ů��" NOR;
                           case "(immortal)":      return GRN "�� С��Ů ��" NOR;
                           case "(elder)":         return GRN "��������ҡ�" NOR;
        default:
          switch(ob->query("class")) 
          {
//------------------rank for girls--------------------
case "xian":
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� ��  Ů ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� С�ɹ� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� ��  Ů ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"���ӡ�" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"ʥĸ��" NOR;
   break;
case "yaomo":
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� С��Ů ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� ��  Ů ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� ��  �� ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"ħŮ��" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"������" NOR;
   break;
case "bonze":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� С��� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� Сʦ̫ ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� ʦ  ̫ ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"���᡿" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"������" NOR;
   break;
case "taoist":                
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� Ů��ͯ ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� С���� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� ��  Ů ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"��Ů��" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"ʥĸ��" NOR;
   break;
case "dragon":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� С���� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� ��  Ů ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� С��Ů ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"��Ů��" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"������" NOR;
   break;
case "scholar":
   if( (string)ob->query("added_title")=="δ��" )
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return GRN "�� Ůѧͯ ��" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return GRN "�� ��  Ů ��" NOR;
     else 
        return GRN "�� Ůѧʿ ��" NOR;
   }
   else
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return GRN "�� Ůѧͯ ��" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return GRN "��"+ob->query("added_title")+"��š�" NOR;
     else 
        return GRN "��"+ob->query("added_title")+"ѧʿ��" NOR;
   }
   break;
case "fighter":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "�� Ů  �� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "�� Ů�ν� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "�� Ů���� ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"�󽫾���" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"��Ԫ˧��" NOR;
   break;
case "youling":   
   if((int)ob->query("combat_exp")<1000) 
     return GRN "������С��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "���Ի�Ů��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "����ڤŮʹ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "��"+ob->query("added_title")+"�޳���" NOR;   
   else 
     return GRN "��"+ob->query("added_title")+"Ů����" NOR;
   break;   
case "dancer":
   return GRN "�� ��  �� ��" NOR;   
   break;
default:        
   return  MAG "�� ƽ  �� ��" NOR;
//------------------end rank for girls--------------------
          }
        }
//begin ���ԣ�
   default:
     switch(wizhood(ob)) 
     {
        case "(admin)":     return HIW "�� ��  ʦ ��" NOR;
        case "(arch)":        return HIW "�� ��  ʦ ��" NOR;
        case "(wizard)":     return HIW "�� ��  ʦ ��" NOR;
        case "(apprentice)":                return HIW "��������ʦ��" NOR;
                           case "(immortal)":               return HIW "�� С��ʦ ��" NOR;
        case "(elder)":                return HIW "��������ҡ�" NOR;
        default:
          switch(ob->query("class")) 
          {
//------------------rank for men--------------------
case "xian":                 
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� ��  ͯ ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
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
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� С  �� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "�� ��  �� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "�� ��  �� ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "�� "+ob->query("added_title")+"�� ��" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "��"+ob->query("added_title")+"��ħ��" NOR;
   else 
     return RED "��"+ob->query("added_title")+"ħ����" NOR;
   break;
case "bonze":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� С���� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "�� ��  �� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "�� ʥ  ɮ ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "��"+ob->query("added_title")+"���ߡ�" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "��"+ob->query("added_title")+"�޺���" NOR;
   else 
     return RED "��"+ob->query("added_title")+"������" NOR;
   break;
case "taoist":                 
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� С��ʿ ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "�� ��  ʿ ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "�� ��  �� ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "��"+ob->query("added_title")+"��ʦ��" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "��"+ob->query("added_title")+"���ˡ�" NOR;
   else 
     return RED "��"+ob->query("added_title")+"����" NOR;
   break;
case "dragon":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� Ϻ  �� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "�� з  �� ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "��Ѳ��ҹ�桿" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "��"+ob->query("added_title")+"ҹ�桿" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "��"+ob->query("added_title")+"����" NOR;
   else 
     return RED "��"+ob->query("added_title")+"������" NOR;
   break;
case "scholar":
   if( (string)ob->query("added_title")=="δ��" )
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return RED "�� ͯ  �� ��" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return RED "�� ��  �� ��" NOR;
     else 
        return RED "�� ��ѧʿ ��" NOR;
   }
   else
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return RED "�� ͯ  �� ��" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return RED "��"+ob->query("added_title")+"��š�" NOR;
     else 
        return RED "��"+ob->query("added_title")+"ѧʿ��" NOR;
   }
   break;
case "fighter":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "�� С  �� ��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "�� С  У ��" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "�� ��  �� ��" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "��"+ob->query("added_title")+"������" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "��"+ob->query("added_title")+"�󽫾���" NOR;
   else 
     return RED "��"+ob->query("added_title")+"��Ԫ˧��" NOR;
   break;
case "youling":   
   if((int)ob->query("combat_exp")<1000) 
     return RED "������С��" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "������ʹ�ߡ�" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "���ظ��й١�" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "��"+ob->query("added_title")+"�޳���" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
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
case "fighter":
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
   return "��ɽ��";
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


