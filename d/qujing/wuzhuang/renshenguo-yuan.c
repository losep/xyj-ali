// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
   set ("short", "�˲ι�԰");
   set ("long", @LONG

�ô��һ���˲ι�԰���޴�Ĺ����ϵ���һöö���˴������ε�
�˲ι���ֻ�ǲ�֪����������Ū����������˵���˲ι������ޱȣ�
Ҫ����ժһ��ʲô���Բ��ϡ�
LONG);

   set("exits", 
   ([ //sizeof() == 4
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
   ]));

   set("outdoors", "wuzhuang");

   setup();
}

void init()
{
   object me, zhenyuan;

   me = this_player();

   if( me->query_temp("used_huangtong_key") == 1 )
   {
     me->delete_temp("used_huangtong_key");
     
     message_vision("ֻ������������Ц����Ԫ�������˳�����\n", me);
     message_vision("��Ԫ����˵������Ȼ���㷢���ˡ������ǾͿ����˲ι����ɣ�\n\n\n", me);

     if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
     {//if zhenyuan already here, we do not need creat another one.
        zhenyuan = new(__DIR__"npc/zhenyuan");
        zhenyuan->move(environment(me));
     }
     zhenyuan->start_renshen();
   }
}

