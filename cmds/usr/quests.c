// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit F_CLEAN_UP;

#include <ansi.h>
#include <obstacle.h>

int telling (object me, object who);

string name;

int main(object me, string arg)
{
        object ob;

        if( !arg ) {
                ob = me;
                name = "��";
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
        
                if(!ob) ob = LOGIN_D->find_body(arg);

                if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

                name = ob->query("name");
        } else
           return 0;

        telling(me, ob);

        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��quests <ĳ��>

��ʾĳ�˽��յ����ϡ� 

�����help jiemi
TEXT
        );
        return 1;
}

int telling (object me, object who)
{
  mapping mapp;
  if (who->query("quest") == 0)
  {
    write (name+"û�н��κ��ԡ�\n");
    return 1;
  }

  write (name+"�Ѿ�����"+(who->query("quest/number"))+"���ԡ�\n");

  write ("    ʳ�"+"����"+(who->query("quest/food/times"))+"�Σ�"+
         "���"+(who->query("quest/food/reward"))+"��Ʒ�¡�\n");
  write ("    ���"+"����"+(who->query("quest/give/times"))+"�Σ�"+
         "���"+(who->query("quest/give/reward"))+"��Ʒ�¡�\n");
  write ("    ���ͣ�"+"����"+(who->query("quest/ask/times"))+"�Σ�"+
         "���"+(who->query("quest/ask/reward"))+"��Ʒ�¡�\n");
  write ("    ������"+"����"+(who->query("quest/kill/times"))+"�Σ�"+
         "���"+(who->query("quest/kill/reward"))+"��Ʒ�¡�\n");
  write ("    ������"+"����"+(who->query("quest/weapon/times"))+"�Σ�"+
         "���"+(who->query("quest/weapon/reward"))+"��Ʒ�¡�\n");
  write ("    ���ף�"+"����"+(who->query("quest/armor/times"))+"�Σ�"+
         "���"+(who->query("quest/armor/reward"))+"��Ʒ�¡�\n");
  write ("    ���"+"����"+(who->query("quest/cloth/times"))+"�Σ�"+
         "���"+(who->query("quest/cloth/reward"))+"��Ʒ�¡�\n");
  write ("    ���Σ�"+"����"+(who->query("quest/wearing/times"))+"�Σ�"+
         "���"+(who->query("quest/wearing/reward"))+"��Ʒ�¡�\n");
  write ("    ��ʲ��"+"����"+(who->query("quest/furniture/times"))+"�Σ�"+
         "���"+(who->query("quest/furniture/reward"))+"��Ʒ�¡�\n");
  write ("\n");

  write (name+"����ã�\n");
  write ("    Ǳ�ܣ�"+(who->query("quest/gain/potential"))+"�㡣\n");
  write ("    ���У�"+COMBAT_D->chinese_daoxing(who->query("quest/gain/combat_exp"))+"���С�\n");
  write ("    ���ܣ�\n");
  mapp = who->query("quest/gain/skills");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+SKILL_D(my_keys[i])->name()+(mapp[my_keys[i]])
              +"�㡣\n");
    }
  }
  write ("    ���ԣ���ʱ���ƣ���\n");
  mapp = who->query("quest/gain/apply");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+(my_keys[i])+(mapp[my_keys[i]])
              +"�㡣\n");
    }
  }
  write ("    ���ӣ�"+(who->query("quest/gain/silver"))+"����\n");
  write ("\n");

  write (name+"�ո���ɵ����ǣ�\n");
  if (who->query("quest/reason"))
  {
    write ("  ��"+who->query("quest/reason")+"������");
    if (who->query("quest/reward")) {
      if (wizardp(me)) 
        write ("  ������"+(who->query("quest/reward"))+"�㽱����\n");
      else  
        write ("  �����н�����\n");
    }  
    else
      write ("\n");
  }    
  write ("\n");

  write (name+"�������¼������ڽ���ԣ�\n");
  if (mapp = who->query("quest/pending/food"))
  {
    write ("  ʳ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/give"))
  {
    write ("  ���"+mapp["name"] + " " + mapp["objectname"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/ask"))
  {
    write ("  ���ͣ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/kill"))
  {
    write ("  ������"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/weapon"))
  {
    write ("  ������"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/armor"))
  {
    write ("  ���ף�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/cloth"))
  {
    write ("  ���"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/wearing"))
  {
    write ("  ���Σ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/furniture"))
  {
    write ("  ��ʲ��"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  write ("\n");

  if (!wizardp(me))
    return 1;
    
  write (name+"�����ݴ�ʹ��ͳ�ƣ�\n");
  if (mapp = who->query("quest/cache/food"))
  {
    write ("  ʳ�"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/give"))
  {
    write ("  ���"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/ask"))
  {
    write ("  ���ͣ�"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/kill"))
  {
    write ("  ������"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/weapon"))
  {
    write ("  ������"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/armor"))
  {
    write ("  ���ף�"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/cloth"))
  {
    write ("  ���"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/wearing"))
  {
    write ("  ���Σ�"+(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/furniture"))
  {
    write ("  ��ʲ��"+(sizeof(mapp))+"��\n");
  }
  write ("\n");
  return 1;
}


