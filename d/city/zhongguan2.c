// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;
string *student_msg = ({
                "���ŵ���Ϧ������",
                "���������壬С��������",
                "����˼���ɣ������Ͷ�����ʡҲ",
                "����ګ���Զ�������",
                "����̹������С�˳�����",
                "����̩��������С�˽�����̩",
});


void create ()
{
        set ("short", "�ܹܸ�����");
        set ("long", @LONG

�ฮ�Ĵ�����������˵���Ǻܺ�����ȴҲ����һ�����ơ�������һ��
�ľ���Σ������Ǽ��ź�ľ�����Σ��ܹ�ƽʱ������Ӽ�һЩ����
(qiuxue)�����߻���ͨ����լ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "north" : __DIR__"zhongguan",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/kaishan" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_qiuxue", "qiuxue"); 
}
int do_qiuxue()
{       object ob, pai_ob;
        string object_file; 
        string obj_file;
        int i;
        object me;
        me=this_player();
        if(!(ob = present("yin kaishan", environment(me))))
                return notify_fail("�ܹܽ��ղ��ڣ����������ɣ�\n");
        if( !(int)me->query_skill("literate") >= 45 )
return notify_fail("��ɽЦ�������µ�ˮƽ�»��������Ϲ��Ӽ�ɣ�\n");
        if(!me->query("guozi/paid"))
        return notify_fail("��ɽЦ�������ǹ��Ӽ࣬��������Ǯ����Ҫ���ģ�\n");

write("��ɽ�Ӽ�������һ��С�ƣ�Ц������������ϧ���ᣬ���ն������ͷ�أ�\n
��ɽ�����ӵݸ�" + this_player()->name() + "��\n");
        me->set("guozi/paid", 0);
        pai_ob = new("/obj/pai");
                obj_file = sprintf("%O", ob);
        for(i=0; i <sizeof(obj_file); i++)  {
    }   
        obj_file = obj_file[0..i-1];

        pai_ob->set("player", this_player()->id());
pai_ob->set_temp("long_1", "���Ӽ����" + this_player()->name() + "\n" + "���滹���ţ�" +
student_msg[random(sizeof(student_msg))] + "\n");
        
        this_player()->start_busy(1);
        pai_ob->move(this_player());
        
        return 1;
}


