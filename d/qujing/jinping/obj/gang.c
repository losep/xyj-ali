// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
  set_name("��Ƹ�", ({"jindeng gang", "gang"}));
  set_weight(5000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��װ���ֺ����͵Ĵ�ף���������ʮ�Ÿ������\n");
    set("unit", "��");
  }
}

void init ()
{
  remove_call_out ("burning");
  call_out ("burning",random(30)+1);
}

void burning ()
{
  object where = environment(this_object());
  string *msgs = ({
    "��Ƹ���ƻ�һ����\n",
    "��Ƹ���ĵƻ𱻷�һ��������һ�¡�\n",
    "�ƻ�����һ����\n",
    "�ƻ��ڸ�������һ�¡�\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]); 
  remove_call_out ("burning");
  call_out ("burning",random(60)+1);
}
