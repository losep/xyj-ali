// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/zoulang
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ͨ������ɽ��Ժ�����������ȡ�����ɽ��Ժ���д�����
���������˵����ǲ�������ʱʹ�ã���������һ��˵���ǲ���
�������Ժ�ġ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chanfang",
  "west" : __DIR__"shuyuan",
  "east" : __DIR__"guangchang.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/honghaier" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{
object ob=present("honghaier", environment(me));
if (me->query("family/family_name") != "�Ϻ�����ɽ" && dir == "west")
if( objectp(ob) && living(ob))
return notify_fail("\n�캢��Ц�����ض���˵��������˭ѽ������ô����ʶ��ѽ��\n"
+ "�캢��������ס�㣺����������Ժ���߸�ʲôѽ��\n");

return ::valid_leave(me, dir);

}
