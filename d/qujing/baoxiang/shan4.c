// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan4.c

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
        "northdown"  : __DIR__"shanwan2",
        "northeast"  : __DIR__"shan3",
        "southeast"  : __DIR__"shan6",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

