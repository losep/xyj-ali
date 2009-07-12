// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat 10/15/1997
// room: /d/qujing/baoxiang/qiao2.c

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
        "north"      : __DIR__"qiao1",
        "southeast"  : __DIR__"xi1",
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
    if (! find_object(__DIR__"qiao1"))
    {
      object room = load_object(__DIR__"qiao1");
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
                        "southeast"  : __DIR__"xi1",
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
                        "southeast"  : __DIR__"xi1",
                        "north"      : __DIR__"qiao1",
                      ]));

  room->set("item_desc",([
               "qiao" : "\n��ֻ������һ������ͨ��԰���\n\n",
            ]));

  remove_call_out ("open_bridge");
  call_out ("open_bridge",20,1);
}
