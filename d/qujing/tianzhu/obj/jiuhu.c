// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("����Ͼƺ�", ({"jiu hu", "jiuhu", "hu"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ������װ����ϾƵľƺ���\n");
     set("unit", "��");
     set("value", 200);
     set("max_liquid", 15);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "����Ͼ�",
        "remaining": 15,
        "drunk_supply": 12,
      ]));
}

