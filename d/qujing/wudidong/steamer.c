// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// steamer.c by mes
// updated 9-18-97 pickle

#include <ansi.h>

inherit ROOM;

int do_tao();
void reset();

void create()
{
  set ("short", "����");
  set ("long", @LONG

�ô��һ����������֪Ϊ�������������������(tao)�ɣ�
LONG);
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 0);
  set("valid_startroom", 1);
  setup();

}
void init()
{
  add_action("do_tao", "tao");
}
int do_tao()
{   
  object me, user, bao;
  string fainter;
  int kee,  mkee;
  
  me=this_player();
  kee=(int)me->query("kee");
  mkee=(int)me->query("max_kee");
  if (random(100)<80) 
  {     
      if (kee<=mkee/5) {
   me->set_temp("death_msg","�������ˡ�\n");
   bao = new(__DIR__"obj/renroubao.c");
   bao->set("long", "һ�������硢�����ڵ�������ӣ���˵������"
      + me->query("name") + "�������ģ����滹մ��һЩѪ˿��\n"
      + "������ζ��֮���������ɵ����˴������Ρ�\n");
   fainter = me->query("wudidong/last_sold_by");
   if (!fainter) bao->move("/d/city/kezhan.c");
   else {
     user = find_player(fainter);
     if (user)
     {
       bao->move(user);
       tell_object(user, "���������������ˡ�\n");
     }
     else bao->move("/d/city/kezhan.c");
   }
   //by mon 8/25/97
   me->die();
   return 1;
      }
      else
      {
     message_vision(RED "һ���һ𣬰�$N�����˻�����\n" NOR, me);
     me->receive_damage("kee", mkee/5);
     me->receive_wound("kee", mkee/5-10);
     me->set("max_force", me->query("max_force")-5);
     return notify_fail("");;
   }   
    }
  else
    {
      message_vision(HIG "$Nһҧ������������һ�����˳�ȥ��\n" NOR, me);
      me->move(__DIR__"kitchen");
      message_vision(CYN "$NͻȻ��¯�ϵ����������˳�����ģ��ʮ���Ǳ���\n" NOR, me);
      me->save();
      return 1;
    }
}
