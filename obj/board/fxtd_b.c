// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ѩ������԰�", ({ "board" }) );
        set("location", "/d/moon/fengxue/living.c");
        set("board_id", "fxtd_b");
        set("long",     "��ѩ������԰塣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

