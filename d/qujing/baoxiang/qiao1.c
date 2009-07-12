// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/qiao1.c

inherit ROOM;

void create ()
{
  set ("short", "��ͷ��");
  set ("long", @LONG

һ���Ӷ������������ǰ��������Ţ��������Ƭ���߽�ȥ���ǻ�
�������������޹飬���ĸ��Ǽ���������

��������һ���ô���ɵļ��׸���(qiao)��

LONG);

  set("exits", ([
        "northeast"      : __DIR__"shanwan3",
        "south"      : __DIR__"qiao2",
      ]));
  set("item_desc",([
      "qiao" : "\n��ֻ������һ������ͨ��԰���\n\n",
     ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void open_bridge(int tell);
void close_bridge(int tell);

void initialize (int bool)
{
  if (this_object()->query("initialized") == 0)
  {
    this_object()->set("initialized",1);
    if (bool)
    {
      close_bridge(0);
      remove_call_out ("open_bridge");
      call_out ("open_bridge",20,1);
    }
    else
    {
      open_bridge(0);
      remove_call_out ("close_bridge");
      call_out ("close_bridge",20,1);
    }
    if (! find_object(__DIR__"qiao2"))
    {
      object room = load_object(__DIR__"qiao2");
      room->initialize(bool);
    }
  }
}

void init ()
{
  initialize (random(2));
}

void open_bridge (int tell)
{
  object room = this_object();

  if (tell)
    tell_room (room,"�����ϵĸ�������ɢ����\n");

  room->set("long", @LONG

һ���Ӷ������������ǰ��������Ţ��������Ƭ���߽�ȥ���ǻ�
�������������޹飬���ĸ��Ǽ���������

�������ô���ɵļ��׸���(qiao)�ѱ��𿪡�

LONG);

  room->set("exits", ([
                        "northeast"      : __DIR__"shanwan3",
                      ]));

  room->set("item_desc",([
               "qiao" : "\n��ֻ�����ں��ϡ�\n\n",
            ]));

  remove_call_out ("close_bridge");
  call_out ("close_bridge",20,1);
}

void close_bridge (int tell)
{
  object room = this_object();

  if (tell)
    tell_room (room,"�����ϵĴ���������һ��\n");

  room->set("long", @LONG

һ���Ӷ������������ǰ��������Ţ��������Ƭ���߽�ȥ���ǻ�
�������������޹飬���ĸ��Ǽ���������

��������һ���ô���ɵļ��׸���(qiao)��

LONG);

  set("item_desc",([
      "qiao" : "\n��ֻ������һ������ͨ��԰���\n\n",
     ]));

  room->set("exits", ([
                        "northeast"      : __DIR__"shanwan3",
                        "south"      : __DIR__"qiao2",
                      ]));

  room->set("item_desc",([
               "qiao" : "\n��ֻ������һ������ͨ��԰���\n\n",
            ]));

  remove_call_out ("open_bridge");
  call_out ("open_bridge",20,1);
}
