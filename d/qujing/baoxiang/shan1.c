// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan1.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ�ϻ���������ʯ��㣬�β��س���һЩ���ֹ�ľ��·����
ʯ��Χ�Ƶ�������ɽ���У��ػ����ۡ��Ĵ��紵�ݶ����չȻ�����
���˻�Ȼ��֪������

LONG);

  set("exits", ([
        "southdown"  : __DIR__"yelu3",
        "northeast"  : __DIR__"luochi1",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

