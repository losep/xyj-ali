// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/shanlu2.c

inherit ROOM;

void create()
{
  set("short", "ɽ��");
  set("long", @LONG

�Ĵ��ڳ����ģ�ʲôҲ�����壬ֻ��������ǰ����������Ϊ��ʪ��ù
���˱ǡ����߱��϶��ǰ�͹��ƽ�ļ�ʯ������Ҳ��ʱ��ʱ�͡��ϱ���
һ��΢�������⣬��֪�ǲ��ǿ쵽�����ˡ�
LONG);
  set("exits", ([ /* sizeof() == 2 */
      "northeast" : __DIR__"shanlu1",
      "southup" : __DIR__"shanlu3.c",
      ]));
  set("no_clean_up", 0);
  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "southup")
    {
      message_vision("$N���ϱ��뿪��\n", me);
      me->move(__DIR__"shanlu3");
      message_vision("$N�ƿ�һ��Ұ�ݣ��ӵ������˳�����\n", me);
      return notify_fail("");
    }
  return ::valid_leave(me, dir);
}
