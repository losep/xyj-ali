// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//binggu.c

inherit ROOM;

void create ()
{
   set ("short", "����");
   set ("long", @LONG

��ǰ���龰���㾪���ˡ�û�뵽������������ı���ѩ���л���
��ôһ��ط����������������ı��°�����Χ����һ����Բ��ʮ
���ɽ�ȡ����������д�С������ʮ�����������һ�������
�Ժ�����ͣ��ڱ�ѩӳ�����������⡣�����������¶������޵�
�����ޱȣ������ܱ��¾ݸ�ѹ��֮�������Ե÷������ѣ����Ʒ�
����
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     //"south" : __DIR__"***",
     "north" : __DIR__"wuchang-s",
     "west" : __DIR__"wroad1",
     "east" : __DIR__"eroad1",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/zhangmen" : 1,
   ]));


   set("outdoors", "xueshan");

   setup();
}



