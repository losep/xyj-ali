// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "��¥����");
  set ("long", @LONG

��¥������������������סլ��δ�������Ѿ�����ɭɭ����¥��
����һ��������ң����顰������������������֡����Ա�����
����������������Ļ����Ÿ��š�
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"yongdao",
    "west" : __DIR__"yun1",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/yaocha" : 1,
  __DIR__"npc/yushi" : 1,
]));

  set("outdoors", 1);
  setup();
}


int valid_leave(object me, string dir)
{

        if( wizardp(me)) return 1;


        if (dir == "east" ) {
        if (objectp(present("yushi jiang", environment(me))))
        return notify_fail("��ʦ�����ֽ�����ס��˵�������������������˵�������\n");
        if (objectp(present("yaocha jiang", environment(me))))
        return notify_fail("ҩ�潫���ֽ�����ס��˵�������������������˵�������\n");
        }   
        return ::valid_leave(me, dir);
}

