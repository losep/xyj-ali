// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/palace2.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

                      ��������

���������������ʣ�����ǧ���������ơ��������ȣ�����
������͸�������Ĵأ�������ﰿ�衣��������Ԫ˧��ԱԱ��
�����������½�����ˣ�����ִ����ޡ����б�ɫ����̨����
һ�����������ҫĿ��������Ȼ������

LONG);

  set("exits", ([
        "north" : __DIR__"palace1",
        "south" : __DIR__"palace3",
        "west"  : __DIR__"pan1c",  
        "east"  : __DIR__"pan1d",  
      ]));

  set("objects", ([
         __DIR__"npc/tian2" : 1,
     ]));

  setup();
}

