// swordsman_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name( GRN "����Ħ����" NOR, ({ "stone" }) );
	set("location", "/d/suburb/fy/fy/fysquare");
	set("board_id", "fysquare_b");
	set("long",	"����һ��ʯ����ʯ���Ͽ���һ����ͷ��������
��������չ����ΰ׳�ۡ�\n" );
	setup();
	set("capacity", 49);
	replace_program(BULLETIN_BOARD);
}
