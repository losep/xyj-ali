// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/qilin2.c

inherit ROOM;

void create()
{
   set("short", "������¥");
   set("long", @LONG

��¥����һ¥����ֻ�и��Ӻ������ɡ�ǽ(wall)�ϻ��ż����ڻ�����
��ɳ������һ������������ȡ�أ�һ���ǳ�ҧ�����彫��һ����
ξ�ٹ����޶��ã�һ�����޳�ǹɨȺ�ۡ�ϯ��һλ�����������ں�һ
λ�������߿���������

LONG
   );
   set("light_up", 1);
   set("no_clean_up", 0);
   set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuchigong" : 1,
  __DIR__"npc/xumaogong" : 1,
]));
   set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"qilin",
]));

   setup();
   replace_program(ROOM);
}
