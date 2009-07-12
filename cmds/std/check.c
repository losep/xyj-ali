// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// check somebody's position

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
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
});

string *exp_level_desc = ({
   BLU "�����;" NOR,   HIB "�������" NOR,
   HIB "��ͨ����" NOR,   HIB "����Ѿ�" NOR,
   HIB "�����ȹ�" NOR,   CYN "һ��ǧ��" NOR,
   CYN "��̥����" NOR,   CYN "ϼ�ٷ���" NOR,
   CYN "��������" NOR,   HIC "�����ֻ�" NOR,
   HIC "��֤���" NOR,   HIW "���˺�һ" NOR
});

string *mana_level_desc = ({
         BLU "���߷���" NOR,   HIB "�����仯" NOR,
   HIB "���Ƽ���" NOR,   HIB "Ԥ֪����" NOR,
          HIB "�������" NOR,   CYN "���绽��" NOR,
          CYN "������ɽ" NOR,    CYN "���ǻ���" NOR,
   HIC "��������" NOR,      HIC "�任Ī��" NOR,
          HIW "�����ޱ�" NOR
});

string skill_level(int,int);

int main(object me,string arg)
{
   object ob;
   int mana_cost;
   int sen_cost;
   int skill_lvl,mana_lvl,exp_lvl;
   string lvl;
   mapping skl;
   int *levels,i;
   string msg;

   if(!arg) 
     return notify_fail("�������˭��״̬��\n");
   if((int)me->query("combat_exp")<5000)
     return notify_fail("��ĵ��в������ò��˵ض��顣\n");
   if((int)me->query("mana")<60) 
     return notify_fail("��ķ����������ò��˵ض��顣\n");
   if((int)me->query("sen")<=50)
     return notify_fail("������̫���ˣ���Ϣ��Ϣ�ɣ�\n");
   mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
   mana_cost=mana_cost+10;
   if(mana_cost > -50) mana_cost=-50;
   me->add("mana", mana_cost);
   sen_cost=50;
   message_vision(HIY "$N�������˼������ģ�����ͻȻ����һ�������һ����˳������ڣ���\nֻ���ٺټ�����Ц����֪�����������һ����ͷ����ļһ��$N���ߵ���˵�˼��仰��\n" NOR, me);
   ob = find_player(arg);
   if( !ob ) ob = find_living(arg);
   if(!ob || ob->query("env/invisibility"))
     return notify_fail("˳��������㣺��֣��Ҳ�������ˣ�����\n");
   skl=ob->query_skills();
   if(!sizeof(skl)) {
     write("˳��������㣺 " + ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
   }
   else {
     levels=values(skl);
     skill_lvl=0;
     for(i=0;i<sizeof(skl);i++) {
        if(skill_lvl<levels[i]) skill_lvl=levels[i];
     }
     lvl=skill_level(1,skill_lvl);
     write("˳��������㣺 " + ob->name() + "Ŀǰ�书�Ѵ�" + lvl + "�ľ��硣\n");
   }
   exp_lvl=ob->query("combat_exp");
   lvl=skill_level(2,exp_lvl);
   write("˳��������㣺 " + ob->name() + "Ŀǰ�����Ѵ�" + lvl + "�ľ��硣\n");
   mana_lvl=ob->query("max_mana");
   lvl=skill_level(3,mana_lvl);
   write("˳��������㣺 " + ob->name() + "Ŀǰ�����Ѵ�" + lvl + "�ľ��硣\n");

        message_vision("$N��ȻĪ������ض�����һ�¡�\n",ob); 
   msg="�㼱æ��ָһ�㣬";
        if(ob->query("combat_exp")>me->query("combat_exp")/5)
     msg+="ԭ����"+me->name()+"("+me->query("id")+")"+
          "���ڴ�����ĵ��С�\n";
        else
     msg+="����ȴֻ��һƬãȻ��\n";
        tell_object(ob, msg);

   return 1;
}

string skill_level(int type,int level)
{
   int grade,lvl,n;

   switch(type) {
   case 1:
     grade=level/10;
     if(grade>=sizeof(skill_level_desc)) grade=sizeof(skill_level_desc)-1;
     return skill_level_desc[grade];
   case 2:
   //in unit of 1000, increase by n^3, to get final one need 1331k.
     lvl=level/1000;
     for(grade=0;grade<sizeof(exp_level_desc);grade++) {
        n=(grade+1)*(grade+1)*(grade+1);
        if(lvl<n) break;
     }
     if(grade>=sizeof(exp_level_desc)) grade=sizeof(exp_level_desc)-1;
     return exp_level_desc[grade];
   case 3:
   //in unit of 20, increase by n^2, to get final one need 2000.
     lvl=level/20;
     for(grade=0;grade<sizeof(mana_level_desc);grade++) {
        n=(grade+1)*(grade+1);
        if(lvl<n) break;
     }
     if(grade>=sizeof(mana_level_desc)) grade=sizeof(mana_level_desc)-1;
     return mana_level_desc[grade];
   }
   return "";
}

int help(object me)
{
   write(@HELP
ָ���ʽ : check|cha [<ĳ��>]

�ض���: �����������ڵĵ���,�������书����

�书����
   ��ѧէ��   �����ž�   ��ͨƤë
   ��֪һ��   ��������   ������
   ����С��   ����Ѿ�   �������
   ��Ȼ����   �������   �������
   ����似   �����뻯   ��Ȼ��ͨ
   �Ƿ��켫   ������˫   һ����ʦ
   ������   ��ɲ�

���м���
   �����;   �������   ��ͨ����
   ����Ѿ�   �����ȹ�   һ��ǧ��
   ��̥����   ϼ�ٷ���   ��������
   �����ֻ�   ��֤���   ���˺�һ
   
��������
   ���߷���   �����仯   ���Ƽ���
   Ԥ֪����   �������   ���绽��
   ������ɽ    ���ǻ���   ��������
   �任Ī��   �����ޱ�
HELP
    );
    return 1;
}

