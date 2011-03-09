// ALi by NewX
 
// Room: /d/city/qilin2.c

inherit ROOM;

void create()
{
    set("short", "������¥");
    set("long", @LONG

��¥����һ¥����ֻ�и��Ӻ������ɡ�ǽ(wall)�ϻ��ż����ڻ�����
��ɳ������һ������������ȡ�أ�һ���ǳ�ҧ�����彫��һ����
ξ�ٹ����޶��ã�һ�����޳�ǹɨȺ�ۡ��˵������ư��磬��ϧ��Χ
�������ȣ��Ҳ����ݣ�ֻ�ܸ������������л���
LONG
    );
    set("item_desc", ([
        "wall" : @WALL

ǽ�ϵıڻ���Ȼ���ư��磬������ȴ���⵽�ǲ����۵ĵط���һ��С
�֣�

��������С�ӣ����񲻴�����Ȼ�ܿ�����Щ�֣�
���������Ϻ��ҿ�������¥��˳�ۣ���Ҫ���ܰ�������¥���ˣ�
�����Ϻ�������һ�ݻ�Ե��
����������ס�ˣ�����¥�Ժ��������ӻ�����������������
���������ҵ�һ���������ȥ��Ȼ�����֪���ˡ�
���������ٺ٣�
��������������������������������������������ξ�ٹ�����

����ϸ�����ң���Ȼ�ڲ����۵Ľ�������һ��Բ�εĶ�(hole)��
WALL,
    ]));
    set("light_up", 1);
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
        "down" : __DIR__"qilin",
    ]));

    setup();
}

void init()
{
    add_action("do_insert", "insert");
}

int do_insert(string arg)
{
    object me=this_player(), here=this_object(), ob, book;

    if (!arg || arg != "zhu zi into hole")
        return notify_fail("��Ҫ��ʲô����ʲô����(insert ** into **)��\n");
    if (!(ob = present("zhu zi", me)))
        return notify_fail("������û����������(zhu zi)��");
    if ((string)ob->query("name_recognized")!="����¥����")
        return notify_fail("��������ӵĳߴ粻�ԣ�������ȥ��");
    if (me->query_temp("weapon") == ob)
        return notify_fail("�㲻�ܰѵ�ǰ���������붴���档\n");

    message_vision("$N��һ�����Ӳ��뵽һ��Բ�εĶ������һš��\n", me);
    message_vision("����¥ͻȻ��ʼ���ҵĻζ�����վ�����ȣ�žߴһ��ˤ�˸�ƨ�ɶס�\n", me);
    message_vision("��������Ϊ¥Ҫ���˵�ʱ�򣬻ζ�ͻȻֹͣ�ˡ�\n", me);
    if (!here->query("book_drop")) {
        message_vision("��Ȼ��ž�һ����һ����Ӳ�֪��ʲô�ط����˳����������˵ذ��ϡ�\n", me);
        ob->move(here);
        destruct(ob);
        book=new("/d/obj/book/parrybook2");
        book->move(here);
        here->add("book_drop", 1);
    }
    else {
        tell_object(me, "����˰��죬ʲôҲû�������ѵ�����ξ�ٹ��Ķ����磿\n");
    }
    return 1;
}