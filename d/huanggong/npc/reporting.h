// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#define DEBUG 0

void reporting (object who, string reason, int points, string name)
{
  string str = reason+"�õ���"+to_chinese(points)+name+"��\n";

  if (DEBUG)
  {
    object snowcat = find_player ("snowcat");

    if (snowcat && wizardp(snowcat))
      tell_object (snowcat, " �� "+who->query("name")+str);
  }
  else
    MONITOR_D->report_system_object_msg (who, str);
}

