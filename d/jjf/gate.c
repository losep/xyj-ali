// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/gate.c

inherit ROOM;

void create()
{
   set("short", "������");
   set("long", @LONG

���ﾹȻ�ǿ��������屦�Ĺ�ۡ����˵�������ʱ���������ȣ�
��������ۡ��Ų�Ƶ�һ����֪�����ɾ���û�뵽��Ȼ���������
���ظ����µ������ƺ�û���յ��κ�Ӱ�죬����Ľ�������ݷ�֮��
���˺ܶࡣ������������һ�����ܹ����һ�����е����꣬Ҳδ��
����һ�����¡������Ժ�Ӻܴ��ſ���һ��ʯʨ�ӣ�������һ��
�����������дУ��ڸ��˴���Ժ�ӣ�����Ժ�������������ģ���
���Ǹ��ճ���������ظ��ҽ�����֮�ء�
LONG
   );
   set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"front_yard.c",
  "northeast" : __DIR__"center",
]));
   set("out_doors", 1);
   set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinan" : 1,
]));
   set("no_clean_up", 0);

   setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "south" ) {
   if (((string)me->query("family/family_name")=="������") 
   ||   wizardp(me)
   ||   me->query_temp("pending/jiangjun_answer")) {
     return ::valid_leave(me, dir);
           }
     if(objectp(present("qin an", environment(me)))) {
               return
notify_fail("�ذ��ȵ����������������Ҵ�֮�أ��кι��(answer)��\n");
         }
     return 1;
   }
       return 1;
   }

