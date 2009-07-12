// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat 

inherit NPC;

#include <quest_ak.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("�¹���", ({"chen guangrui", "chen", "guangrui"}));
  set("long", "�¹���������֮�������������������״Ԫ��\n");
  set("title", "�������");
  set("gender", "����");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "scholar");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("literate", 180);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "�����ʦ˵�������������ġ�\n",
    "�����ʦ��������������ˣ������Ӧ�ġ�\n",
    "�����ʦ˵�����������ͣ���ˮ½���ǰ֮����Ҳ��\n",
    "�����ʦ̾�Ե����������ͣ���������֮���Ҳ��\n",
    "�����ʦ˵�����˷�����Ҳ��\n",
    "�����ʦ˵����������棬������������ʿ��\n",
  }));
  set("inquiry", ([
        "here":   "��������̨Ҳ��ˮ½��Ὣ���ھ��У���״Ԫ�ڴ�Ԥ�������Լ������͡�\n",
        "name":   "����֮���¹���Ҳ���ڴ������������͡�\n",
        "ask":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "��ʿ":   (: test_player() :),
        "����":   (: test_player() :),
        "��":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$Nȼ��һ�������һ������$n˵�����������죬������ȥ�ݼ�$w��ѯ���й�$oһ�¡�\n",
    "$N���������ȼ��$n˵�����Ϸ�ռ������ڣ���֪��$w֪��$o֮�£����ɷ�ȥ�����\n",
    "$N����������һ�ݣ�ת���$n˵�����ɷ�ȥ�ݼ�$w������֪$oһ�£�\n",
    "$N�����ȼ����$n˵����������������ȥ��$oһ�°ݷ�$w���뾡�綯��Ҳ��\n",
    "$N��$n˵�����Ϸ�������ڣ���ȱ��ȥ�ݷ�$w��ȥ��֪$o֮�¡�\n",
    "$Nȼ����ϣ���ͷ��$n˵������֪�ɷ�ȥ�ݼ�$w����̽��$oһ�¡�\n",
    "$N������л���������һ�ݣ��ٶ�$n˵����������������ȥѰ��$w����֪$o֮�¡�\n",
  });  
  string *acks = ({
    "֪���ˡ�\n",
    "����ͻᶯ�������Ȼذɡ�\n",
    "�õġ�\n",
    "��л���ã������ȥ�졣\n",
    "�ã������Ͼ�ȥ׼����\n",
  });
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  string str;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�����������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/ask"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�������ȥ��"+who->query("quest/pending/ask/name")+
                    "ѯ��"+who->query("quest/pending/ask/topic")+"һ����\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_ask);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/ask");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣��Ϸ��������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_ask[quest_keys[i]];
  who->set("quest/pending/ask/index", i);
  who->set("quest/pending/ask/daoxing", quest_keys[i]);
  who->set("quest/pending/ask/name", quest[IDX_NAME]);
  who->set("quest/pending/ask/id", quest[IDX_ID]);
  who->set("quest/pending/ask/topic", quest[IDX_OBJ]);
  who->set("quest/pending/ask/acknowledge", acks[random(sizeof(acks))]);
  who->set("quest/pending/ask/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
  str = replace_string (str, "$o", quest[IDX_OBJ]);
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������ƻ��ƣ����ٸ������������ͣ�\n",me,who);
    return;
  }

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ���˵����ȥ�ݼ�"+who->query("quest/pending/ask/name")+
                    "����֮"+who->query("quest/pending/ask/topic")+"һ����\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/ask/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$n��̾�������Ѿ������ˣ�������ô��ɡ�\n",me,who);
    message_vision ("$N����һ����˵�������㻹��"+chinese_number((t-uptime())/60+1)+
                    "���Ӳ�ȼ������ʱ�������ɡ�\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: �ó¹���ֱ���Ͽɡ�\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "������ͣ���"+who->query("quest/pending/ask/topic")+
           "һ�°ݼ���"+who->query("quest/pending/ask/name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����Ʒ�пɼ�Ҳ��\n",me,who);
  reward = quest_reward(who, quests_ask, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  who->add("quest/ask/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/ask");
  call_out ("quest_done",1,who);
}


