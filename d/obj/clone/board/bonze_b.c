// /clone/board/bonze_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ֵ������԰�", ({ "board" }) );
	set("location", "/d/suburb/xkx/shaolin/dxbdian");
	set("board_id", "bonze_b");
	set("long", "����һ�������ֵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
