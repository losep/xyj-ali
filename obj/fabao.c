// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// fabao.c

#include <weapon.h>
#include <armor.h>

inherit EQUIP;
inherit F_SAVE;
inherit F_BACKUP;

void create()
{
   seteuid(0);   
   set_name("���Ʒ������", ({ "fabao object", "fabao", "object" }) );
   setup();
}

void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        destruct(this_object());
        return;
    }
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
   string id, series;

   id = query("owner_id");
   series = query("series_no");
   if( !id || !series) return 0;

   return sprintf(DATA_DIR "fabao/%c/%s-%s", id[0], id, series);
}

int save()
{
   if( query("equipped") )   {
     write("������·������ܴ��档\n");
     return 0;
   }
   return ::save();
}

void setup()
{
   ::setup();
}

int query_unique()  { return 1; }
