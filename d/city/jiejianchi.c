// ALi by NewX
//changan city

inherit ROOM;

void create ()
{
    set ("short", "�⽣��");
    set ("long", @LONG

���������ǿ���Ԫѫ����ĸ�ۡ����������������Ҳ�ͻķ��ˡ�
��˵֮���һ��ʱ������ﾭ���ֹ�Ԭ����ڴ˵�̽��һ����
��Ϊ�˵�ɱ�����أ����������ڴ˾�סʱ���п���ѹɱ�����������
���٣�ɱ��ʧȥѹ�ƣ����ǲ����˸������⡣Ϊ�ˣ�Ԭ��������ڴ�
�޽���һ���⽣�أ����Ի���ɱ����
LONG);
    //set("item_desc", ([" *** " : " *** ", ]));

    set("exits", 
    ([ //sizeof() == 1
            "north" : __DIR__"qinglong-e2",
    ]));

    set("outdoors", "changan");
    setup();
}

void init()
{
    add_action("do_bath", "bath");
}

int do_bath(string arg)
{
    object me;
    me = this_player();
    message_vision("$N����ʵ��Ĺ��ڵ��ϣ�����һ�ѳ�ˮ��������ͷ�ϡ�\n", me);
    me->start_busy(3+random(4));
    call_out("bath_finish", 3, me);
    return 1;
}

void bath_finish(object me)
{
    if (me->query("bellicosity") < 50) {
        message_vision("$N����ɢ����һ�����֮������Χ�����̲�ספ��ۿ���\n", me);
    }
    else if (random(me->query_kar() + 40) > 40) {
        message_vision("��Χ���˶��о���$N����Ũ�ص�ɱ���䵭��һЩ��\n", me);
        me->add("bellicosity", -50);
    }
    else {
        message_vision("��ˮ����$N���Ͼ�ð��һ������̣�$NҲ�������������ҽУ���æվ����������\n", me);
    }
}