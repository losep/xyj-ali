// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998


inherit ROOM;

void create ()
{
    set ("short", "��ٵ�");
    set ("long", @LONG

һ��������ֱ�Ĵ�ٵ���ƽԭ���ɶ�����ԶԶ�����ӿ�������
��ƽ�����ݵ���ʮ���ۡ���ٵ�������ͨ��Զ��������ԶԶ
�ɿ�������Ǹ���

LONG);

    set("exits", ([
            "west" : __DIR__"east4",
            "east" : "/d/kaifeng/chengmen",
        ]));
    set("outdoors", __DIR__);
    
    setup();
}


