
//eroad2.c

inherit ROOM;

void create ()
{
   set ("short", "Сľ����");
   set ("long", @LONG

����������Щľͷ�Ǵ��������ġ����������ȷ��һ��Сľ�ݡ�
��Χ��һ�����Ƶ�Χǽ��Ҳ�����������ߡ�
LONG);

   set("exits", ([ //sizeof() == 3
     "south" : __DIR__"xiaomuwu",
     "west" : __DIR__"eroad1",
     "east" : __DIR__"eroad3",
   ]));

   set("objects", ([ //sizeof() == 1
     __DIR__"npc/shier" : 2,
   ]));

   set("outdoors", "xueshan");

   setup();
}

int valid_leave(object me, string dir)
{
    object shier;
    if (dir == "south") {
        if (objectp(shier = present("shi er", environment(me))) && living(shier)) {
            if (me->query("family/family_name") == "��ѩɽ" && (int)me->query("family/generation") <= 3)
                message_vision("$N��ü˳Ŀ��$n����\n", shier, this_player());
            else 
                return notify_fail("�̶�����һ��������������κ��˲������ڴ����\n");
        }
    }

    return ::valid_leave(me, dir);
}

