// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// wiz.c

string wizhood(mixed ob)
{
   return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
   return SECURITY_D->get_wiz_level(ob);
}

/*void disable_commands( )
{
   if( this_player()->query("id") != "tool" )
      efun::disable_commands();
}
*/
