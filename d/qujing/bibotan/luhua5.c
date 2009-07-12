// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "芦花荡");
  set ("long", @LONG

走如芦花荡便如走入一个迷宫，前后左右都是一人多高的芦
草，密密麻麻的让人辩不清方位，随风而舞的芦花沾了人满
身都是。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/luniang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luhua2",
  "east" : __DIR__"luhua8",
  "north" : __DIR__"luhua6",
  "south" : __DIR__"luhua4",
]));

  setup();
}

