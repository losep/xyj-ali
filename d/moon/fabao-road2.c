// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//fabao-road2.c
inherit ROOM;

void create ()
{
   set ("short", "��ʯ·");
   set ("long", @LONG

бб��һ��ɽ�����������ȥ��һ·�ϻ�ѩԽ��Խ���������ι�
״�Ĳ�����ʯȴԽ��Խ�ࡣ���л���һЩ����ɫ�ʰ�쵣���֪��
�Ӻζ�����ǰ����һƬ�����أ�����ԼԼ������Ѥ����˸������
��һ����������ɵüӿ��˽Ų���
LONG);

   set("exits", 
   ([ //sizeof() == 4
     //"out" : __DIR__"guangchang",
     "east" : __DIR__"fabao-road1",
     "west" : __DIR__"fabao-room",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/qingfeng" : 1,
     //__DIR__"npc/mingyue" : 1,
   ]));

   //set("valid_startroom", 1);
   set("outdoors", "moon");

   setup();
}

