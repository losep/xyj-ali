// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by mes, updated 6-17-97 pickle

inherit ROOM;
void create ()
{
  set ("short", "��Ѩ");
  set ("long", @LONG

����ʯ��һ�ƣ��ԹԲ����ˡ�����ԭ�����������ĳ�Ѩ����Ȼ����û
��ˮ������ʪ�ޱȡ��Ĵ����Ÿ��ָ������δ�����ĳ��ӣ�������һ
�Ѻ��Ƿ�ɢ�����󸯳�֮����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"well",
]));
  set("outdoors", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{
  if(dir=="west" &&
     objectp(present("dragon", environment(me))))
    return notify_fail("������ס�����ȥ·��\n");
  return ::valid_leave(me, dir);
}

int clean_up()
{
  return 0;
}


   
