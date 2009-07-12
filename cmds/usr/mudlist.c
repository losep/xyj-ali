// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;


int main(object me, string arg)
{
   mapping mud_list;
   mapping mud_svc;
   mixed *muds;
   string output, output1, output2="";
   int loop, size, pplno, total;
   int show_all=0;

   if( !find_object(DNS_MASTER) )
     return notify_fail("��·���鲢û�б����룬���Ƚ���·�������롣\n");

   //   Obtain mapping containing mud data
   mud_list = (mapping)DNS_MASTER->query_muds();

   // so we recognise ourselves as a DNS mud
   mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

   if(!mud_list)
     return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

   //   Get list of all mud names within name server
   muds = keys( mud_list ) - ({ "DEFAULT" });

   //   Place mudlist into alphabetical format
   muds = sort_array(muds, 1);

   //    If mudname provided, search server's database for a match
   //   and display its cooresponding address
   if(arg && arg != "") {
           if(arg=="-a") 
        show_all=1;
           else {
     arg = htonn(arg);

     if(!mapp( mud_list[arg] )) {
        write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
        return 1;
     }
     printf("�й� %s ����Ѷ��\n%O\n", arg, mud_list[arg]);
     return 1;
           }
   }

   output = "\n\n"+
"   �ͣ�������              ������·λַ   ����      ����ʱ��     �������\n"+
"��������������������������������������������������������������������������\n";

   total = 0;
   //   Loop through mud list and store one by one
   for(loop = 0, size = sizeof(muds); loop<size; loop++) {
           string mudname, mudtime;
     
                mudname=undefinedp(mud_list[muds[loop]]["MUDNAME"])?
             upper_case(muds[loop]):
        mud_list[muds[loop]]["MUDNAME"] +
        "("+upper_case(muds[loop])+")"; 
                if(strlen(mudname)>25) mudname=mudname[0..24];
     mudtime=mud_list[muds[loop]]["TIME"];
           
         output1 = sprintf("%-25s %-16s%-5s %15s %5s\n", 
        mudname,
        mud_list[muds[loop]]["HOSTADDRESS"],
        mud_list[muds[loop]]["PORT"],
//        undefinedp(mud_svc[muds[loop]]) ? "  " : "��",
             undefinedp(mud_list[muds[loop]]["TIME"])?
        "                ":
        mudtime[0..15],
        undefinedp(mud_list[muds[loop]]["USERS"]) ?
        "":""+mud_list[muds[loop]]["USERS"] );
         if (undefinedp(mud_list[muds[loop]]["USERS"]))
        pplno = 0;
         else
        sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);
         if ((show_all==1) || 
        (mud_list[muds[loop]]["MUDLIB"]==
         "A Journey to the West") )
        total += pplno;
         if(mud_list[muds[loop]]["MUDLIB"]==
           "A Journey to the West")
           output2=output1+output2; //add xyj mud at front.
                    else if(show_all==1)
           output2=output2+output1; //add non-xyj mud at end.
        }
   output+=output2;
   output+=
"��������������������������������������������������������������������������\n";
   output+="���� " + sprintf("%d", total) + " λʹ���������С�\n";

   //   Display dumped mudlist output through user's more pager
   this_player()->start_more( output );

   return 1;
}

int help()
{
        write(@HELP

ָ���ʽ��mudlist               �г������е����μ�վ��
          mudlist -a            �г������е����Уͣ���
          mudlist <Mud ����>    �г�ָ���ͣ������Ϣ

HELP
   );
   return 1;
}

