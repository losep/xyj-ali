// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Wuliao's Board


inherit BULLETIN_BOARD;

void create()
{
        set_name("���İ�", ({ "board" }) );
  set("location", "/u/wuxin/workroom");
        set("board_id", "wuliao_board");
        set("long",     "����һ���İ壬����д�����������µ����ԡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
