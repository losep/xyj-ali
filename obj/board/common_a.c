// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// common_b.c

inherit BULLETIN_BOARD;

void create()
{
   set_name("һ����;���԰�", ({ "board" }) );
   set("location", "/d/ourhome/kedian");
   set("board_id", "common_a");
   set("long",   "����һ���������Լ��µ����԰塣\n" );
   setup();
   set("capacity", 80);
   replace_program(BULLETIN_BOARD);
}
