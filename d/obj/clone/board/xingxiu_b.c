// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ɵ������԰�",({"board"}));
	set("location", "/d/suburb/xkx/xingxiu/xxh2");
	set("board_id", "xingxiu_b");
	set("long", "���ǹ������������Եİ���.\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

