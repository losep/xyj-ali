// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/death/block.c
inherit ROOM;


void create ()
{
  set ("short", "������"); 
  set ("long", @LONG
����һ��ר�Źرձ��д����̻��������ߵķ��䡣����
ǽ�ڽ��ɸ������ɣ�ֻ���ϱ߲���һ����ڴ��С���ڡ�
LONG);

  set("valid_startroom",1);

  setup();
}

void init()
{
   if(!wizardp(this_player()))   {
      this_player()->set("startroom", "/d/death/block");
      add_action("block_cmd", "", 1);
   }   
}

int block_cmd(string args)
{
   string verb;
   string chat_msg;
   
   //chat_msg = "huogai " + this_player()->query("id");

   verb = query_verb();
   if(verb == "quit" || verb == "look") return 0;
   //if(verb == "chat*" && args == chat_msg) return 0;
   
   return 1;
}


