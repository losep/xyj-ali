// ALi by NewX

inherit ROOM;

void create()
{
   set("short", "����");
   set("long", @LONG

һƬ������������֣���������һλ�¶������ˡ��˿�������ľ�ȣ�
����һ���ʯͷ�ϣ����ڲ�ΡΡ�ط�����һ����������Щ�ر�Ĳ�
��(book)��
LONG
   );

   set("no_fight", "1");
   set("no_magic", "1");
   set("no_sleep_room", "1");

   set("item_desc", ([
     "book" : "�Ⲿ�ӱ�ͿĨ�����߰��㣬��ǿ�ܱ��ϳ������ϵļ����֣�����Ե����\n"
     ]));

   set("exits", ([
     "out" : __DIR__"yltw",
   ]));

   set("objects", ([
     __DIR__"npc/yuelao": 1,
   ]));

   setup();
}
