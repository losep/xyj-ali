// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/nogate.c

inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

���ﱾ�ǵ��������屦�Ĺ�ۡ�������Դ��������Ժ�����㱻��
���ˣ�����Ѿ������������ˡ�
LONG
   );
    set("exits", ([ /* sizeof() == 1 */
        "north" : "/d/city/qinglong-e2",
    ]));
   set("out_doors", 1);
   set("no_clean_up", 0);

   setup();
}
