// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//luobodi.c

inherit ROOM;

void create ()
{
   set ("short", "�ܲ���");
   set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ����������ܲ��ء�
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "north" : __DIR__"huludi",
     "southeast" : __DIR__"huangguadi",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/food/carrot" : 3,
   ]));

   //create_door("south", "�滨��", "north", DOOR_CLOSED);
   set("outdoors", "wuzhuang");

   setup();
}
