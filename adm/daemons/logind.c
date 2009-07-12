// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
   "��", "��", "��", "��", "��",
});

string *default_name=({"����","����", "����", 
        "ţ", "�ϻ�", "����",
        "��","è��","��","��",
        "����","�ڹ�","��","���",
        "¹","��","Ϭţ"});
string *default_prefix=({"С","��","��","��","��","��","��","��"});

int new_start=0;

private void encoding(string arg, object ob);
private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);

void create() 
{
   seteuid(getuid());
   set("channel_id", "���߾���");
        set("id", "logind");
}

// added by snowcat Mar 11 1998
int total_players()
{
   mapping mud_list;
   mixed *muds;
   string output;
   int loop, size, nb, total=0;

   if( !find_object(DNS_MASTER) )
     return 0;

   mud_list = (mapping)DNS_MASTER->query_muds();
   if(!mud_list)
     return 0;

   muds = keys( mud_list ) - ({ "DEFAULT" });
   for(loop = 0, size = sizeof(muds); loop<size; loop++) {
                if(mud_list[muds[loop]]["MUDLIB"]=="A Journey to the West" &&
        !undefinedp(mud_list[muds[loop]]["USERS"])) {
        sscanf (mud_list[muds[loop]]["USERS"],"%d",nb);
        total += nb; 
     }
        }

   return total;
}

void logon(object ob)
{
    
    cat(BANNER);
    write("            ���μǻ�ӭ�����ã�ʹ�ù�������������룺gb\n");
    write("            ���O�w��z�ӳX�I�ϥΤj���X�����a����J�Gbig5\n");
    write("            Welcome to Xi You Ji! Select GB or BIG5 (gb/big5):");
    input_to( (: encoding :), ob );
}

private void encoding(string arg, object ob)
{
   object *usr;
   int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt;
   string ip_name, ip_number;
    int ii;
   int encode;
   
   if(!arg || arg=="") {
       write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
       input_to( (: encoding :), ob );
       return;
   } else if(arg[0..0]=="g" || arg[0..0]=="G")
       encode=0;
   else if(arg[0..0]=="b" || arg[0..0]=="B")
       encode=1;
   else {
       write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
       input_to( (: encoding :), ob );
       return;
   }
   
   if(encode==0)
       write("\nUse GB encoded Chinese.\n");
   else
       write("\nUse BIG5 encoded Chinese.\n");
   
   ob->set_encoding(encode);

   ip_name = query_ip_name(ob);
   ip_number = query_ip_number(ob);

   if(new_start==0) { //only check for once.
     new_start++;
    }

/*
   if ("/adm/daemons/band"->create_char_banned(query_ip_number(ob)) == 1) {
        write("�Բ�����Ŀǰ���ܴ��������\n");
        destruct(ob);
//     log_file( "ALLCONT", sprintf("kicked out, create char banned\n"));
        return;
       }
*/

//log all connections.
   log_file( "ALLCONT", sprintf("IP_name--number  %s--%s (%s)\n", ip_name,
                                ip_number, ctime(time()) ) );

// snowcat dec 10 1997
// try strict ban here...weiqi.

   if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
        write("���ĵ�ַ�ڱ� MUD ֮���������ƻ��ˡ�\n");
        destruct(ob);
     log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
        return;
   }

   
   // try not accept "name" as IP

   if (!ip_name) {
     destruct(ob);
     log_file( "ALLCONT", sprintf("kicked out, No IP\n"));
     return;
   }

   for(ii=0; ii<sizeof(ip_number); ii++) {
     if( (ip_number[ii] != '.')&&(ip_number[ii]>'9') ){
        destruct(ob);
        log_file( "ALLCONT", sprintf("kicked out, Non_number\n"));
        return;
     }
   }
   
/*
   if( ip_name != ip_number )  {
         destruct(ob);
     log_file( "ALLCONT", sprintf("kicked out, number != name\n"));
         return;
   }
*/

   cat(WELCOME);
   UPTIME_CMD->report();

   usr = users();
   wiz_cnt = 0;
   ppl_cnt = 0;
   login_cnt = 0;
   for(i=0; i<sizeof(usr); i++) {
     if( !environment(usr[i]) ) login_cnt++;
     else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
     else ppl_cnt++;
   }
   // snowcat Mar 11 1998
   ttl_cnt = total_players();
   if (ttl_cnt == 0) 
     printf("Ŀǰ"); // info not available
   else 
     printf("Ŀǰ����%dλ��������ϡ���վ", ttl_cnt );
   printf("����%dλ��ʦ��%dλ��ң��Լ�%dλ�ڳ������ߡ�\n\n",
     wiz_cnt, ppl_cnt, login_cnt );

// mon 4/19/98
// reduce number of pending login users.
#ifdef MAX_USERS
   if(sizeof(usr)>(MAX_USERS+10)) {
       write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ�������������\n");
       destruct(ob);
       return;
   }
#endif


   if (ob) ob->set_temp("id_count",0);
   //mon 10/15/97 to prevent flooding illegal ID after login.

   write("\n����Ӣ�����֣�");
   input_to( (: get_id :), ob);
}

private void get_id(string arg, object ob)
{
   object ppl;
        int id_count;

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
   if(id_count>6) {
     destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
     return;
        }

   arg = lower_case(arg);
   if( !check_legal_id(arg)) {
     write("����Ӣ�����֣�");
     input_to("get_id", ob);
     return;
   }

#ifdef MAX_USERS
   if( (string)SECURITY_D->get_status(arg)=="(player)"
   && sizeof(users()) >= MAX_USERS ) {
     ppl = find_body(arg);
     // Only allow reconnect an interactive player when MAX_USERS exceeded.
     if( !ppl || !interactive(ppl) ) {
       write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ�������������\n");
       destruct(ob);
       return;
     }
   }
#endif

   if( wiz_level(arg) < wiz_lock_level ) {
     write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
        + " ���ϵ��˲������ߡ�\n");
     destruct(ob);
     return;
   }
   
   if( (string)ob->set("id", arg) != arg ) {
     write("Failed setting user name.\n");
     destruct(ob);
     return;
   }

   if( arg=="guest" ) {
     // If guest, let them create the character.
     confirm_id("Yes", ob);
     return;
   } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
     if( ob->restore() ) {
        write("���������룺");
        input_to("get_passwd", 1, ob);
        return;
     }
     write("�������ﴢ�浵����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
     destruct(ob);
     return;
   }

// snowcat dec 10 1997
/*
   if ("/adm/daemons/band"->create_char_banned(query_ip_number(ob)) == 1 ||
       "/adm/daemons/band"->is_banned(query_ip_number(ob)) == 1) {
           write("�Բ�����Ŀǰ���ܴ��������\n");
        destruct(ob);
     log_file( "ALLCONT", sprintf("kicked out, create char banned\n"));
        return;
       }
*/

   write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
   input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
   string my_pass;
   object user;

   write("\n");
   my_pass = ob->query("password");
   if( crypt(pass, my_pass) != my_pass ||
    !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
     write("�������");
     write("���������ߣ�������ȷ���������ȡһ���µ�Ӣ�����֡�\n");
     destruct(ob);
     return;
   }

   // Check if we are already playing.
   user = find_body(ob->query("id"));
   if (user) {
       
     if( user->query_temp("netdead") ) {
        reconnect(ob, user);
        return;
     }
     write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
     input_to("confirm_relogin", ob, user);
     return;
   }

   if( objectp(user = make_body(ob)) ) {
     if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );

        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("�������´���������\n");
   confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
   object old_link;

   if( yn=="" ) {
     write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
     input_to("confirm_relogin", ob, user);
     return;
   }   

   if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
       // user may be destructed during the process.
       // so I put in this check. mon 4/15/98
     write("�ðɣ���ӭ�´�������\n");
     destruct(ob);
     return;
   } else {
     tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
        + " )����ȡ���������Ƶ����\n");
     log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
     user->query("name"), user->query("id"),
        query_ip_number(ob), ctime(time()) ) );
   }

   // Kick out tho old player.
   old_link = user->query_temp("link_ob");
   if( old_link ) {

           // 5/11/98 mon
           user->set_encoding(ob->query_encoding());

     exec(old_link, user);
     destruct(old_link);
   }

   reconnect(ob, user);   
}

private void confirm_id(string yn, object ob)
{
   if( yn=="" ) {
     write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
     input_to("confirm_id", ob);
     return;
   }   

   if( yn[0]!='y' && yn[0]!='Y' ) {
     write("�ðɣ���ô��������������Ӣ�����֣�");
     input_to("get_id", ob);
     return;
   }

   write( @TEXT

�������Լ����������������ҪȡһЩ���Ż�����������������ŵ�
���֡�������ֽ������������������󽫲����ٸ��ģ���������ء�
(��������֮�⣬�� mud �����ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)

TEXT
   );
   write("�����������֣�");
   ob->set_temp("get_name",0);
   input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
   if( !check_legal_name(arg) ) {
            ob->add_temp("get_name",1);
       if(ob->query_temp("get_name")>2) {
           // the user can't input proper chinese name.
           // assign one for him/her.    mon 4/19/98

     arg=default_prefix[random(sizeof(default_prefix))]+
         default_name[random(sizeof(default_name))];

     write("��Ϊ�㲻�������ʵ����������֣�ϵͳָ���������Ϊ��"+
        arg+"\n");
     write("���ڽ�����Ϸ������ʦ�����޸ġ�\n");

       } else {
     write("�����������֣�");
     input_to("get_name", ob);
     return;
       }
   }

   printf("%O\n", ob);
   ob->set("name", arg);
   write("���趨�������룺");
   input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
   write("\n");
   if( strlen(pass)<5 ) {
     write("����ĳ�������Ҫ�����Ԫ���������������룺");
     input_to("new_password", 1, ob);
     return;
   }
   ob->set("password", crypt(pass,0) );
   write("��������һ���������룬��ȷ����û�Ǵ�");
   input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
   string old_pass;
   write("\n");
   old_pass = ob->query("password");
   if( crypt(pass, old_pass)!=old_pass ) {
     write("��������������벢��һ�����������趨һ�����룺");
     input_to("new_password", 1, ob);
     return;
   }

   write("���ĵ����ʼ���ַ��");
   input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
   object user;

   ob->set("email", email);

   // If you want do race stuff, ask player to choose one here, then you can
   // set the user's body after the question is answered. The following are
   // options for player's body, so we clone a body here.
   ob->set("body", USER_OB);
   if( !objectp(user = make_body(ob)) )
     return;

   write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
   input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
   if( gender=="" ) {
     write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
     input_to("get_gender", ob, user);
     return;
   }

   if( gender[0]=='m' || gender[0]=='M' )
     user->set("gender", "����");
   else if( gender[0]=='f' || gender[0]=='F' )
     user->set("gender", "Ů��" );
   else {
     write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
     input_to("get_gender", ob, user);
     return;
   }
   
        confirm_gift("n",ob,user);
}

object make_body(object ob)
{
   string err;
   object user;
   int n;

        if(!ob->query("body")) {
     return 0;
        }
   user = new(ob->query("body"));
   if(!user) {
     write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
     write(err+"\n");
     return 0;
   }
   seteuid(ob->query("id"));
   export_uid(user);
   export_uid(ob);
   seteuid(getuid());
   user->set("id", ob->query("id"));
   user->set_name( ob->query("name"), ({ ob->query("id")}) );
   return user;
}

private void confirm_gift(string yn, object ob, object user)
{
        int n;

   if(!ob || !user) {
            if(user) {
         destruct(user);
         return;
       }
            if(ob) destruct(ob);
       return;
        }

        if (yn!="") {
          if (yn[0]=='y' || yn[0]=='Y') {
       CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
       user->set("title", "��ͨ����");
       user->set("birthday", time() );
       user->set("potential", 99);
       user->set("food", user->max_food_capacity());
       user->set("water", user->max_water_capacity());
       user->set("channels", ({ "chat","rumor","xyj","sldh" }) );
       log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
     query_ip_number(ob), ctime(time()) ) );

       return enter_world(ob, user);
            
          } else if (yn[0]=='q' || yn[0]=='Q') {
            destruct(user);
            destruct(ob);
            return;
          }
        }
        
        user->set("kar",0);
   while(user->query("kar")<10 || user->query("kar")>30){
   user->set("str", 10 + random(21));
   user->set("cps", 10 + random(21));
   user->set("int", 10 + random(21));
   user->set("cor", 10 + random(21));
   user->set("con", 10 + random(21));
   user->set("spi", 10 + random(21));
   user->set("per", 10 + random(21));
        n = user->query("str") + user->query("cps") + user->query("int");
        n = n + user->query("cor") +  user->query("con") +  user->query("spi") + user->query("per");
        if(n>168)
           user->set("kar",0);
           else
           user->set("kar",168-n);   
        }

        write("\n");
        printf(" ������[%s]  ��ʶ��[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n"
               " ������[%s]  ��ò��[%s]  ���ǣ�[%s]  ��Ե��[%s]\n\n",
               dis_attr(user->query_str()),
               dis_attr(user->query_cor()),
               dis_attr(user->query_int()),
               dis_attr(user->query_spi()),
               dis_attr(user->query_cps()),
               dis_attr(user->query_per()),
               dis_attr(user->query_con()),
               dis_attr(user->query_kar()));
        write("��ͬ�������츳��ֵ��[n|y|q]");
        input_to("confirm_gift",ob,user);
        return;
}


string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

varargs void enter_world(object ob, object user, int silent)
{
   object cloth, room, mbx;
   string startroom="";
   int num;

        reset_eval_cost();

   user->set_temp("link_ob", ob);
   ob->set_temp("body_ob", user);

   // 5/11/98 mon
   user->set_encoding(ob->query_encoding());

   exec(user, ob);

/*
    // default wiz
   if (sizeof(SECURITY_D->query_wizlist()) == 0) {
      SECURITY_D->add_wiz(user->query("id"),"(admin)", "");
    }
*/

   write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
   user->setup();

   // In case of new player, we save them here right aftre setup 
   // compeleted.
   user->save();
   ob->save();

/*.   if (user->query("gender")=="Ů��")
        {
          cloth = new("/obj/loginload/skirt.c");
     cloth->move(user);
     cloth->wear();
          cloth = new("/obj/loginload/shoes.c");
     cloth->move(user);
     cloth->wear();
        }
        else
        cloth = new("/obj/loginload/linen.c");
   cloth->move(user);
   cloth->wear();
*/
        if( !silent ) {
           if(file_size(MOTD)>0)
                  user->start_more(read_file(MOTD),1);
     if( user->is_ghost() )
        startroom = DEATH_ROOM;
     else if( strlen(startroom = user->query("startroom"))<2 )
        startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {
       startroom = START_ROOM;
                  user->set("startroom",startroom);
                }
                //added by mon 10/27/97

     // the following 7 lines are aded by snowcat dec 10 1997
     if (("/adm/daemons/band"
         ->create_char_banned(query_ip_number(user)) == 1 ||
             "/adm/daemons/band"->is_banned(query_ip_number(user))
         == 1) && !wizardp(user)) {
        user->move("/d/wiz/guest");
        log_file( "ALLCONT", sprintf("from banned site\n"));
     }
     else if( !catch(load_object(startroom)) )
        user->move(startroom);
     else {
        user->move(START_ROOM);
        startroom = START_ROOM;
        user->set("startroom", START_ROOM);
     }
     tell_room(startroom, user->query("name") + "���߽���������硣\n",
        ({user}));
     
     mbx=ob->query_temp("mbox_ob");
     if (!mbx) {
       mbx=new(MAILBOX_OB);
       mbx->set_owner(ob->query("id"));
                }
     num=mbx->query_new_mail();
     if( num>0 ) {
             write( GRN + "\n˳��������㣺����"
         +chinese_number(num)+
         "���ţ��뵽�ϳǿ�ջ��һ�ˣ�����\n\n" + NOR);
     }
     destruct(mbx);
   }

   CHANNEL_D->do_channel( this_object(), "sys",
     sprintf("%s��%s���߽��롣", user->name()+"("+capitalize(user->query("id")) + ")", query_ip_name(user)) );
   UPDATE_D->check_user(user);

      {object caishen;
   if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
     caishen->check_one(user);
        }
      }
}

varargs void reconnect(object ob, object user, int silent)
{
   user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
  
   // 5/11/98 mon
   user->set_encoding(ob->query_encoding());

   exec(user, ob);

   user->reconnect();
   if( !silent && !user->query("env/invisibility")) {
     tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
     ({user}));
   }
   CHANNEL_D->do_channel( this_object(), "sys",
     sprintf("%s��%s�������߽��롣", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
   UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
   int i;
   string *legalid;

   i = strlen(id);
   
   if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
     write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
     return 0;
   }
   while(i--)
     if( id[i]<'a' || id[i]>'z' ) {
        write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
        return 0;
     }


   legalid = explode(read_file(BANNED_ID), "\n");
   for(i=0; i<sizeof(legalid); i++)   {
      if( id == legalid[i] )   {
       write("�Բ����������ֻ���������˵����š�\n");
       return 0;
       }
   }
   return 1;
}

int check_legal_name(string name)
{
   int i;

   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
     write("�Բ�������������ֱ����� 1 �� 6 �������֡�\n");
     return 0;
   }
   while(i--) {
     if( name[i]<=' ' ) {
        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
        return 0;
     }
     if( i%2==0 && !is_chinese(name[i..<0]) ) {
        write("�Բ��������á����ġ�ȡ���֡�\n");
        return 0;
     }
   }
   if( member_array(name, banned_name)!=-1 ) {
     write("�Բ����������ֻ���������˵����š�\n");
     return 0;
   }

   return 1;
}

object find_body(string name)
{
   object ob, *body;

   if( objectp(ob = find_player(name)) )
     return ob;
   body = children(USER_OB);
   for(int i=0; i<sizeof(body); i++) {
          ob=body[i];
     if( clonep(ob) && getuid(ob) == name 
            && ob->query("max_gin")>0 ) return ob;
       //check max_gin to avoid damaged user object.
        }

   return 0;
}
/*
object find_body(string name)
{
   object ob, *body;

   if( objectp(ob = find_player(name)) )
     return ob;
   body = children(USER_OB);
   for(int i=0; i<sizeof(body); i++)
     if( clonep(body[i])
     &&   getuid(body[i]) == name ) return body[i];

   return 0;
}
*/
int set_wizlock(int level)
{
   if( wiz_level(this_player(1)) <= level )
     return 0;
   if( geteuid(previous_object()) != ROOT_UID )
     return 0;
   wiz_lock_level = level;
   return 1;
}
