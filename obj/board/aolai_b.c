// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
   set_name("�����ջ���԰�", ({ "board" }) );
   set("location", "/d/4world/cuixiang");
   set("board_id", "aolai_b");
   set("long",   "����һ���������Լ��µ����԰塣\n" );
   setup();
   set("capacity", 100);
   replace_program(BULLETIN_BOARD);
}
