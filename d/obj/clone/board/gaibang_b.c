// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ؤ��������԰�", ({ "board" }) );
	set("location", "/d/suburb/xkx/city/pomiao");
	set("board_id", "gaibang_b");
	set("long", "����һ����ؤ����ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

