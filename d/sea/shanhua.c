// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /u/rainy/sea/shanhua.c
inherit ROOM;

void create ()
{
  set ("short", "ɢ��̨");
  set ("long", @LONG

�����������е�һ��¶̨��һ����ɴ��ס�˺��湬���ڵ���ⱦ��������
¶̨�ʳ��Σ���Χ�����ƺ���ʲô������ȴһʱ������Щ�ŵ�����������
˵������������ʹ�˺���������ȥڸ�������붨��

LONG);
  set("dragonforce_practice",1);
  set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"jingxing",
]));
  setup();
}
