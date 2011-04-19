// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// go.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
   "north":     "��",
   "south":     "��",
   "east":        "��",
   "west":        "��",
   "northup":     "����",
   "southup":     "�ϱ�",
   "eastup":     "����",
   "westup":     "����",
   "northdown":   "����",
   "southdown":   "�ϱ�",
   "eastdown":     "����",
   "westdown":     "����",
   "northeast":   "����",
   "northwest":   "����",
   "southeast":   "����",
   "southwest":   "����",
   "up":        "��",
   "down":        "��",
   "out":        "��",
   "enter":     "��",
   "left":      "��",
   "right":     "��",
]);

void create() { seteuid(getuid()); }

// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg, int silent)
{
   string dest, ridemsg, mout, min, dir;
   object env, obj, ridee;
   mapping exit;

   if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if(!"/adm/daemons/tempd"->valid_move(me)) return 0;

/*
   if( me->over_encumbranced() )
     return notify_fail("��ĸ��ɹ��أ��������á�\n");

   if( me->is_busy() )
     return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

   if( me->query_temp("no_move") )
//     return notify_fail("�㱻��ס�ˣ����ﶯ���ˣ�\n");
// mon 8/11/97. change the fail message since not only dingshen
// can lead to no_move.
     return notify_fail("�����ڲ����ƶ���\n");
*/

   env = environment(me);
   if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

   if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
     if( query_verb()=="go")
        return notify_fail("�������û�г�·��\n");
     else
        return 0;
   }

   dest = exit[arg];

   if( !(obj = load_object(dest)) )
           return notify_fail("��Ҫȥ������û����ͨ��\n");
   if( !(obj = find_object(dest)) )
     return notify_fail("�޷��ƶ���\n");

   if( !env->valid_leave(me, arg) ) return 0;

   if( !undefinedp(default_dirs[arg]) )
     dir = default_dirs[arg];
   else
     dir = arg;

        // snowcat 12/20/97
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
        else  
          ridemsg = "";

        if(ridee && !"/adm/daemons/tempd"->valid_move(ridee)) 
           return notify_fail("��������߶����ˡ�\n");

   if( me->is_fighting() ) {
     mout = ridemsg + "��" + dir + "��Ķ����ˡ�\n";
     min = ridemsg + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
   } else {
     mout = ridemsg+ "��" + dir + "�뿪��\n";
     min = ridemsg+ "���˹�����\n";
   }

   if( !wizardp(me) || !me->query("env/invisibility") )
     message( "vision", me->name() + mout, environment(me), ({me}) );
   if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
     me->remove_all_enemy();
     if( !wizardp(me) || !me->query("env/invisibility") )
        message( "vision", me->name() + min, environment(me), ({me}) );
     me->set_temp("pending", 0);
     // added by snowcat, to fix the bug of recursive move of mutual follow + move to same room 
     if (env != obj)
        all_inventory(env)->follow_me(me, arg);
     if (ridee)
        tell_object (me,"��"+min);
     return 1;
   }

   return 0;
}

void do_flee(object me)
{
   mapping exits;
   string *directions;

   if( !environment(me) || !living(me) ) return;
   exits = environment(me)->query("exits");
   if( !mapp(exits) || !sizeof(exits) ) return;
   directions = keys(exits);
   if (environment(me) && environment(me)->query("no_flee")) return;
   tell_object(me, "�������һ��������ˣ�����\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "���㱻��ס�ˣ��Ӳ�����\n");
          return;
        }

   if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
      tell_object(me, "������ʧ�ܡ�\n");
      return;
    }

   main(me, directions[random(sizeof(directions))], 0);
}

int help(object me)
{
   write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}
